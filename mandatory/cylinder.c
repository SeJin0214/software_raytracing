/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:14 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/19 20:48:46 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "equation.h"
#include "solid_shape.h"

bool	is_hit_cylinder(const t_ray ray, const void *obj, t_hit_record *out)
{
	const t_cylinder			*cy = obj;
	const t_quadratic_equation	equation = load_hit_cy_equation(ray, *cy);
	float						solution;
	bool						is_hit;

	is_hit = is_hit_cylinder_end_cap(ray, cy, out);
	solution = (-equation.b - sqrtf(\
	equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
	if (solution <= 0 || out->t <= solution)
	{
		solution = (-equation.b + sqrtf(equation.b * \
		equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution <= 0 || out->t <= solution)
			return (is_hit);
	}
	if (equation.discriminant <= 0 || calculate_cylinder_hit_height(ray, \
	*cy, solution) > cy->height / 2)
		return (is_hit);
	out->t = solution;
	out->point = get_point_in_ray(ray, out->t);
	out->normal = divide_vector3(subtract_vector3(\
	out->point, cy->shape.coordinates), cy->diameter / 2);
	out->color = cy->shape.colors;
	out->object = (void *)cy;
	return (true);
}

bool	is_hit_cylinder_end_cap(const t_ray ray, \
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
bool	is_hit_up_cap(const t_ray ray, const t_cylinder *cylinder, \
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

bool	is_hit_down_cap(const t_ray ray, const t_cylinder *cylinder, \
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
	out->normal = multiply_vector3(\
	cylinder->shape.local_basis.row[Z], -1);
	out->color = cylinder->shape.colors;
	out->object = (void *)cylinder;
	return (true);
}
