/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:18 by sejjeong          #+#    #+#             */
/*   Updated: 2024/03/07 20:07:08 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	min_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_calloc(1, 1));
	else if (len == 0)
		return (ft_calloc(1, 1));
	s_len = ft_strlen(s + start);
	if (len < s_len)
		min_len = len;
	else
		min_len = s_len;
	res = malloc(sizeof(char) * (min_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, min_len + 1);
	return (res);
}
