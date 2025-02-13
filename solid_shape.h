/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:28 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 17:20:05 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_SHAPE_H
# define SOLID_SHAPE_H
# include <stdbool.h>
# include "vector.h"
# include "array_list.h"
# include "matrix.h"
# include "hit_record.h"
# include "ray.h"
# define X 0
# define Y 1
# define Z 2

typedef struct s_world	t_world;

// 자료구조에 object를 넣어야 겠고.. 
// 할당한 애들을
// array_list를 그럼 .. 

typedef struct s_solid_shape
{
	t_vector3	coordinates;
	t_ivector3	colors;
	bool		(*is_hit)(const t_ray , const void *, t_hit_record *);
}	t_solid_shape;

typedef struct s_sphere
{
	t_vector3	center;
	t_ivector3	colors;
	float		diameter;
}	t_sphere;

typedef enum sphere_attribute
{
	SPHERE_ATTRIBUTE_CENTER = 1,
	SPHERE_ATTRIBUTE_DIAMETER,
	SPHERE_ATTRIBUTE_COLORS,
	SPHERE_ATTRIBUTE_LENGTH
}	t_sphere_attribute;

typedef struct s_plane
{
	t_vector3	coordinates;
	t_ivector3	colors;
	t_vector3	normalized_orientation_vector_of_axis;
}	t_plane;

typedef enum plane_attribute
{
	PLANE_ATTRIBUTE_COORDINATES = 1,
	PLANE_ATTRIBUTE_ORIENTATION_VECTOR,
	PLANE_ATTRIBUTE_COLORS,
	PLANE_ATTRIBUTE_LENGTH
}	t_plane_attribute;

typedef struct s_cylinder
{
	t_vector3	coordinates;
	t_ivector3	colors;
	t_vector3	normalized_orientation_vector_of_axis;
	float		diameter;
	float		height;
}	t_cylinder;

typedef enum cylinder_attribute
{
	CYLINDER_ATTRIBUTE_COORDINATES = 1,
	CYLINDER_ATTRIBUTE_NORMALIZED_VECTOR,
	CYLINDER_ATTRIBUTE_DIAMETER,
	CYLINDER_ATTRIBUTE_HEIGHT,
	CYLINDER_ATTRIBUTE_COLORS,
	CYLINDER_ATTRIBUTE_LENGTH
}	t_cylinder_attribute;

bool	try_add_plane_to_world(char **attributes, t_world *world);
bool	try_add_cylinder_to_world(char **attributes, t_world *world);
bool	try_add_sphere_to_world(char **attributes, t_world *world);

void	load_sphere_points(t_sphere *sphere);
void	destory_sphere(void *obj);
void	load_cylinder_points(t_cylinder *cylinder);
void	destory_cylinder(void *obj);
void	load_plane_points(t_plane *plane);
void	destory_plane(void *obj);

#endif
