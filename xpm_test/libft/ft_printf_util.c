/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:29:20 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:20:06 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	repeat_char(char chr, int repeat, int str_len, int condition)
{
	int	i;

	i = 0;
	while (i + str_len < repeat && condition)
	{
		write(1, &chr, 1);
		++i;
	}
	return (i);
}

void	str_toupper(char *str, int i, char conversion)
{
	if (conversion == 'X')
	{
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] + 'A' - 'a';
			++i;
		}
	}
}
