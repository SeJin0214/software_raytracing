/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:27:38 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/24 09:23:52 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# define PI 3.141592f


inline float	get_radian(const float degree)
{
	return (degree * PI / 180);
}

inline int	get_min(int num0, int num1)
{
	if (num0 > num1)
	{
		return (num1);
	}
	return (num0);
}

inline int	get_max(int num0, int num1)
{
	if (num0 >= num1)
	{
		return (num0);
	}
	return (num1);
}

inline int	lerp_int(const int from, const int to, const float t)
{
	int	result;

	result = (1.0f - t) * from + t * to;
	return (result);
}

inline float	lerp(const float a, const float b, const float t)
{
	return ((1.0f - t) * a + t * b);
}

#endif