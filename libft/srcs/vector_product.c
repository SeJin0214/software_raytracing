/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:57 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 18:05:03 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

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

	result.x = vector0.y * vector1.z - vector0.z * vector1.y;
	result.y = vector0.z * vector1.x - vector0.x * vector1.z;
	result.z = vector0.x * vector1.y - vector0.y * vector1.x;
	return (result);
}
