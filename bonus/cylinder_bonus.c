/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:14 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 03:34:22 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cylinder_bonus.h"
#include "equation_bonus.h"
#include "solid_shape_getter_bonus.h"

bool	is_hit_cylinder(const t_ray ray, \
const void *obj, t_hit_record *out)
{
	const t_cylinder			*cy = obj;
	const t_quadratic_equation	quadratic = load_hit_cy_equation(ray, *cy);
	float						solution;
	bool						is_hit;
	float						height;

	is_hit = is_hit_cylinder_end_cap(ray, cy, out);
	solution = get_quadtatic_root_minus(quadratic);
	if (solution <= 0 || out->t <= solution)
	{
		solution = get_quadtatic_root_plus(quadratic);
		if (solution <= 0 || out->t <= solution)
			return (is_hit);
	}
	height = calculate_cylinder_hit_height(ray, *cy, solution);
	if (quadratic.discriminant <= 0 || fabsf(height) > cy->height / 2)
		return (is_hit);
	out->t = solution;
	out->point = get_point_in_ray(ray, out->t);
	out->normal = get_normal_at_hit_point(cy->shape, normalize_vector3(\
	subtract_vector3(out->point, get_point_in_ray(get_ray(cy->\
	shape.coordinates, cy->shape.local_basis.row[Z]), height))), out->point);
	out->color = get_color_at_hit_point(cy->shape, out->point);
	out->object = (void *)cy;
	return (true);
}

extern inline bool	is_hit_cylinder_end_cap(const t_ray ray, \
const t_cylinder *cylinder, t_hit_record *out);

extern inline bool	is_hit_up_cap(const t_ray ray, \
const t_cylinder *cylinder, const t_vector3 up_c, t_hit_record *out);

extern inline bool	is_hit_down_cap(const t_ray ray, \
const t_cylinder *cylinder, const t_vector3 down_c, t_hit_record *out);
