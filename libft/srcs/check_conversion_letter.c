/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion_letter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:01 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:58:03 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	check_conversion(const char **str, va_list ap, t_data *data)
{
	int	count;

	if (**str == 'c')
		count = format_conversion_c(va_arg(ap, int), data);
	else if (**str == 's')
		count = format_conversion_s(va_arg(ap, char *), data);
	else if (**str == 'p')
		count = format_conversion_p(va_arg(ap, void *), data);
	else if (**str == 'd' || **str == 'i')
		count = format_conversion_d_i(va_arg(ap, int), data);
	else if (**str == 'u')
		count = format_conversion_u(va_arg(ap, unsigned int), data);
	else if (**str == 'x')
		count = format_conversion_x(va_arg(ap, unsigned int), data);
	else if (**str == 'X')
		count = format_conversion_upper_x(va_arg(ap, unsigned int), data);
	else if (**str == '%')
		count = format_conversion_percent();
	else
		return (-1);
	return (count);
}

int	format_conversion_c(char ch, t_data *data)
{
	int	count;

	count = 0;
	if (data->width <= 0)
	{
		count += ft_putchar_fd(ch, 1);
		return (count);
	}
	if (data->t_state.state_minus)
	{
		count += ft_putchar_fd(ch, 1);
		count += write_repeated_char(' ', 1, data->width - count);
	}
	else
	{
		count += write_repeated_char(' ', 1, data->width - 1);
		count += ft_putchar_fd(ch, 1);
	}
	return (count);
}

int	format_conversion_s(char *arg_str, t_data *data)
{
	int			count;

	if (arg_str == NULL)
	{
		arg_str = "(null)";
	}
	if (data->t_state.state_precision && ft_strcmp(arg_str, "(nil)") != 0)
	{
		if (ft_strcmp(arg_str, "(null)") == 0 && data->precision < 6)
			arg_str = "";
		count = convert_flag_s_width(data, arg_str, data->precision);
	}
	else
	{
		count = convert_flag_s_width(data, arg_str, ft_strlen(arg_str));
	}
	return (count);
}

int	convert_flag_s_width(t_data *data, const char *arg_str, const int length)
{
	int			count;
	const int	arg_len = ft_strlen(arg_str);

	count = 0;
	if (data->width <= 0)
	{
		count += print_strn_fd(arg_str, 1, length);
		return (count);
	}
	if (data->t_state.state_minus)
	{
		count += print_strn_fd(arg_str, 1, length);
		count += write_repeated_char(' ', 1, data->width - count);
	}
	else
	{
		count = get_min(length, arg_len);
		count += write_repeated_char(' ', 1, data->width - count);
		print_strn_fd(arg_str, 1, length);
	}
	return (count);
}

int	format_conversion_percent(void)
{
	return (ft_putchar_fd('%', 1));
}
