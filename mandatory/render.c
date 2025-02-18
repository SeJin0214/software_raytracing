/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 14:49:20 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "float.h"
#include "libft.h"
#include "solid_shape.h"
#include "light.h"

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
		y_angle_to_convert = lerp(world->camera.y_theta, \
		-world->camera.y_theta, (float)y / canvas->screen.height);
		x = 0;
		while (x < canvas->screen.width)
		{
			x_angle_to_convert = lerp(-world->camera.x_theta, \
			world->camera.x_theta, (float)x / canvas->screen.width);
			color = load_pixel_color(world, get_ray_mappied_to_pixel(\
			world->camera, x_angle_to_convert, y_angle_to_convert));
			put_color_in_image_frame(canvas, (int)x, (int)y, color);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(canvas->xvar, canvas->win, \
			canvas->img, 0, 0);
}

t_ray	get_ray_mappied_to_pixel(const t_camera camera, \
const float x_angle_to_convert, const float y_angle_to_convert)
{
	t_vector3	y_axis_vec;
	t_vector3	x_axis_vec;
	t_vector3	direction;
	t_ray		ray;

	y_axis_vec = multiply_vector3(camera.local_basis.row[Y], \
	tanf(get_radian(y_angle_to_convert)));
	x_axis_vec = multiply_vector3(camera.local_basis.row[X], \
	tanf(get_radian(x_angle_to_convert)));
	direction = normalize_vector3(add_vector3(camera.local_basis.row[Z], \
	add_vector3(y_axis_vec, x_axis_vec)));
	ray = get_ray(camera.coordinates, direction);
	return (ray);
}

int	load_pixel_color(t_world *world, const t_ray ray)
{
	t_ivector3		color;
	size_t			i;
	t_hit_record	hit_record;
	t_solid_shape	**shape;

	i = 0;
	hit_record = get_hit_record();
	while (i < world->solid_shapes.count)
	{
		shape = get_element_or_null_in_list(&world->solid_shapes, i);
		(*shape)->is_hit(ray, *shape, &hit_record);
		++i;
	}
	if (is_collision(hit_record) == false)
		return (convert_colors(get_ivector3(0, 0, 0)));
	color = add_color(load_diffuse_color(world->light, hit_record), \
	load_ambient_color(world->ambient_light, hit_record));
	if (is_shadowed_surface(world, hit_record.point, hit_record.object))
	{
		color.x /= 2;
		color.y /= 2;
		color.z /= 2;
	}
	return (convert_colors(color));
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
