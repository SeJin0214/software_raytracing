/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:10:23 by sejjeong          #+#    #+#             */
/*   Updated: 2024/05/25 21:25:51 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	total_len;
	char	*str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str, s1, total_len + 1);
	ft_strlcat(str, s2, total_len + 1);
	return (str);
}

char	*ft_strsjoin(const char **strs, size_t n)
{
	size_t	total_len;
	char	*str;
	size_t	i;

	i = 0;
	total_len = 0;
	while (i < n)
	{
		total_len += ft_strlen(strs[i]);
		++i;
	}
	str = malloc(sizeof(char) * (total_len + 1));
	ft_memset(str, 0, total_len + 1);
	i = 0;
	while (i < n)
	{
		ft_strlcat(str, strs[i], total_len + 1);
		++i;
	}
	return (str);
}
