/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:58:48 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:04:37 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_sign(int *num, char *char_num, int *i, t_flag f)
{
	if (*num < 0)
	{
		char_num[0] = '-';
		if (*num > -10)
			*num = -*num;
		else
		{
			char_num[*i] = *num % 10 * -1 + '0';
			*num = *num / 10 * -1;
			--*i;
		}
	}
	else if (f.plus)
		char_num[0] = '+';
	else if (f.space)
		char_num[0] = ' ';
	else
		return (0);
	return (1);
}

void	print_int_fill_string(int num, char *str, int *i)
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

int	print_int_main_write(char has_sign, char *str, int i, t_flag f)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = ft_strlen(str + i + 1);
	if (has_sign)
		cnt += write(1, str, 1);
	cnt += repeat_char('0', f.prec, len, 1);
	if (!f.use_p)
		cnt += repeat_char('0', f.field, len + has_sign, !f.minus && f.zero);
	cnt += write(1, str + i + 1, len);
	if (len < f.prec)
		cnt += repeat_char(' ', f.field, f.prec + has_sign, f.minus);
	else
		cnt += repeat_char(' ', f.field, len + has_sign, f.minus);
	return (cnt);
}

int	print_int_write_space(int len, t_flag f, int has_sign)
{
	int	cnt;

	cnt = 0;
	if (!f.zero || (f.zero && f.use_p && f.prec < f.field))
	{
		if (len < f.prec)
			cnt += repeat_char(' ', f.field, f.prec + has_sign, !f.minus);
		else
			cnt += repeat_char(' ', f.field, len + has_sign, !f.minus);
	}
	return (cnt);
}

int	print_int(int num, t_flag f)
{
	char	str[INT_STRING_LEN];
	char	has_sign;
	int		i;
	int		cnt;

	cnt = 0;
	str[INT_STRING_LEN - 1] = '\0';
	i = INT_STRING_LEN - 2;
	has_sign = process_sign(&num, str, &i, f);
	print_int_fill_string(num, str, &i);
	if (f.use_p && !f.prec && num == 0)
	{
		cnt += repeat_char(' ', f.field - has_sign, 0, 1);
		cnt += write(1, str, has_sign);
		return (cnt);
	}
	else if (f.use_p && !f.prec)
		cnt += repeat_char(' ', f.field,
				ft_strlen(str + i + 1) + has_sign, !f.minus);
	else
		cnt += print_int_write_space(ft_strlen(str + i + 1), f, has_sign);
	cnt += print_int_main_write(has_sign, str, i, f);
	return (cnt);
}
