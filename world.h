/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:08:49 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/10 17:54:12 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "solid_shape.h"
# include "array_list.h"
# include "vector.h"
# include "canvas.h"
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
	t_vector3	normalized_orientation_vector_of_axis; // [-1, 1]  * 180
	size_t		focal_length;
	int			field_of_view; // 제거
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
	
	// hits 를 들고 있는다?
	// void * 받아서 
	// 함수마다 다형성 구현
	// 그러면 array_list로 넣을 때, 포인터로 넣어야 한다.
	
	
	t_array_list	spheres;
	t_array_list	planes;
	t_array_list	cylinders;
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
bool	try_add_camera_to_world(char **attributes, t_world *world, t_canvas *canvas);
void	init_camera(t_world *world, t_canvas *canvas);
bool	try_parse_vector3(char *attribute, t_vector3 *out_result);
bool	try_parse_color(char *attribute, t_ivector3 *out_result);
int		convert_colors(t_ivector3 colors);

bool	is_invalid_normalized_vector3(t_vector3 vector);
bool	is_invalid_ratio_in_range(float ratio_in_range);
bool	is_invalid_colors(t_ivector3 colors);

#endif