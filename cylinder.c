/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:14 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 20:08:05 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "equation.h"
#include "solid_shape.h"

t_cylinder	*copy_construction_to_cylinder(const t_cylinder cylinder)
{
	t_cylinder	*result;

	result = malloc(sizeof(t_cylinder));
	result->shape.coordinates = cylinder.shape.coordinates;
	result->shape.colors = cylinder.shape.colors;
	result->shape.is_hit = is_hit_cylinder;
	result->shape.delete = delete_cylinder;
	result->normalized_orientation_vector_of_axis = \
	cylinder.normalized_orientation_vector_of_axis;
	result->diameter = cylinder.diameter;
	result->height = cylinder.height;
	return (result);
}

void	delete_cylinder(void *obj)
{
	free(obj);
}

bool	is_hit_cylinder(const t_ray ray, const void *obj, t_hit_record *out)
{
	const t_cylinder			*cylinder = obj;
	const t_quadratic_equation	equation = load_hit_cylinder_equation(ray, *cylinder);
	float						solution;
	float						height;
	
	solution = (-equation.b - sqrtf(equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
	if (solution <= 0 || out->t <= solution)
	{
		solution = (-equation.b + sqrtf(equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution <= 0 || out->t <= solution)
		{
			return (false);
		}
	}
	height = calculate_cylinder_hit_height(ray, *cylinder, solution);
	if (equation.discriminant > 0 && height <= cylinder->height / 2)
	{
		out->t = solution;
		out->point = get_point_in_ray(ray, out->t);
		out->normal = divide_vector3(subtract_vector3(out->point, cylinder->shape.coordinates), cylinder->diameter / 2);
		out->color = cylinder->shape.colors;
		out->object = (void *)cylinder;
		return (true);
	}
	// (p - c) * N = 0
	// (O + sD - (C + hB)) * N = 0
	// NO + sND - NC = 0
	// s = N(C + hB - O) / ND 
	
	const t_vector3	n = cylinder->normalized_orientation_vector_of_axis;
	const t_ray		upward_ray = get_ray(cylinder->shape.coordinates, n);
	const t_vector3	up_c = get_point_in_ray(upward_ray, cylinder->height / 2); 
	//  C + hB : up_c or down_c
	//  O + sD : 
	float		numerator = dot_product3x3(n, \
	subtract_vector3(up_c, ray.origin));
	float		denominator = dot_product3x3(n, ray.direction);
	if (denominator != 0 \
	&& numerator / denominator > 0 \
	&& numerator / denominator < out->t)
	{
		solution = numerator / denominator;
		const t_vector3 p = get_point_in_ray(ray, solution);
		t_vector3 p_sub_c = subtract_vector3(p, up_c);
		if (dot_product3x3(p_sub_c, p_sub_c) < (cylinder->diameter / 2) * (cylinder->diameter / 2))
		{
			out->t = solution;
			out->point = p;
			out->normal = n;
			out->color = cylinder->shape.colors;
			out->object = (void *)cylinder;
			return (true);
		}
	}
	const t_vector3 down_c = get_point_in_ray(upward_ray, -(cylinder->height / 2));
	
	numerator = dot_product3x3(n, \
	subtract_vector3(down_c, ray.origin));
	denominator = dot_product3x3(n, ray.direction);
	if (denominator != 0 && numerator / denominator > 0 && numerator / denominator < out->t)
	{
		solution = numerator / denominator;
		const t_vector3 p = get_point_in_ray(ray, solution);
		t_vector3 p_sub_c = subtract_vector3(p, down_c);
		if (dot_product3x3(p_sub_c, p_sub_c) < (cylinder->diameter / 2) * (cylinder->diameter / 2))
		{
			out->t = solution;
			out->point = p;
			out->normal = multiply_vector3(n, -1);
			out->color = cylinder->shape.colors;
			out->object = (void *)cylinder;
			return (true);
		}
	}
	return (false);
}
