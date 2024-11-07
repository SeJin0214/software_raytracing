/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:45 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:48 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	sprint_itoa(char *dest, int num)
{
	if (num == 0)
	{
		*dest = '0';
		*(dest + 1) = '\0';
		return ;
	}
	if (num < 0)
	{
		*dest++ = '-';
	}
	sprint_abs_toa(dest, num);
}

void	sprint_uitoa(char *dest, unsigned int num)
{
	char			*p;
	const size_t	len = get_digit(num);

	if (num == 0)
	{
		*dest = '0';
		*(dest + 1) = '\0';
		return ;
	}
	p = dest + len;
	*p = '\0';
	while (dest < p)
	{
		--p;
		*p = num % 10 + '0';
		num /= 10;
	}
}

void	sprint_abs_toa(char *dest, int num)
{
	long			n;
	char			*p;
	const size_t	len = get_digit(num);

	if (num == 0)
	{
		*dest = '0';
		*(dest + 1) = '\0';
		return ;
	}
	n = num;
	if (n < 0)
	{
		n *= -1;
	}
	p = dest + len;
	*p = '\0';
	while (dest < p)
	{
		--p;
		*p = n % 10 + '0';
		n /= 10;
	}
}
