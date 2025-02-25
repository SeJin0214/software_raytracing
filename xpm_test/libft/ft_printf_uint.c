/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:58:48 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:04:31 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint_fill_string(unsigned int num, char *str, int *i)
{
	while (num >= 10)
	{
		str[*i] = num % 10 + '0';
		num = num / 10;
		--*i;
	}
	str[*i] = num + '0';
	--*i;
}

int	print_uint_main_write(char *str, int len, int i, t_flag f)
{
	int	cnt;

	cnt = 0;
	cnt += repeat_char('0', f.prec, len, 1);
	cnt += repeat_char('0', f.field, len, !f.use_p && !f.minus && f.zero);
	cnt += write(1, str + i + 1, len);
	if (len < f.prec)
		cnt += repeat_char(' ', f.field, f.prec, f.minus);
	else
		cnt += repeat_char(' ', f.field, len, f.minus);
	return (cnt);
}

int	print_uint(unsigned int num, t_flag f)
{
	char	str[INT_STRING_LEN];
	int		i;
	int		len;
	int		cnt;

	cnt = 0;
	str[INT_STRING_LEN - 1] = '\0';
	i = INT_STRING_LEN - 2;
	print_uint_fill_string(num, str, &i);
	len = ft_strlen(str + i + 1);
	if (f.use_p && !f.prec)
	{
		if (num == 0)
			return (cnt + repeat_char(' ', f.field, 0, 1));
		else
			cnt += repeat_char(' ', f.field, len, !f.minus);
	}
	if (!f.zero || (f.zero && f.use_p && f.prec < f.field))
	{
		if (len < f.prec)
			cnt += repeat_char(' ', f.field, f.prec, !f.minus);
		else
			cnt += repeat_char(' ', f.field, len, !f.minus);
	}
	return (cnt + print_uint_main_write(str, len, i, f));
}
