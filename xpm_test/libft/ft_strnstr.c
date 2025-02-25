/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:38:46 by yuna              #+#    #+#             */
/*   Updated: 2024/05/28 11:32:48 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_strchr_index(const char *s, int i, int c);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		little_len;
	int		found_index;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	little_len = ft_strlen(little);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	while (i < len && big[i])
	{
		found_index = find_strchr_index(big, i, little[0]);
		if (found_index == -1 || (size_t)found_index + little_len > len)
			return (NULL);
		i = found_index;
		j = 0;
		while (big[i + j] == little[j])
			if (little[++j] == '\0')
				return ((char *)(big + i));
		++i;
	}
	return (NULL);
}

static int	find_strchr_index(const char *s, int i, int c)
{
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
