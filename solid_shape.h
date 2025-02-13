/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:28 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 19:34:15 by sejjeong         ###   ########.fr       */
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

typedef struct s_solid_shape
{
	t_vector3	coordinates;
	t_ivector3	colors;
	bool		(*is_hit)(const t_ray, const void *, t_hit_record *);
	void		(*delete)(void *);
}	t_solid_shape;

typedef struct s_sphere
{
	t_solid_shape	shape;
	float			diameter;
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
	t_solid_shape	shape;
	t_vector3		normalized_orientation_vector_of_axis;
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
	t_solid_shape	shape;
	t_vector3		normalized_orientation_vector_of_axis;
	float			diameter;
	float			height;
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

bool		is_hit_plane(const t_ray ray, const void *plane, t_hit_record *out);
bool		is_hit_sphere(const t_ray ray, \
const void *sphere, t_hit_record *out);
bool		is_hit_cylinder(const t_ray ray, \
const void *cylinder, t_hit_record *out);

t_sphere	*copy_construction_to_sphere(const t_sphere sphere);
void		delete_sphere(void *obj);
t_cylinder	*copy_construction_to_cylinder(const t_cylinder cylinder);
void		delete_cylinder(void *obj);
t_plane		*copy_construction_to_plane(const t_plane plane);
void		delete_plane(void *obj);
void		destroy_shapes(t_array_list *list);

#endif
