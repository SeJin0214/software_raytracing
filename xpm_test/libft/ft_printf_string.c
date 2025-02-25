/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:30:12 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:04:34 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(unsigned char c, t_flag flag)
{
	int	cnt;

	cnt = repeat_char(' ', flag.field, 1, !flag.minus);
	cnt += write(1, &c, 1);
	cnt += repeat_char(' ', flag.field, 1, flag.minus);
	return (cnt);
}

int	print_string(const char *str, t_flag flag)
{
	int		cnt;
	size_t	len;

	cnt = 0;
	if (str == 0)
	{
		str = "(null)";
		len = ft_strlen(str);
		if (flag.use_p && (size_t)flag.prec < len)
			len = 0;
		cnt += repeat_char(' ', flag.field, len, !flag.minus);
		if (!flag.use_p || (flag.use_p && (size_t)flag.prec >= len))
			cnt += write(1, str, len);
		cnt += repeat_char(' ', flag.field, len, flag.minus);
		return (cnt);
	}
	len = ft_strlen(str);
	if (flag.use_p && (size_t)flag.prec < len)
		len = flag.prec;
	cnt += repeat_char(' ', flag.field, len, !flag.minus);
	cnt += write(1, str, len);
	cnt += repeat_char(' ', flag.field, len, flag.minus);
	return (cnt);
}

int	print_percent(void)
{
	return (write(1, "%", 1));
}
