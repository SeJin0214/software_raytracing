/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:52:03 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/28 18:55:49 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_cone_bonus.h"
#include "equation_bonus.h"
#include "hit_cylinder_bonus.h"
#include "ft_math.h"

extern inline bool		is_hit_down_cap_in_cone(const t_ray ray, \
const t_cone *cone, const t_vector3 down_c, t_hit_record *out);

extern inline t_vector3	get_normal_in_cone(const t_vector3 point, \
const t_cone cone);

bool	is_hit_cone(const t_ray ray, \
const void *obj, t_hit_record *out)
{
	const t_cone				*cone = obj;
	const t_quadratic_equation	quadratic = load_hit_cone_equation(ray, *cone);
	float						solution;
	bool						is_hit;
	float						height;

	is_hit = is_hit_down_cap_in_cone(ray, cone, cone->shape.coordinates, out);
	solution = get_quadtatic_root_minus(quadratic);
	if (solution <= 0 || out->t <= solution)
	{
		solution = get_quadtatic_root_plus(quadratic);
		if (solution <= 0 || out->t <= solution)
			return (is_hit);
	}
	height = calculate_hit_height(ray, \
	cone->shape.local_basis.row[Z], cone->shape.coordinates, solution);
	if (quadratic.discriminant <= 0 \
	|| height > cone->height || height <= __FLT_EPSILON__)
		return (is_hit);
	out->t = solution;
	out->point = get_point_in_ray(ray, solution);
	out->normal = get_normal_at_hit_point(cone, \
	get_normal_in_cone(out->point, *cone), out->point);
	out->color = get_color_at_hit_point(cone, out->point);
	out->object = (void *)cone;
	return (true);
}
