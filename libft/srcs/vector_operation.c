/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:01:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 19:46:35 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	add_vector3(const t_vector3 v0, const t_vector3 v1)
{
	t_vector3	result;

	result.x = v0.x + v1.x;
	result.y = v0.y + v1.y;
	result.z = v0.z + v1.z;
	return (result);
}

t_vector3	subtract_vector3(const t_vector3 v0, const t_vector3 v1)
{
	t_vector3	result;

	result.x = v0.x - v1.x;
	result.y = v0.y - v1.y;
	result.z = v0.z - v1.z;
	return (result);
}

t_vector3	multiply_vector3(const t_vector3 v, const float t)
{
	const t_vector3	result = {{v.x * t, v.y * t, v.z * t}};

	return (result);
}

t_vector3	divide_vector3(const t_vector3 v, const float t)
{
	const t_vector3	result = {{v.x / t, v.y / t, v.z / t}};

	return (result);
}
