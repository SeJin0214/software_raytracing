/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:26:19 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 05:03:05 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_BONUS_H
# define CYLINDER_BONUS_H
# include "solid_shape_bonus.h"
# include "solid_shape_getter_bonus.h"

typedef struct s_cylinder
{
	t_solid_shape	shape;
	float			diameter;
	float			height;
}	t_cylinder;

/** 
 * P = O + tD
 * c = C + hB 
 * D = camera direction
 * N = local_basis[Z]
 * (P - c) * N = 0
 * (O + tD - c) * N = 0
 * NO + tND - Nc = 0
 * t = N(c - O) / ND 
*/	
inline bool	is_hit_up_cap(const t_ray ray, const t_cylinder *cylinder, \
const t_vector3 up_c, t_hit_record *out)
{
	const float		numerator = dot_product3x3(cylinder->\
	shape.local_basis.row[Z], subtract_vector3(up_c, ray.origin));
	const float		denominator = dot_product3x3(\
	cylinder->shape.local_basis.row[Z], ray.direction);
	float			solution;
	t_vector3		p;
	t_vector3		p_sub_c;

	if (denominator == 0 || numerator / denominator < 0 \
	|| numerator / denominator >= out->t)
		return (false);
	solution = numerator / denominator;
	p = get_point_in_ray(ray, solution);
	p_sub_c = subtract_vector3(p, up_c);
	if (get_length_in_vector3(p_sub_c) * get_length_in_vector3(p_sub_c) > \
	(cylinder->diameter / 2) * (cylinder->diameter / 2))
		return (false);
	out->t = solution;
	out->point = p;
	out->normal = cylinder->shape.local_basis.row[Z];
	out->color = cylinder->shape.colors;
	out->object = (void *)cylinder;
	return (true);
}

inline bool	is_hit_down_cap(const t_ray ray, const t_cylinder *cylinder, \
const t_vector3 down_c, t_hit_record *out)
{
	const float		numerator = dot_product3x3(cylinder->\
	shape.local_basis.row[Z], subtract_vector3(down_c, ray.origin));
	const float		denominator = dot_product3x3(\
	cylinder->shape.local_basis.row[Z], ray.direction);
	float			solution;
	t_vector3		p;
	t_vector3		p_sub_c;

	if (denominator == 0 || numerator / denominator < 0 \
	|| numerator / denominator >= out->t)
		return (false);
	solution = numerator / denominator;
	p = get_point_in_ray(ray, solution);
	p_sub_c = subtract_vector3(p, down_c);
	if (dot_product3x3(p_sub_c, p_sub_c) > \
	(cylinder->diameter / 2) * (cylinder->diameter / 2))
		return (false);
	out->t = solution;
	out->point = p;
	out->normal = get_normal_at_hit_point(cylinder->shape, multiply_vector3(\
	cylinder->shape.local_basis.row[Z], -1), out->point);
	out->color = get_color_at_hit_point(cylinder->shape, out->point);
	out->object = (void *)cylinder;
	return (true);
}

inline bool	is_hit_cylinder_end_cap(const t_ray ray, \
const t_cylinder *cylinder, t_hit_record *out)
{
	const t_vector3	n = cylinder->shape.local_basis.row[Z];
	const t_ray		upward_ray = get_ray(cylinder->shape.coordinates, n);
	const t_vector3	up_c = get_point_in_ray(upward_ray, cylinder->height / 2);
	const t_vector3	down_c = get_point_in_ray(upward_ray, \
	-(cylinder->height / 2));
	bool			is_hit;

	is_hit = is_hit_up_cap(ray, cylinder, up_c, out);
	is_hit = is_hit_down_cap(ray, cylinder, down_c, out) || is_hit;
	return (is_hit);
}

inline t_ivector2	get_uv_coordinate_in_cylinder(const void *cylinder, const t_vector3 hit_point)
{
	t_ivector2	uv;
	
	uv.x = 0;
	
	(void) cylinder;
	(void) hit_point;
	return (uv);
}

bool		is_hit_cylinder(const t_ray ray, \
const void *obj, t_hit_record *out);

/* cylinder_object.c */
t_cylinder	*copy_construction_to_cylinder(const t_cylinder cylinder);
void		delete_cylinder(void *obj);

/* cylinder_action.c */
void		update_scale_diameter_cylinder(void *cylinder, \
const t_action action);
void		update_scale_height_cylinder(void *cylinder, \
const t_action action);

#endif