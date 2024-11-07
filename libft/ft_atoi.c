/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:15:06 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/07 19:32:11 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#define INT_MAX_LENGTH 11

int	ft_atoi(const char *nptr)
{
	return ((int)ft_atol(nptr));
}

long	ft_atol(const char *nptr)
{
	int		neg_flag;
	long	res;

	neg_flag = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		++nptr;
	if (*nptr == '+')
		++nptr;
	else if (*nptr == '-')
	{
		neg_flag *= -1;
		++nptr;
	}
	res = 0;
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		res *= 10;
		res += *nptr - '0';
		++nptr;
	}
	if (neg_flag == -1)
		res *= neg_flag;
	return (res);
}

bool	try_atoi(const char *nums, int *out_result)
{
	char	sign;

	sign = *nums;
	*out_result = 0;
	if (*nums == '+' || *nums == '-')
		++nums;
	while (*nums != '\0' && *nums == '0')
		++nums;
	if (ft_strlen(nums) > INT_MAX_LENGTH)
		return (false);
	if (ft_atol(nums) > INT_MAX)
		return (false);
	while (*nums != '\0')
	{
		if (ft_isdigit(*nums) == false)
		{
			*out_result = 0;
			return (false);
		}
		*out_result = *out_result * 10 + *nums - '0';
		++nums;
	}
	if (sign == '-')
		*out_result *= -1;
	return (true);
}