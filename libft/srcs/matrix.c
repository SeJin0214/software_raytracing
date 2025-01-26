/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:54:49 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/26 13:44:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

t_matrix3x3	multiply_matrix3x3(const t_matrix3x3 left, const t_matrix3x3 right)
{
	int			i;
	t_matrix3x3	result;

	i = 0;
	while (i < 3)
	{
		result.row[i] = \
		multiply_vector_and_matrix3x3(left.row[i], right);
		++i;
	}
	return (result);
}

t_vector3	multiply_vector_and_matrix3x3(const t_vector3 left, \
const t_matrix3x3 right)
{
	t_vector3	result;
	size_t		j;
	size_t		k;

	j = 0;
	while (j < 3)
	{
		k = 0;
		result.xyz[j] = 0;
		while (k < 3)
		{
			result.xyz[j] += left.xyz[k] * right.row_f[k][j];
			++k;
		}
		++j;
	}
	//print_vector3(result);
	return (result);
}

t_matrix3x3	transpose(const t_matrix3x3 m)
{
	const t_matrix3x3	result = {{
		{m.row_f[0][0], m.row_f[1][0], m.row_f[2][0]},
		{m.row_f[0][1], m.row_f[1][1], m.row_f[2][1]},
		{m.row_f[0][2], m.row_f[1][2], m.row_f[2][2]}
	}};
	
	return (result);
}

void	print_matrix3x3(const t_matrix3x3 m)
{
	printf("m ----\n");
	printf("%f, %f, %f\n", m.row_f[0][0], m.row_f[0][1], m.row_f[0][2]);
	printf("%f, %f, %f\n", m.row_f[1][0], m.row_f[1][1], m.row_f[1][2]);
	printf("%f, %f, %f\n", m.row_f[2][0], m.row_f[2][1], m.row_f[2][2]);
	printf("------\n");
}
