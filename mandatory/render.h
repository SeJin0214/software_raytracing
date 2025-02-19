/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:13 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/20 05:00:28 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "world.h"
# include "canvas.h"
# include "matrix.h"
# include "ray.h"
# include "hit_record.h"
# include "libft.h"
# include "light.h"
# include "ft_math.h"
# define PI 3.141592f

/* render.c */
void		render(t_world *world, t_canvas *canvas);
int			load_pixel_color(t_world *world, const t_ray ray);
void		put_color_in_image_frame(t_canvas *canvas, \
const int x, const int y, const int color);
t_ray		get_ray_mappied_to_pixel(const t_camera camera, \
const float x_angle_to_convert, const float y_angle_to_convert);
bool		is_collision(const t_hit_record record);

/* render_util.c */
inline int	convert_colors(t_ivector3 colors)
{
	return ((colors.x << 16) + (colors.y << 8) + colors.z);
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