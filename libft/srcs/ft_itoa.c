/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:30:20 by sejjeong          #+#    #+#             */
/*   Updated: 2024/06/02 17:41:08 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*get_nums(long n);

char	*ft_itoa(int n)
{
	return (ft_ltoa(n));
}

char	*ft_uitoa(unsigned int n)
{
	return (ft_ltoa(n));
}

char	*ft_ltoa(long n)
{
	char	*res;

	if (n == 0)
	{
		res = malloc(sizeof(char) * 2);
		*res = '0';
		*(res + 1) = '\0';
		return (res);
	}
	res = get_nums(n);
	return (res);
}

size_t	get_digit(long n)
{
	size_t	length;

	length = 0;
	while (n != 0)
	{
		++length;
		n /= 10;
	}
	return (length);
}

static char	*get_nums(long n)
{
	char			*res;
	char			*res_first;
	char			*res_last;
	const size_t	len = get_digit(n);

	res = malloc(sizeof(char) * (len + 1 + (n < 0)));
	if (res == NULL)
		return (NULL);
	res_first = res;
	res_last = res + len + (n < 0);
	*res_last = '\0';
	if (n < 0)
	{
		*res_first++ = '-';
		*res_last-- = n % -10 + '0';
		n /= -10;
	}
	while (res_first <= --res_last)
	{
		*res_last = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
