/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:44 by sejjeong          #+#    #+#             */
/*   Updated: 2024/04/29 21:02:41 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
	{
		return (0);
	}
	count = 1;
	while (*s1 == *s2 && *s1 != '\0' && count < n)
	{
		++s1;
		++s2;
		++count;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
