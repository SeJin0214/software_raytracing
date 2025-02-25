/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:27:26 by yuna              #+#    #+#             */
/*   Updated: 2024/06/15 16:58:11 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_mem(char *dst, void *src)
{
	int		bits;
	size_t	idx;

	bits = 64;
	idx = 0;
	while (bits && idx < VOID_POINTER_SIZE)
	{
		bits -= 4;
		dst[idx] = "0123456789abcdef"[((size_t)src >> bits) & 0xf];
		++idx;
	}
}

int	print_address(void *ptr, t_flag f)
{
	char	str[VOID_POINTER_SIZE + 1];
	int		cnt;
	int		len;
	int		skip_zero;

	if (ptr == 0)
	{
		cnt = repeat_char(' ', f.field, 5, !f.minus);
		cnt += write(1, "(nil)", 5);
		cnt += repeat_char(' ', f.field, 5, f.minus);
	}
	else
	{
		skip_zero = 0;
		ft_memset(str, 0, VOID_POINTER_SIZE + 1);
		convert_mem(str, ptr);
		while (str[skip_zero] == '0')
			++skip_zero;
		len = ft_strlen(str + skip_zero);
		cnt = repeat_char(' ', f.field, len + 2, !f.minus);
		cnt += write(1, "0x", 2);
		cnt += write(1, str + skip_zero, len);
		cnt += repeat_char(' ', f.field, len + 2, f.minus);
	}
	return (cnt);
}

int	uint_to_hex(unsigned int num, char *str, char conversion, int zero_x)
{
	const char	hex[] = "0123456789abcdef";
	int			i;

	i = 12;
	while (num >= 16)
	{
		str[i] = hex[num % 16];
		num = num / 16;
		--i;
	}
	str[i] = hex[num];
	--i;
	if (zero_x)
	{
		str[0] = '0';
		str[1] = conversion;
	}
	str_toupper(str, i + 1, conversion);
	return (i);
}

int	print_hex_write_space(int len, t_flag f, int sharp, int condition)
{
	int	cnt;

	cnt = 0;
	if (len < f.prec)
		cnt += repeat_char(' ', f.field, f.prec + sharp, condition);
	else
		cnt += repeat_char(' ', f.field, len + sharp, condition);
	return (cnt);
}

int	print_hex(unsigned int num, t_flag f, char conversion)
{
	char	str[14];
	int		i;
	int		len;
	int		cnt;
	int		sharp;

	cnt = 0;
	ft_memset(str, 0, 14);
	sharp = (f.sharp && num) * 2;
	i = uint_to_hex(num, str, conversion, sharp);
	len = ft_strlen(str + i + 1);
	if (f.use_p && !f.prec && num == 0)
		return (cnt + repeat_char(' ', f.field, 0, 1));
	else if (f.use_p && !f.prec)
		cnt += repeat_char(' ', f.field, len, !f.minus);
	if (!f.zero || (f.zero && f.use_p && f.prec < f.field))
		cnt += print_hex_write_space(len, f, sharp, !f.minus);
	cnt += write(1, str, sharp);
	cnt += repeat_char('0', f.prec, len, 1);
	if (!f.use_p)
		cnt += repeat_char('0', f.field, len + sharp, !f.minus && f.zero);
	cnt += write(1, str + i + 1, len);
	cnt += print_hex_write_space(len, f, sharp, f.minus);
	return (cnt);
}
