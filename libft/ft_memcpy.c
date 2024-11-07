/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:07:31 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 16:14:14 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;
	size_t	i;

	if (n == 0)
		return (dest);
	p = (char *)dest;
	if (dest - src >= 0)
	{
		i = n;
		while (i-- > 0)
			p[i] = ((const char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			p[i] = ((const char *)src)[i];
			++i;
		}
	}
	return (dest);
}
