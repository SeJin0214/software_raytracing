/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:27:28 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:04:23 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_percent(const char *str, t_conv *munja, int *cnt);
int		find_conversion(const char *str, t_conv *munja);
int		ft_strchr_idx(int find_char);
int		switch_c(t_conv *munja, va_list *ptr);

int	ft_printf(const char *format, ...)
{
	int			cnt;
	int			i;
	va_list		ptr;
	t_conv		munja;

	if (format == NULL)
		return (-1);
	cnt = 0;
	i = 0;
	va_start(ptr, format);
	while (1)
	{
		if (find_percent(format + i, &munja, &cnt) == -1)
			break ;
		if (find_conversion(format + i, &munja) == -1)
		{
			i = i + munja.start_idx + 1;
			break ;
		}
		scan_for_flag(&munja, format + i);
		cnt += switch_c(&munja, &ptr);
		i = i + munja.end_idx + 1;
	}
	va_end(ptr);
	return (cnt);
}

int	switch_c(t_conv *munja, va_list *ptr)
{
	int	cnt;

	cnt = 0;
	if (munja->conversion == CONVERSION_C)
		cnt = print_char(va_arg(*ptr, int), munja->flag);
	else if (munja->conversion == CONVERSION_S)
		cnt = print_string(va_arg(*ptr, const char *), munja->flag);
	else if (munja->conversion == CONVERSION_P)
		cnt = print_address(va_arg(*ptr, void *), munja->flag);
	else if (munja->conversion == CONVERSION_D
		|| munja->conversion == CONVERSION_I)
		cnt = print_int(va_arg(*ptr, int), munja->flag);
	else if (munja->conversion == CONVERSION_U)
		cnt = print_uint(va_arg(*ptr, unsigned int), munja->flag);
	else if (munja->conversion == CONVERSION_LOWER_X)
		cnt = print_hex(va_arg(*ptr, unsigned int), munja->flag, 'x');
	else if (munja->conversion == CONVERSION_X)
		cnt = print_hex(va_arg(*ptr, unsigned int), munja->flag, 'X');
	else if (munja->conversion == CONVERSION_PERCENT)
		cnt = print_percent();
	return (cnt);
}

int	find_percent(const char *str, t_conv *munja, int *all_cnt)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != '%')
	{
		write(1, str + cnt, 1);
		++cnt;
	}
	*all_cnt += cnt;
	if (!str[cnt])
	{
		munja->start_idx = -1;
		return (-1);
	}
	else
		munja->start_idx = cnt;
	return (cnt);
}

int	find_conversion(const char *str, t_conv *munja)
{
	int		i;

	i = munja->start_idx + 1;
	while (str[i])
	{
		munja->conversion = ft_strchr_idx(str[i]);
		if (munja->conversion != -1)
		{
			munja->end_idx = i;
			return (0);
		}
		++i;
	}
	munja->end_idx = -1;
	return (-1);
}

int	ft_strchr_idx(int find_char)
{
	const char	conversion[] = "cspdiuxX%";
	int			i;

	i = 0;
	while (conversion[i])
	{
		if (conversion[i] == find_char)
			return (i);
		++i;
	}
	return (-1);
}
