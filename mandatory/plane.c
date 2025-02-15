/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:32:39 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 13:54:41 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "solid_shape.h"

t_plane	*copy_construction_to_plane(const t_plane plane)
{
	t_plane	*result;

	result = malloc(sizeof(t_plane));
	result->shape = plane.shape;
	result->shape.is_hit = is_hit_plane;
	result->shape.delete = delete_plane;
	result->shape.scale_diameter = update_scale_diameter_plane;
	result->shape.scale_height = update_scale_height_plane;
	return (result);
}

void	delete_plane(void *obj)
{
	free(obj);
}

/**
 * N : normal
 * N * (p1 - p2) = 0
 * p2 : camera ray point, O + tD
 * N * (p1 - (O + tD)) = 0
 * Np1 - NO - tND = 0
 * tND = Np1 - NO
 * t = (Np1 - NO) / ND 
 */
bool	is_hit_plane(const t_ray ray, const void *obj, t_hit_record *out)
{
	const t_plane	*plane = obj;
	const t_vector3	n = plane->shape.local_basis.row[Z];
	const float		numerator = dot_product3x3(n, \
	subtract_vector3(plane->shape.coordinates, ray.origin));
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
	out->color = plane->shape.colors;
	out->object = (void *)plane;
	return (true);
}
