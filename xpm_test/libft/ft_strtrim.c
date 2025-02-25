/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:01:40 by yuna              #+#    #+#             */
/*   Updated: 2024/03/13 22:19:57 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		end_idx;

	while (*s1 && ft_strchr(set, *s1) != NULL)
		++s1;
	if (*s1 == 0)
		return (ft_strdup(""));
	end_idx = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end_idx]) != NULL)
		--end_idx;
	res = (char *)malloc(sizeof(char) * (end_idx + 2));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, end_idx + 2);
	return (res);
}
