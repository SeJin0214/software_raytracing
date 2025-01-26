/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:55:04 by sejjeong          #+#    #+#             */
/*   Updated: 2024/10/08 13:43:40 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	length;

	length = ft_strlen(s);
	p = malloc(sizeof(char) * (length + 1));
	if (p == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(p, s, length + 1);
	return (p);
}

char	*ft_strndup_malloc(const char *src, const size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0' && i < n)
	{
		res[i] = src[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
