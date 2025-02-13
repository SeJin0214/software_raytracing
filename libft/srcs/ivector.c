/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:58:53 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 18:04:55 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

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

t_ivector3	get_ivector3(const int x, const int y, const int z)
{
	t_ivector3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
