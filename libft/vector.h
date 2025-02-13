/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:18:05 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 19:46:46 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdbool.h>

typedef union s_vector3
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	float	xyz[3];
}	t_vector3;

typedef union s_ivector3
{
	struct
	{
		int	x;
		int	y;
		int	z;
	};
	int	xyz[3];
}	t_ivector3;

typedef union s_vector4
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	a;
	};
	float	xyza[4];
}	t_vector4;

typedef union s_ivector4
{
	struct
	{
		int	x;
		int	y;
		int	z;
		int	a;
	};
	int	xyza[4];
}	t_ivector4;

float		dot_product3x3(const t_vector3 vector0, const t_vector3 vector1);
float		dot_product4x4(const t_vector4 vector0, const t_vector4 vector1);
t_vector3	get_vector3(const float x, const float y, const float z);
t_ivector3	get_ivector3(const int x, const int y, const int z);
t_vector3	cross_product3x3(const t_vector3 vector0, const t_vector3 vector1);
t_vector3	add_vector3(const t_vector3 v0, const t_vector3 v1);
t_vector3	subtract_vector3(const t_vector3 v0, const t_vector3 v1);
t_vector3	multiply_vector3(const t_vector3 v, const float t);
t_vector3	divide_vector3(const t_vector3 v, const float t);
t_vector3	normalize_vector3(const t_vector3 v);
bool		is_uneqaul_vector3(const t_vector3 v0, const t_vector3 v1);
void		print_vector3(const char *message, const t_vector3 v);
float		get_length_in_vector3(const t_vector3 v);
t_ivector3	multiply_ivector3(const t_ivector3 iv, const float t);
t_ivector3	add_ivector3(const t_ivector3 v0, const t_ivector3 v1);

#endif
