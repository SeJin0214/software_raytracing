/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:25:08 by yuna              #+#    #+#             */
/*   Updated: 2024/05/08 09:53:22 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
			return (str + i);
		++i;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i + 1 < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		++i;
	}
	return (str1[i] - str2[i]);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	i = 0;
	if (dest == src)
		return (dest);
	ch_dst = (unsigned char *)dest;
	ch_src = (unsigned char *)src;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		++i;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ch_src;
	unsigned char	*ch_dest;

	if (src == dest || n == 0)
		return (dest);
	ch_src = (unsigned char *)src;
	ch_dest = (unsigned char *)dest;
	if (src < dest)
	{
		while (n > 0)
		{
			ch_dest[n - 1] = ch_src[n - 1];
			--n;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		++i;
	}
	return (s);
}
