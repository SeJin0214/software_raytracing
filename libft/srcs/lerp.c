/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:41:02 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 19:16:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lerp_int(int from, int to, float t)
{
	int	result;

	result = (1.0f - t) * from + t * to;
	return (result);
}

float	lerp(const float a, const float b, const float t)
{
	return ((1.0f - t) * a + t * b);
}
