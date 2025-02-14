/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:26:13 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 13:18:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "world.h"
# include "canvas.h"
# include "matrix.h"
# include "ray.h"
# include "hit_record.h"
# define PI 3.141592f

/* render.c */
void		render(t_world *world, t_canvas *canvas);
int			load_pixel_color(t_world *world, const t_ray ray);
void		put_color_in_image_frame(t_canvas *canvas, \
const int x, const int y, const int color);
t_ray		get_ray_mappied_to_pixel(const t_camera camera, \
const float x_angle_to_convert, const float y_angle_to_convert);
bool		is_collision(const t_hit_record record);

/* light.c */
t_ivector3	load_diffuse_color(const t_light light, \
const t_hit_record hit_record);
t_ivector3	load_ambient_color(const t_ambient_light ambient, \
const t_hit_record hit_record);

/* shadow.c */
bool		is_shadowed_surface(t_world *world, \
const t_vector3 surface, void *object);
t_ivector3	reflect_light(const t_ivector3 ligth_resource_color, \
const t_ivector3 surface_color);

/* render_util.c */
int			convert_colors(t_ivector3 colors);
t_ivector3	add_color(const t_ivector3 color0, const t_ivector3 color1);
float		get_radian(const float degree);

#endif