/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:04 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:05 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	sprint_long_hexa(char *dest, unsigned long nbr, const char *base16)
{
	size_t	shift;
	size_t	i;
	bool	is_zero;

	ft_memset(dest, 0, MAX_DIGIT_LONG_HEXA + 1);
	shift = BIT_SIZE64;
	is_zero = true;
	i = 0;
	while (shift != 0)
	{
		shift -= 4;
		dest[i] = base16[(nbr >> shift) & 0xf];
		if (dest[i] == '0' && is_zero)
		{
			continue ;
		}
		++i;
		is_zero = false;
	}
}

size_t	get_ascii_digit(const char *dest)
{
	size_t	i;

	i = 0;
	if (*dest == '-')
	{
		++dest;
	}
	else if (*dest == '0')
	{
		return (1);
	}
	while (dest[i] != '\0' && ((dest[i] >= '0' && dest[i] <= '9') \
			|| (dest[i] >= 'a' && dest[i] <= 'z') \
			|| (dest[i] >= 'A' && dest[i] <= 'Z')))
	{
		++i;
	}
	return (i);
}
