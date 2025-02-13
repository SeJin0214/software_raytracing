/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:13 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 20:16:30 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "world.h"
# include "canvas.h"
# include "matrix.h"
# include "ray.h"
# include "hit_record.h"

void		render(t_world *world, t_canvas *canvas);
int			load_pixel_color(t_world *world, const t_ray ray);
void		put_color_in_image_frame(t_canvas *canvas, \
const int x, const int y, const int color);
int			convert_colors(t_ivector3 colors);
t_ivector3	add_color(const t_ivector3 color0, const t_ivector3 color1);

bool		is_shadowed_surface(t_world *world, \
const t_vector3 surface, void *object);
t_ivector3	reflect_light(const t_ivector3 ligth_resource_color, \
const t_ivector3 surface_color);

bool		is_collision(const t_hit_record record);
t_matrix3x3	get_rotation_matrix(const float x, const float y, const float z);
float		get_radian(const float degree);

#endif