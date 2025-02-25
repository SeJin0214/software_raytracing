/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:44:57 by yuna              #+#    #+#             */
/*   Updated: 2024/03/06 10:07:52 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process_if_minus(int n, char *char_num, int *i, char *is_minus);
static int	cat_minus(char is_minus, char *char_num, int i);

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	char	is_minus;
	int		i;

	str[11] = '\0';
	i = 10;
	n = process_if_minus(n, str, &i, &is_minus);
	if (n >= 0)
	{
		while (n >= 10)
		{
			str[i] = n % 10 + '0';
			n = n / 10;
			--i;
		}
		str[i] = n + '0';
		--i;
	}
	i = cat_minus(is_minus, str, i);
	write(fd, str + i + 1, ft_strlen(str + i + 1));
}

static int	process_if_minus(int n, char *char_num, int *i, char *is_minus)
{
	if (n < 0)
	{
		if (n > -10)
			char_num[*i] = n * -1 + '0';
		else
		{
			char_num[*i] = n % 10 * -1 + '0';
			n = n / 10 * -1;
		}
		--(*i);
		*is_minus = 1;
	}
	else
		*is_minus = 0;
	return (n);
}

static int	cat_minus(char is_minus, char *char_num, int i)
{
	if (is_minus)
	{
		char_num[i] = '-';
		return (i - 1);
	}
	return (i);
}
