/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:31:36 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/26 13:49:00 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"

t_ray		get_ray(const t_vector3 origin, const t_vector3 direction)
{
	t_ray	ray;
	
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_vector3	get_point_in_ray(const t_ray ray, const float t)
{
	return (add_vector3(ray.origin, multiply_vector3(ray.direction, t)));
}