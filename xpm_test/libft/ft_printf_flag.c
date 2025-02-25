/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:55:14 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:04:44 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	simple_atoi(const char *str, int *i, int num)
{
	if (str[*i] == '-')
		return (0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + str[*i] - '0';
		++*i;
	}
	--*i;
	return (num);
}

int	check_has_flag(char c, t_flag *flag)
{
	if (c == '#')
		flag->sharp = 1;
	else if (c == '0')
		flag->zero = 1;
	else if (c == '-')
		flag->minus = 1;
	else if (c == ' ')
		flag->space = 1;
	else if (c == '+')
		flag->plus = 1;
	else
		return (0);
	return (1);
}

void	scan_for_flag(t_conv *munja, const char *str)
{
	int		i;
	int		str_len;

	i = 0;
	str += munja->start_idx;
	str_len = munja->end_idx - munja->start_idx;
	ft_memset(&(munja->flag), 0, sizeof(t_flag));
	while (++i < str_len)
	{
		if (check_has_flag(str[i], &(munja->flag)))
			;
		else if (str[i] == '.')
		{
			++i;
			munja->flag.use_p = 1;
			munja->flag.prec = simple_atoi(str, &i, munja->flag.prec);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			munja->flag.field = simple_atoi(str, &i, munja->flag.field);
	}
}
