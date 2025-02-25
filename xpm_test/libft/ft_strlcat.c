/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:41:47 by yuna              #+#    #+#             */
/*   Updated: 2024/03/06 10:28:26 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		cnt_src;
	int		dst_len;
	int		src_len;

	i = 0;
	cnt_src = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (size < i + 1)
		return (size + src_len);
	while (src[cnt_src] && i + 1 < size)
	{
		dst[i] = src[cnt_src];
		++i;
		++cnt_src;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
