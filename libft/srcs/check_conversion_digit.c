/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:57:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/19 16:02:51 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "ft_math.h"
#include <stdio.h>

int	convert_digit(t_data *data, const char *num)
{
	int			count;
	int			max;
	const int	flag = get_count_by_flag(data);

	if (data->t_state.state_minus)
	{
		count = write_basic(data, num);
		count += write_repeated_char(' ', 1, data->width - count);
		return (count);
	}
	if (data->t_state.state_precision)
	{
		max = get_max(data->precision, flag + get_ascii_digit(num));
		if (data->precision < flag + get_ascii_digit(num))
			count = write_repeated_char(' ', 1, data->width - \
					get_max(flag + data->precision, max));
		else
			count = write_repeated_char(' ', 1, data->width - max - flag);
		count += write_basic(data, num);
		return (count);
	}
	count = convert_zero_flag(data, num);
	count += ft_putstr_fd(num, 1);
	return (count);
}

int	write_basic(t_data *data, const char *num)
{
	int	count;
	int	length;

	count = write_special_flag(data);
	length = data->precision - get_ascii_digit(num);
	count += write_repeated_char('0', 1, length);
	if (data->t_state.state_precision == false \
		|| data->precision != 0 || *num != '0')
		count += ft_putstr_fd(num, 1);
	return (count);
}

int	convert_zero_flag(t_data *data, const char *num)
{
	int			count;
	int			length;
	const int	digit = get_ascii_digit(num);
	const int	flag_count = get_count_by_flag(data);

	count = 0;
	if (data->t_state.state_zero == false)
	{
		length = data->width - digit - flag_count;
		count += write_repeated_char(' ', 1, length);
		count += write_special_flag(data);
	}
	else
	{
		count = write_special_flag(data);
		length = data->width - digit - count;
		count += write_repeated_char('0', 1, length);
	}
	return (count);
}

int	write_special_flag(t_data *data)
{
	int	count;

	count = 0;
	if (data->t_state.state_neg_decimal)
	{
		count += ft_putchar_fd('-', 1);
	}
	else if (data->t_state.state_plus)
	{
		count += ft_putchar_fd('+', 1);
	}
	else if (data->t_state.state_space)
	{
		count += ft_putchar_fd(' ', 1);
	}
	if (data->t_state.state_number_sign)
	{
		if (data->t_state.state_upper_hexa == false)
			count += ft_putstr_fd("0x", 1);
		else
			count += ft_putstr_fd("0X", 1);
	}
	return (count);
}

int	get_count_by_flag(t_data *data)
{
	int	count;

	count = (data->t_state.state_neg_decimal || data->t_state.state_plus \
			|| data->t_state.state_space) \
			+ data->t_state.state_number_sign * 2;
	return (count);
}
