/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivector_operation.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:55:11 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 15:26:31 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVECTOR_OPERATION_H
# define IVECTOR_OPERATION_H
# include "vector_struct.h"

inline t_ivector3	get_ivector3(const int x, const int y, const int z)
{
	t_ivector3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

inline t_ivector3	multiply_ivector3(const t_ivector3 iv, const float t)
{
	const t_ivector3	result = {{iv.x * t, iv.y * t, iv.z * t}};

	return (result);
}

inline t_ivector3	add_ivector3(const t_ivector3 v0, const t_ivector3 v1)
{
	t_ivector3	result;

	result.x = v0.x + v1.x;
	result.y = v0.y + v1.y;
	result.z = v0.z + v1.z;
	return (result);
}

#endif