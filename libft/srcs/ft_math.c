/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:31 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:58:33 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_min(int num0, int num1)
{
	if (num0 > num1)
	{
		return (num1);
	}
	else
	{
		return (num0);
	}
}

int	get_max(int num0, int num1)
{
	if (num0 > num1)
	{
		return (num0);
	}
	else
	{
		return (num1);
	}
}

int	get_abs(int num0, int num1)
{
	int	res;

	res = num0 - num1;
	if (res < 0)
	{
		res *= -1;
	}
	return (res);
}
