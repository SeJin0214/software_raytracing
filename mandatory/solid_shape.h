/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:28 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/25 14:08:16 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_SHAPE_H
# define SOLID_SHAPE_H
# include <stdbool.h>
# include <stdalign.h>
# include "array_list.h"
# include "matrix.h"
# include "hit_record.h"
# include "ray.h"
# include "input.h"

typedef struct s_world	t_world;

typedef struct s_solid_shape
{
	alignas(16) t_vector3 coordinates;
	alignas(16) t_ivector3 colors;
	t_matrix3x3	local_basis;
	bool		(*is_hit)(const t_ray, const void *, t_hit_record *);
	void		(*delete)(void *);
	void		(*scale_height)(void *, const t_action);
	void		(*scale_diameter)(void *, const t_action);
}	t_solid_shape;

typedef enum sphere_attribute
{
	SPHERE_ATTRIBUTE_CENTER = 1,
	SPHERE_ATTRIBUTE_DIAMETER,
	SPHERE_ATTRIBUTE_COLORS,
	SPHERE_ATTRIBUTE_LENGTH
}	t_sphere_attribute;

typedef enum plane_attribute
{
	PLANE_ATTRIBUTE_COORDINATES = 1,
	PLANE_ATTRIBUTE_ORIENTATION_VECTOR,
	PLANE_ATTRIBUTE_COLORS,
	PLANE_ATTRIBUTE_LENGTH
}	t_plane_attribute;

typedef enum cylinder_attribute
{
	CYLINDER_ATTRIBUTE_COORDINATES = 1,
	CYLINDER_ATTRIBUTE_NORMALIZED_VECTOR,
	CYLINDER_ATTRIBUTE_DIAMETER,
	CYLINDER_ATTRIBUTE_HEIGHT,
	CYLINDER_ATTRIBUTE_COLORS,
	CYLINDER_ATTRIBUTE_LENGTH
}	t_cylinder_attribute;

/* solid_shape.c */
void		move_shape(void *obj, const t_action action);
void		rotate_shape(void *obj, const t_action action);
t_matrix3x3	get_local_basis(t_vector3 n);
void		destroy_shapes(t_array_list *list);

#endif
