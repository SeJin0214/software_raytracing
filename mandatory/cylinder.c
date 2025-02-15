/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:14 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 19:37:28 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "equation.h"
#include "solid_shape.h"

bool	is_hit_cylinder(const t_ray ray, const void *obj, t_hit_record *out)
{
	const t_cylinder			*cylinder = obj;
	const t_quadratic_equation	equation = \
	load_hit_cylinder_equation(ray, *cylinder);
	float						solution;
	float						height;

	solution = (-equation.b - sqrtf(\
	equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
	if (solution <= 0 || out->t <= solution)
	{
		solution = (-equation.b + sqrtf(equation.b * \
		equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution <= 0 || out->t <= solution)
			return (false);
	}
	height = calculate_cylinder_hit_height(ray, *cylinder, solution);
	if (equation.discriminant <= 0 || height > cylinder->height / 2)
		return (is_hit_cylinder_end_cap(ray, cylinder, out));
	out->t = solution;
	out->point = get_point_in_ray(ray, out->t);
	out->normal = divide_vector3(subtract_vector3(\
	out->point, cylinder->shape.coordinates), cylinder->diameter / 2);
	out->color = cylinder->shape.colors;
	out->object = (void *)cylinder;
	return (true);
}

bool	is_hit_cylinder_end_cap(const t_ray ray, \
const t_cylinder *cylinder, t_hit_record *out)
{
	const t_vector3	n = cylinder->shape.local_basis.row[Z];
	const t_ray		upward_ray = get_ray(cylinder->shape.coordinates, n);
	const t_vector3	up_c = get_point_in_ray(upward_ray, cylinder->height / 2);
	t_vector3		down_c;

	if (is_hit_up_cap(ray, cylinder, up_c, out))
	{
		return (true);
	}
	down_c = get_point_in_ray(upward_ray, -(cylinder->height / 2));
	if (is_hit_down_cap(ray, cylinder, down_c, out))
	{
		return (true);
	}
	return (false);
}

/** 
 * (p - c) * N = 0
 * (O + sD - (C + hB)) * N = 0
 * NO + sND - NC = 0
 * s = N(C + hB - O) / ND 
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

	if (denominator == 0 || numerator / denominator <= 0 \
	|| numerator / denominator >= out->t)
		return (false);
	solution = numerator / denominator;
	p = get_point_in_ray(ray, solution);
	p_sub_c = subtract_vector3(p, up_c);
	if (dot_product3x3(p_sub_c, p_sub_c) >= \
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

	if (denominator == 0 || numerator / denominator <= 0 \
	|| numerator / denominator >= out->t)
		return (false);
	solution = numerator / denominator;
	p = get_point_in_ray(ray, solution);
	p_sub_c = subtract_vector3(p, down_c);
	if (dot_product3x3(p_sub_c, p_sub_c) >= \
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
