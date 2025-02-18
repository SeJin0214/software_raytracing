/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:42:03 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 14:13:03 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdalign.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"
#define FLT_EPSILON 1.19209289550781250000000000000000000e-7F

extern inline float		get_length_in_vector3(const t_vector3 v);
extern inline t_vector3	normalize_vector3(const t_vector3 v);

t_vector3	get_vector3(const float x, const float y, \
const float z)
{
	alignas(16) t_vector3 result;
	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

bool	is_uneqaul_vector3(const t_vector3 v0, \
const t_vector3 v1)
{
	return (fabsf(v0.x - v1.x) > FLT_EPSILON \
	|| fabsf(v0.y - v1.y) > FLT_EPSILON \
	|| fabsf(v0.z - v1.z) > FLT_EPSILON);
}

void	print_vector3(const char *message, const t_vector3 v)
{
	printf("%s, v = %f, %f, %f\n", message, v.x, v.y, v.z);
}
