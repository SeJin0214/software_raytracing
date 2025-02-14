/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:28 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 21:14:16 by sejjeong         ###   ########.fr       */
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
# include "input.h"
# define X 0
# define Y 1
# define Z 2

typedef struct s_world	t_world;

typedef struct s_solid_shape
{
	t_vector3	coordinates;
	t_ivector3	colors;
	// local_basis로 그냥 방향 벡터 더해버리면 된다.
	// local_basis를 다 통일하자
	bool		(*is_hit)(const t_ray, const void *, t_hit_record *);
	void		(*delete)(void *);
	void		(*rotate)(void *, t_action);
	void		(*scale_height)(void *, t_action);
	void		(*scale_diameter)(void *, t_action);
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

/* plane.c */
t_plane		*copy_construction_to_plane(const t_plane plane);
void		delete_plane(void *obj);
bool		is_hit_plane(const t_ray ray, const void *plane, t_hit_record *out);

/* plane_action.c */
void		update_scale_diameter_plane(const void *plane, \
const t_action action);
void		update_scale_height_plane(const void *plane, \
const t_action action);
void		rotate_plane(const void *plane, const t_action action);

/* sphere.c */
t_sphere	*copy_construction_to_sphere(const t_sphere sphere);
void		delete_sphere(void *obj);
bool		is_hit_sphere(const t_ray ray, \
const void *sphere, t_hit_record *out);
void		set_hit_record_by_sphere(t_hit_record *out, \
const float solution, const t_ray ray, const t_sphere *sphere);

/* sphere_action.c */
void		update_scale_diameter_sphere(const void *sphere, \
const t_action action);
void		update_scale_height_sphere(const void *sphere, \
const t_action action);
void		rotate_sphere(const void *sphere, const t_action action);

/* cylinder_object.c */
t_cylinder	*copy_construction_to_cylinder(const t_cylinder cylinder);
void		delete_cylinder(void *obj);

/* cylinder.c */
bool		is_hit_cylinder(const t_ray ray, \
const void *cylinder, t_hit_record *out);
bool		is_hit_cylinder_end_cap(const t_ray ray, \
const t_cylinder *cylinder, t_hit_record *out);
bool		is_hit_up_cap(const t_ray ray, const t_cylinder *cylinder, \
const t_vector3 up_c, t_hit_record *out);
bool		is_hit_down_cap(const t_ray ray, const t_cylinder *cylinder, \
const t_vector3 down_c, t_hit_record *out);

/* cylinder_action.c */
void		update_scale_diameter_cylinder(const void *cylinder, \
const t_action action);
void		update_scale_height_cylinder(const void *cylinder, \
const t_action action);
void		rotate_cylinder(const void *cylinder, const t_action action);

void		destroy_shapes(t_array_list *list);

#endif
