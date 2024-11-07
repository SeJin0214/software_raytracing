/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:13:59 by sejjeong          #+#    #+#             */
/*   Updated: 2024/03/01 15:43:00 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (void *)0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			p = (char *)s;
		}
		++s;
	}
	if (c == '\0')
	{
		p = (char *)s;
	}
	return (p);
}
