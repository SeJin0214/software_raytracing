/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:00:11 by yuna              #+#    #+#             */
/*   Updated: 2024/03/06 09:18:21 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = 0;
	if (size != 0 && size * nmemb / size != nmemb)
		return (result);
	result = malloc(size * nmemb);
	if (result == NULL)
		return (NULL);
	if (size * nmemb == 0)
		*((char *)result) = 0;
	ft_memset(result, 0, size * nmemb);
	return (result);
}
