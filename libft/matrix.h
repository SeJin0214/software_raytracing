/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:42:46 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 19:46:13 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "vector.h"

typedef union s_matrix3x3
{
	float		row_f[3][3];
	t_vector3	row[3];
}	t_matrix3x3;

typedef union s_matrix4x4
{
	float		row_f[4][4];
	t_vector4	row[4];
}	t_matrix4x4;

t_matrix3x3	multiply_matrix3x3(const t_matrix3x3 left, \
const t_matrix3x3 right);
t_vector3	multiply_vector_and_matrix3x3(const t_vector3 left, \
const t_matrix3x3 right);
t_matrix3x3	transpose(const t_matrix3x3 m);
void		print_matrix3x3(const t_matrix3x3 m);
#endif