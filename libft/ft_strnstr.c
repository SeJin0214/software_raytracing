/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:48:48 by sejjeong          #+#    #+#             */
/*   Updated: 2024/08/29 16:18:23 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr_or_null(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	count = 0;
	little_len = ft_strlen(little);
	while (*big != '\0' && count + little_len <= len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
		{
			return ((char *)big);
		}
		++big;
		++count;
	}
	return (NULL);
}

char	*ft_strstr_or_null(const char *big, const char *little)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big != '\0')
	{
		if (ft_strncmp(big, little, little_len) == 0)
		{
			return ((char *)big);
		}
		++big;
	}
	return (NULL);
}
