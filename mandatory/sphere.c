/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:59:06 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/20 05:01:42 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "sphere.h"
#include "equation.h"

t_sphere	*copy_construction_to_sphere(const t_sphere sphere)
{
	t_sphere	*result;

	result = malloc(sizeof(t_sphere));
	result->shape = sphere.shape;
	result->shape.is_hit = is_hit_sphere;
	result->shape.delete = delete_sphere;
	result->shape.scale_diameter = update_scale_diameter_sphere;
	result->shape.scale_height = update_scale_height_sphere;
	result->diameter = sphere.diameter;
	return (result);
}

void	delete_sphere(void *obj)
{
	free(obj);
}

bool	is_hit_sphere(const t_ray ray, const void *obj, t_hit_record *out)
{
	const t_sphere			*sphere = obj;
	const t_vector3			oc = \
	subtract_vector3(ray.origin, sphere->shape.coordinates);
	t_quadratic_equation	equation;
	float					solution;

	equation.a = dot_product3x3(ray.direction, ray.direction);
	equation.b = 2.0f * dot_product3x3(oc, ray.direction);
	equation.c = dot_product3x3(oc, oc) - (sphere->diameter / 2) \
	* (sphere->diameter / 2);
	equation.discriminant = equation.b * equation.b \
	- 4 * equation.a * equation.c;
	if (equation.discriminant <= 0)
		return (false);
	solution = (-equation.b - sqrtf(equation.b * equation.b \
	- 4 * equation.a * equation.c)) / (2 * equation.a);
	if (solution <= 0 || out->t < solution)
	{
		solution = (-equation.b + sqrtf(equation.b * equation.b \
		- 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution <= 0 || out->t < solution)
			return (false);
	}
	set_hit_record_by_sphere(out, solution, ray, sphere);
	return (true);
}

extern inline void	set_hit_record_by_sphere(t_hit_record *out, \
const float solution, const t_ray ray, const t_sphere *sphere);
