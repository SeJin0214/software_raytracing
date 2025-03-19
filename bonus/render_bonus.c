/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/03/19 21:36:51 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render_bonus.h"
#include "float_bonus.h"
#include "shadow_bonus.h"

extern inline t_ivector3		trace_reflection_color(const t_world *world, \
const t_ray ray, const t_hit_record hit_record, size_t depth);

extern inline t_ivector3		load_hit_point_color(const t_world *world, \
const t_ray ray);

extern inline t_hit_record	load_hit_record(const t_world *world, \
const t_ray ray);

void	*render(void *obj)
{
	t_renderer	*renderer;
	size_t		y;
	size_t		x;
	int			color;

	renderer = obj;
	y = renderer->start_y - 1;
	while (++y < renderer->last_y)
	{
		renderer->y_angle_to_convert = lerp(renderer->world->camera.y_theta, \
		-renderer->world->camera.y_theta, \
		(float)y / renderer->canvas->screen.height);
		x = renderer->start_x - 1;
		while (++x < renderer->last_x)
		{
			renderer->x_angle_to_convert = lerp(-renderer->world->\
			camera.x_theta, renderer->world->camera.x_theta, \
			(float)x / renderer->canvas->screen.width);
			color = convert_colors(load_hit_point_color(renderer->world, \
			get_ray_mappied_to_pixel(renderer->world->camera, \
			renderer->x_angle_to_convert, renderer->y_angle_to_convert)));
			put_color_in_image_frame(renderer, (int)x, (int)y, color);
		}
	}
	return (0);
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

t_ivector3	compute_reflection_lighting_recursive(const t_world *world, \
const t_ray ray, const t_hit_record hit_record, size_t depth)
{
	size_t			i;
	t_light			*light;
	t_ivector3		total_color;
	t_ivector3		diffuse_color;
	t_ivector3		specular_color;

	total_color = trace_reflection_color(world, ray, hit_record, depth);
	total_color = add_color(total_color, \
	load_ambient_color(world->ambient_light, hit_record));
	i = 0;
	while (i < world->lights.count)
	{
		light = get_element_or_null_in_list(\
		(t_array_list *)(&world->lights), i);
		++i;
		if (is_shadowed_surface(world, *light, \
		hit_record.point, hit_record.object))
			continue ;
		diffuse_color = load_diffuse_color(*light, hit_record);
		specular_color = load_specular_color(ray.origin, *light, hit_record);
		total_color = add_color(total_color, specular_color);
		total_color = add_color(total_color, diffuse_color);
	}
	return (total_color);
}

bool	is_collision(const t_hit_record record)
{
	return (FLT_MAX != record.t);
}

void	put_color_in_image_frame(t_renderer *renderer, const int x, \
const int y, const int color)
{
	int			*image_frame_buffer;
	const int	offset = renderer->canvas->screen.width * y + x;

	image_frame_buffer = (int *)renderer->canvas->img->data;
	if (x >= 0 && y >= 0 && y < (int)renderer->canvas->screen.height \
			&& x < (int)renderer->canvas->screen.width)
	{
		pthread_mutex_lock(&renderer->canvas_lock);
		*(image_frame_buffer + offset) = color;
		pthread_mutex_unlock(&renderer->canvas_lock);
	}
}
