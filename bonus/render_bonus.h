/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:13 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 04:45:08 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H
# include "world_bonus.h"
# include "canvas_bonus.h"
# include "matrix.h"
# include "ray_bonus.h"
# include "hit_record_bonus.h"
# include "libft.h"
# include "light_bonus.h"
# include "ft_math.h"
# define PI 3.141592f

/* render.c */
void		render(t_world *world, t_canvas *canvas);
bool		is_collision(const t_hit_record record);
t_ivector3	load_pixel_color_by_light(t_world *world, \
const t_hit_record hit_record);
void		put_color_in_image_frame(t_canvas *canvas, \
const int x, const int y, const int color);
t_ray		get_ray_mappied_to_pixel(const t_camera camera, \
const float x_angle_to_convert, const float y_angle_to_convert);

inline int	convert_colors(t_ivector3 colors)
{
	return ((colors.x << 16) + (colors.y << 8) + colors.z);
}

inline int	load_pixel_color(t_world *world, const t_ray ray)
{
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
	{
		return (convert_colors(get_ivector3(0, 0, 0)));
	}
	return (convert_colors(load_pixel_color_by_light(world, hit_record)));
}

inline t_ivector3	add_color(const t_ivector3 color0, const t_ivector3 color1)
{
	t_ivector3	result;

	result.x = get_min(color0.x + color1.x, 255);
	result.y = get_min(color0.y + color1.y, 255);
	result.z = get_min(color0.z + color1.z, 255);
	return (result);
}

#endif