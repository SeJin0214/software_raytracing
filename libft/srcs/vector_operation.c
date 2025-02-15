/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:01:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 20:36:50 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdalign.h>
#include "vector.h"

t_vector3	add_vector3(const t_vector3 v0, const t_vector3 v1)
{
	alignas(16) t_vector3 result;
	result.x = v0.x + v1.x;
	result.y = v0.y + v1.y;
	result.z = v0.z + v1.z;
	result.xyz[3] = v0.xyz[3] + v1.xyz[3];
	return (result);
}

t_vector3	subtract_vector3(const t_vector3 v0, const t_vector3 v1)
{
	alignas(16) t_vector3 result;
	result.x = v0.x - v1.x;
	result.y = v0.y - v1.y;
	result.z = v0.z - v1.z;
	result.xyz[3] = v0.xyz[3] - v1.xyz[3];
	return (result);
}

t_vector3	multiply_vector3(const t_vector3 v, const float t)
{
	alignas(16) t_vector3 result;
	result.x = v.x * t;
	result.y = v.y * t;
	result.z = v.z * t;
	result.xyz[3] = v.xyz[3] * t;
	return (result);
}

t_vector3	divide_vector3(const t_vector3 v, const float t)
{
	alignas(16) t_vector3 result;
	result.x = v.x / t;
	result.y = v.y / t;
	result.z = v.z / t;
	result.xyz[3] = v.xyz[3] / t;
	return (result);
}
