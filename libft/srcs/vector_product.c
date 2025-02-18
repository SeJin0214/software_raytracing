/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:57 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 14:14:21 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdalign.h>
#include <stddef.h>
#include "vector.h"

extern inline float	dot_product3x3(const t_vector3 vector0, \
const t_vector3 vector1);

float	dot_product4x4(const t_vector4 vector0, const t_vector4 vector1)
{
	float	result;
	size_t	i;

	result = 0.0f;
	i = 0;
	while (i < 4)
	{
		result += vector0.xyza[i] * vector1.xyza[i];
		++i;
	}
	return (result);
}

t_vector3	cross_product3x3(const t_vector3 vector0, const t_vector3 vector1)
{
	alignas(16) t_vector3 result;
	result.x = vector0.y * vector1.z - vector0.z * vector1.y;
	result.y = vector0.z * vector1.x - vector0.x * vector1.z;
	result.z = vector0.x * vector1.y - vector0.y * vector1.x;
	return (result);
}
