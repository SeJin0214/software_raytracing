/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:06 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:58:09 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_conversion_p(void *address, t_data *data)
{
	int		count;
	char	buffer[MAX_DIGIT_LONG_HEXA + 1];

	if (address == NULL)
	{
		return (format_conversion_s("(nil)", data));
	}
	sprint_long_hexa(buffer, (unsigned long)address, "0123456789abcdef");
	data->t_state.state_number_sign = true;
	count = convert_digit(data, buffer);
	return (count);
}

int	format_conversion_d_i(int num, t_data *data)
{
	int		count;
	char	buffer[MAX_DIGIT_INT + 1];

	if (num < 0)
	{
		data->t_state.state_neg_decimal = true;
	}
	data->t_state.state_number_sign = false;
	sprint_abs_toa(buffer, num);
	count = convert_digit(data, buffer);
	return (count);
}

int	format_conversion_u(unsigned int num, t_data *data)
{
	int		count;
	char	buffer[MAX_DIGIT_INT + 1];

	data->t_state.state_number_sign = false;
	data->t_state.state_plus = false;
	data->t_state.state_space = false;
	sprint_uitoa(buffer, num);
	count = convert_digit(data, buffer);
	return (count);
}

int	format_conversion_x(unsigned int num, t_data *data)
{
	int		count;
	char	buffer[MAX_DIGIT_LONG_HEXA + 1];

	if (num == 0)
	{
		data->t_state.state_number_sign = false;
	}
	data->t_state.state_plus = false;
	data->t_state.state_space = false;
	sprint_long_hexa(buffer, (unsigned long)num, "0123456789abcdef");
	count = convert_digit(data, buffer);
	return (count);
}

int	format_conversion_upper_x(unsigned int num, t_data *data)
{
	int		count;
	char	buffer[MAX_DIGIT_LONG_HEXA + 1];

	if (num == 0)
	{
		data->t_state.state_number_sign = false;
	}
	data->t_state.state_plus = false;
	data->t_state.state_space = false;
	data->t_state.state_upper_hexa = true;
	sprint_long_hexa(buffer, (unsigned long)num, "0123456789ABCDEF");
	count = convert_digit(data, buffer);
	return (count);
}
