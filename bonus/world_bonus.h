/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:08:49 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 17:12:09 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_BONUS_H
# define WORLD_BONUS_H
# include "solid_shape_bonus.h"
# include "canvas_bonus.h"
# include "array_list.h"
# include "vector.h"
# define VECTOR_ATTRIBUTE_COUNT 3
# define COLORS_ATTRIBUTE_COUNT 3

typedef struct s_ambient_light
{
	float		ratio_in_range;
	t_ivector3	colors;
}	t_ambient_light;

typedef enum ambient_attribute
{
	AMBIENT_ATTRIBUTE_RATIO_IN_RANGE = 1,
	AMBIENT_ATTRIBUTE_COLORS,
	AMBIENT_ATTRIBUTE_LENGTH
}	t_ambient_attribute;

typedef struct s_camera
{
	t_vector3	coordinates;
	t_matrix3x3	local_basis;
	t_vector3	normalized_orientation_vector_of_axis;
	float		field_of_view;
	float		x_theta;
	float		y_theta;
}	t_camera;

typedef enum camera_attribute
{
	CAMERA_ATTRIBUTE_COORDINATES = 1,
	CAMERA_ATTRIBUTE_ORIENTATION_VECTOR,
	CAMERA_ATTRIBUTE_FOV,
	CAMERA_ATTRIBUTE_LENGTH
}	t_camera_attribute;

typedef struct s_light
{
	t_vector3	coordinates;
	float		ratio_in_range;
	t_ivector3	colors;
}	t_light;

typedef struct s_world
{
	t_camera		camera;
	bool			is_valid_camera;
	t_ambient_light	ambient_light;
	bool			is_valid_ambient_light;
	t_light			light;
	bool			is_valid_light;
	t_array_list	solid_shapes;
}	t_world;

typedef enum light_attribute
{
	LIGHT_ATTRIBUTE_COORDINATES = 1,
	LIGHT_ATTRIBUTE_RATIO_IN_RANGE,
	LIGHT_ATTRIBUTE_COLORS,
	LIGHT_ATTRIBUTE_LENGTH
}	t_light_attribute;

void	init_world(t_world *world);
void	destroy_world(t_world *world);
bool	try_add_ambient_light_to_world(char **attributes, t_world *world);
bool	try_add_light_to_world(char **attributes, t_world *world);
bool	try_add_camera_to_world(char **attributes, \
t_world *world, t_canvas *canvas);
void	init_camera(t_world *world, t_canvas *canvas);

#endif