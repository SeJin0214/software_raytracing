/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:53:03 by sejjeong          #+#    #+#             */
/*   Updated: 2024/03/07 20:08:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	trim_cnt;
	size_t	len;
	char	*res;
	char	*p;

	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
	{
		++s1;
	}
	len = ft_strlen(s1);
	p = (char *)s1 + len - 1;
	trim_cnt = 0;
	while (s1 <= p && ft_strchr(set, *p) != NULL)
	{
		++trim_cnt;
		--p;
	}
	len -= trim_cnt;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}
