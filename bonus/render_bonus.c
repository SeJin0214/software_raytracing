/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 04:53:34 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render_bonus.h"
#include "float_bonus.h"
#include "libft.h"
#include "solid_shape_bonus.h"
#include "ft_math.h"
#include "shadow_bonus.h"

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

extern inline int	load_pixel_color(t_world *world, const t_ray ray);

t_ivector3	load_pixel_color_by_light(t_world *world, \
const t_hit_record hit_record)
{
	size_t			i;
	t_light			*light;
	t_ivector3		total_color;
	t_ivector3		diffuse_color;
	t_ivector3		specular_color;

	i = 0;
	total_color = load_ambient_color(world->ambient_light, hit_record);
	while (i < world->lights.count)
	{
		light = get_element_or_null_in_list(&world->lights, i);
		++i;
		if (is_shadowed_surface(world, *light, \
		hit_record.point, hit_record.object))
		{
			continue ;
		}
		diffuse_color = load_diffuse_color(*light, hit_record);
		specular_color = load_specular_color(world->camera, *light, hit_record);
		total_color = add_color(total_color, specular_color);
		total_color = add_color(total_color, diffuse_color);
	}
	return (total_color);
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
