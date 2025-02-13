/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:32:39 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 19:46:27 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solid_shape.h"
#include "hit_record.h"
#include "ray.h"

/**
 * N : normal
 * N * (p1 - p2) = 0
 * p2 : camera ray point, O + tD
 * N * (p1 - (O + tD)) = 0
 * Np1 - NO - tND = 0
 * tND = Np1 - NO
 * t = (Np1 - NO) / ND 
 */
bool	is_hit_plane(const t_ray ray, const t_plane *plane, t_hit_record *out)
{
	const t_vector3	n = plane->normalized_orientation_vector_of_axis;
	const float		numerator = dot_product3x3(n, \
	subtract_vector3(plane->coordinates, ray.origin));
	const float		denominator = dot_product3x3(n, ray.direction);

	if (denominator == 0 \
	|| numerator / denominator <= 0 \
	|| numerator / denominator >= out->t)
	{
		return (false);
	}
	out->t = numerator / denominator;
	out->point = get_point_in_ray(ray, out->t);
	out->normal = n;
	out->color = plane->colors;
	out->object = (void *)plane;
	return (true);
}
