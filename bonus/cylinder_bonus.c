/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:14 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 08:08:43 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cylinder_bonus.h"
#include "equation_bonus.h"

bool	is_hit_cylinder(const t_ray ray, \
const void *obj, t_hit_record *out)
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
	out->normal = normalize_vector3(subtract_vector3(\
	out->point, cy->shape.coordinates));
	out->color = cy->shape.colors;
	out->object = (void *)cy;
	return (true);
}

extern inline bool	is_hit_cylinder_end_cap(const t_ray ray, \
const t_cylinder *cylinder, t_hit_record *out);

extern inline bool	is_hit_up_cap(const t_ray ray, \
const t_cylinder *cylinder, const t_vector3 up_c, t_hit_record *out);

extern inline bool	is_hit_down_cap(const t_ray ray, \
const t_cylinder *cylinder, const t_vector3 down_c, t_hit_record *out);
