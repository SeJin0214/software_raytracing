/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:41:09 by yuna              #+#    #+#             */
/*   Updated: 2024/03/06 09:31:13 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n);
static void	fill_str(char *str, int n, int index);

char	*ft_itoa(int n)
{
	int		index;
	char	*str;

	index = num_length(n) + 1;
	str = (char *)malloc(sizeof(char) * index);
	if (str == 0)
		return (NULL);
	str[0] = '-';
	str[--index] = '\0';
	fill_str(str, n, index);
	return (str);
}

static int	num_length(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		len = num_length(n * -1) + 1;
	}
	else if (n >= 10)
		len = num_length(n / 10) + 1;
	return (len);
}

static void	fill_str(char *str, int n, int index)
{
	if (n < 0)
	{
		if (n > -10)
			str[--index] = n * -1 + '0';
		else
		{
			str[--index] = n % 10 * -1 + '0';
			n = n / 10 * -1;
		}
	}
	if (n >= 0)
	{
		while (n >= 10)
		{
			str[--index] = n % 10 + '0';
			n = n / 10;
		}
		str[--index] = n + '0';
	}
}
