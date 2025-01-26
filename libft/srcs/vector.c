/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:42:03 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/26 13:43:39 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "vector.h"

t_vector4	init_vector4(const float x, const float y, const float z, const float a)
{
	t_vector4	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.a = a;
	return (result);
}

float	dot_product3x3(const t_vector3 vector0, const t_vector3 vector1)
{
	return (vector0.x * vector1.x \
	+ vector0.y * vector1.y + vector0.z * vector1.z);
}

float	dot_product4x4(const t_vector4 vector0, const t_vector4 vector1)
{
	return (vector0.x * vector1.x + vector0.y * vector1.y \
	+ vector0.z * vector1.z + vector0.a * vector1.a);
}

t_vector3	cross_product3x3(const t_vector3 vector0, const t_vector3 vector1)
{
	t_vector3	result;

	result.x = vector0.y * vector1.z + vector0.z * vector1.y;
	result.y = vector0.z * vector1.x + vector0.x * vector1.z;
	result.z = vector0.x * vector1.y + vector0.y * vector1.x;
	return (result);
}

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

float	get_length_in_vector3(const t_vector3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector3	normalize_vector3(const t_vector3 v)
{
	const float	length = get_length_in_vector3(v);
	t_vector3	result;

	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}

t_vector3	multiply_vector3(const t_vector3 v, const float t)
{
	const t_vector3	result = {{v.x * t, v.y * t, v.z * t}};

	return (result);
}

t_ivector3	multiply_ivector3(const t_ivector3 iv, const float t)
{
	const t_ivector3	result = {{iv.x * t, iv.y * t, iv.z * t}};

	return (result);
}

t_ivector3	add_ivector3(const t_ivector3 v0, const t_ivector3 v1)
{
	t_ivector3	result;

	result.x = v0.x + v1.x;
	result.y = v0.y + v1.y;
	result.z = v0.z + v1.z;
	return (result);
}

t_vector3	divide_vector3(const t_vector3 v, const float t)
{
	const t_vector3	result = {{v.x / t, v.y / t, v.z / t}};

	return (result);
}

void	print_vector3(const t_vector3 v)
{
	printf("v = %f, %f, %f\n", v.x, v.y, v.z);
}