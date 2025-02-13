/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 20:19:33 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "float.h"
#include "libft.h"
#include "solid_shape.h"

#define PI 3.141592f

void	render(t_world *world, t_canvas *canvas)
{
	size_t	y;
	size_t	x;
	float	y_angle_to_convert;
	float	x_angle_to_convert;
	int		color;

	y = 0;
	while (y < canvas->screen.height)
	{
		y_angle_to_convert = lerp(world->camera.y_theta, 
		-world->camera.y_theta, (float)y / canvas->screen.height);
		x = 0;
		while (x < canvas->screen.width)
		{
			t_vector3 y_axis_vec = multiply_vector3(world->camera.local_basis.row[Y], tanf(get_radian(y_angle_to_convert)));
			x_angle_to_convert = lerp(-world->camera.x_theta, world->camera.x_theta, (float)x / canvas->screen.width);
			
			t_vector3 x_axis_vec = multiply_vector3(world->camera.local_basis.row[X], tanf(get_radian(x_angle_to_convert)));
			t_vector3 direction = normalize_vector3(add_vector3(world->camera.local_basis.row[Z], add_vector3(y_axis_vec, x_axis_vec)));
			
			t_ray ray = get_ray(world->camera.coordinates, direction);
			color = load_pixel_color(world, ray);
			put_color_in_image_frame(canvas, (int)x, (int)y, color);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(canvas->xvar, canvas->win, \
			canvas->img, 0, 0);
}

int	load_pixel_color(t_world *world, const t_ray ray)
{
	t_ivector3		result;
	size_t			i;
	t_hit_record	hit_record;
	t_solid_shape	**shape;

	i = 0;
	hit_record = get_hit_record();
	while (i < world->solid_shapes.count)
	{
		shape = world->solid_shapes.get_element_or_null(&world->solid_shapes, i);
		(*shape)->is_hit(ray, *shape, &hit_record);
		++i;
	}
	if (is_collision(hit_record))
	{
		// shadow
		t_vector3 surface_to_diffuse_light = subtract_vector3(world->light.coordinates, hit_record.point);
		t_vector3 direction_to_light = normalize_vector3(surface_to_diffuse_light);
		float light_intensity = fmax(dot_product3x3(direction_to_light, hit_record.normal), 0.0f);
		t_ivector3 diffuse_source_color = multiply_ivector3(world->light.colors, light_intensity);
		t_ivector3 diffuse_color = reflect_light(diffuse_source_color, hit_record.color);
		t_ivector3 ambient_color = reflect_light(world->ambient_light.colors, hit_record.color);
		float ratio_in_range = world->ambient_light.ratio_in_range;
		t_ivector3 ambient = get_ivector3(ratio_in_range * 255, ratio_in_range * 255, ratio_in_range * 255);
		ambient_color = reflect_light(ambient, ambient_color);
		result = add_color(diffuse_color, ambient_color);
		if (is_shadowed_surface(world, hit_record.point, hit_record.object))
		{
			result.x /= 2;
			result.y /= 2;
			result.z /= 2;
		}
		return (convert_colors(result));
	}
	return convert_colors((t_ivector3){{0, 0, 0}});
}

bool	is_collision(const t_hit_record record)
{
	return (FLT_MAX != record.t);
}

void	put_color_in_image_frame(t_canvas *canvas, const int x, \
const int y, const int color)
{
	int			*image_frame_buffer;
	const int	offset = canvas->screen.width * y + x;

	image_frame_buffer = (int *)canvas->img->data;
	if (x >= 0 && y >= 0 && y < (int)canvas->screen.height \
			&& x < (int)canvas->screen.width)
	{
		*(image_frame_buffer + offset) = color;
	}
}

int	convert_colors(t_ivector3 colors)
{
	return ((colors.x << 16) + (colors.y << 8) + colors.z);
}







// 밑은 다른 폴더로 이동
t_matrix3x3	get_rotation_matrix(const float x, const float y, const float z)
{
	const t_vector3	radian = {{ get_radian(x), get_radian(y), get_radian(z) }};
	const t_matrix3x3 x_matrix = {{
		{1, 0, 0},
		{0, cosf(radian.x), sinf(radian.x)},
		{0, -sinf(radian.x), cosf(radian.x)}
	}};
	const t_matrix3x3 y_matrix = {{
		{cosf(radian.y), 0, -sinf(radian.y)},
		{0, 1, 0},
		{sinf(radian.y), 0, cosf(radian.y)}
	}};
	const t_matrix3x3 z_matrix = {{
		{cosf(radian.z), sinf(radian.z), 0},
		{-sinf(radian.z), cosf(radian.z), 0},
		{0, 0, 1},
	}};
	
	return (transpose(multiply_matrix3x3(x_matrix, \
	multiply_matrix3x3(z_matrix, y_matrix))));
}

t_ivector3	add_color(const t_ivector3 color0, const t_ivector3 color1)
{
	t_ivector3	result;

	result.x = get_min(color0.x + color1.x , 255);
	result.y = get_min(color0.y + color1.y , 255);
	result.z = get_min(color0.z + color1.z , 255);
	return (result);
}

// math
float	get_radian(const float degree)
{
	return (degree * PI / 180);
}