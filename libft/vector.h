/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:18:05 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 14:57:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdbool.h>
# include <math.h>
# include "vector_struct.h"
# include "vector_operation.h"
# include "ivector_operation.h"

float		dot_product4x4(const t_vector4 vector0, const t_vector4 vector1);
t_vector3	get_vector3(const float x, const float y, const float z);
t_vector3	cross_product3x3(const t_vector3 vector0, const t_vector3 vector1);
bool		is_uneqaul_vector3(const t_vector3 v0, const t_vector3 v1);
void		print_vector3(const char *message, const t_vector3 v);

inline float	get_length_in_vector3(const t_vector3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline float	dot_product3x3(const t_vector3 vector0, const t_vector3 vector1)
{
	return (vector0.x * vector1.x + vector0.y * vector1.y \
	+ vector0.z * vector1.z);
}

inline t_vector3	normalize_vector3(const t_vector3 v)
{
	const float	length = get_length_in_vector3(v);
	t_vector3	result;

	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}

#endif
