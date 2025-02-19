/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:25:07 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/19 17:25:41 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATION_H
# define VECTOR_OPERATION_H
# include "vector_struct.h"

inline t_vector3	add_vector3(const t_vector3 v0, const t_vector3 v1)
{
	alignas(16) t_vector3 result;
	result.x = v0.x + v1.x;
	result.y = v0.y + v1.y;
	result.z = v0.z + v1.z;
	return (result);
}

inline t_vector3	subtract_vector3(const t_vector3 v0, const t_vector3 v1)
{
	alignas(16) t_vector3 result;
	result.x = v0.x - v1.x;
	result.y = v0.y - v1.y;
	result.z = v0.z - v1.z;
	return (result);
}

inline t_vector3	multiply_vector3(const t_vector3 v, const float t)
{
	alignas(16) t_vector3 result;
	result.x = v.x * t;
	result.y = v.y * t;
	result.z = v.z * t;
	return (result);
}

inline t_vector3	divide_vector3(const t_vector3 v, const float t)
{
	alignas(16) t_vector3 result;
	result.x = v.x / t;
	result.y = v.y / t;
	result.z = v.z / t;
	return (result);
}

#endif
