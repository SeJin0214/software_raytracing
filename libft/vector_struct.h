/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:29:16 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/28 20:34:49 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_STRUCT_H
# define VECTOR_STRUCT_H
# include <stdalign.h>

typedef union __attribute__((aligned(16))) s_vector2
{
	struct
	{
		float	x;
		float	y;
	};
	float	xy[4];
}	t_vector2;

typedef union __attribute__((aligned(16))) s_ivector2
{
	struct
	{
		int	x;
		int	y;
	};
	int	xy[4];
}	t_ivector2;

typedef union __attribute__((aligned(16))) s_vector3
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	float	xyz[4];
}	t_vector3;

typedef union __attribute__((aligned(16))) s_ivector3
{
	struct
	{
		int	x;
		int	y;
		int	z;
	};
	int	xyz[4];
}	t_ivector3;

typedef union __attribute__((aligned(16))) s_vector4
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

typedef union __attribute__((aligned(16))) s_ivector4
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

#endif