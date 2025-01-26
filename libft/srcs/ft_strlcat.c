/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:58:44 by sejjeong          #+#    #+#             */
/*   Updated: 2024/02/28 21:22:34 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	count;
	size_t	dest_len;
	size_t	src_len;
	char	*dest_p;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dest_p = dest;
	count = 0;
	if ((dest == NULL && n == 0) || dest_len >= n)
		return (src_len + n);
	while (*dest_p != '\0')
	{
		++dest_p;
		++count;
	}
	while (*src != '\0' && count + 1 < n)
	{
		*dest_p++ = *src++;
		++count;
	}
	*dest_p = '\0';
	return (dest_len + src_len);
}
