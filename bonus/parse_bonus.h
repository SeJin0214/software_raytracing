/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:20:41 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 16:48:06 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H
# include "world_bonus.h"

/* parse.c */
bool	try_parse(int argc, char **argv, t_world *out_world, t_canvas *canvas);
bool	is_valid_file(char *filename);
bool	try_parse_file(char *filename, t_world *out_world, t_canvas *canvas);
bool	try_parse_attributes(char **attributes, \
t_world *out_world, t_canvas *canvas);

/* parse_solid_shape.c */
bool	try_add_sphere_to_world(char **attributes, t_world *world);
bool	try_add_plane_to_world(char **attributes, t_world *world);
bool	is_invalid_value_in_plane(char **attributes, t_plane *plane);
bool	try_add_cylinder_to_world(char **attributes, t_world *world);
bool	is_invalid_value_in_cylinder(char **attributes, t_cylinder *cylinder);

/* parse_util.c */
bool	try_parse_vector3(char *attribute, t_vector3 *out_result);
bool	try_parse_color(char *attribute, t_ivector3 *out_result);
bool	is_invalid_normalized_vector3(t_vector3 vector);
bool	is_invalid_ratio_in_range(float ratio_in_range);
bool	is_invalid_colors(t_ivector3 colors);

#endif