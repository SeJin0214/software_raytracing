/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:40 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:58:42 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_data		data;
	int			count;

	if (write(1, "", 0) == -1 || str == NULL)
		return (-1);
	ft_memset(&data, 0, sizeof(t_data));
	va_start(ap, str);
	{
		count = try_format_str(&str, ap, &data);
	}
	va_end(ap);
	return (count);
}

int	try_format_str(const char **str, va_list ap, t_data *data)
{
	int		count;
	int		temp;

	count = 0;
	while (**str != '\0')
	{
		ft_memset(data, 0, sizeof(t_data));
		if (**str == '%')
		{
			++*str;
			check_flags(str, data);
			check_width(str, ap, data);
			check_precision(str, ap, data);
			temp = check_conversion(str, ap, data);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			count += write(1, *str, 1);
		}
		++*str;
	}
	return (count);
}

void	check_flags(const char **str, t_data *data)
{
	while (1)
	{
		if (**str == '-')
			data->t_state.state_minus = true;
		else if (**str == '+')
			data->t_state.state_plus = true;
		else if (**str == ' ')
			data->t_state.state_space = true;
		else if (**str == '0')
			data->t_state.state_zero = true;
		else if (**str == '#')
			data->t_state.state_number_sign = true;
		else
			break ;
		++*str;
	}
}

void	check_width(const char **str, va_list ap, t_data *data)
{
	if (**str == '*')
	{
		data->width = va_arg(ap, int);
		++*str;
		return ;
	}
	while (ft_isdigit(**str))
	{
		data->width *= 10;
		data->width += **str - '0';
		++*str;
	}
}

void	check_precision(const char **str, va_list ap, t_data *data)
{
	if (**str != '.')
	{
		return ;
	}
	++*str;
	data->t_state.state_precision = true;
	if (**str == '*')
	{
		data->precision = va_arg(ap, int);
		++*str;
		return ;
	}
	while (ft_isdigit(**str))
	{
		data->precision *= 10;
		data->precision += **str - '0';
		++*str;
	}
}
