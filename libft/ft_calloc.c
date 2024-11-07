/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:39:17 by sejjeong          #+#    #+#             */
/*   Updated: 2024/02/29 22:18:13 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	count;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	count = nmemb * size;
	if (count / size != nmemb)
		return (NULL);
	p = malloc(count);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count);
	return (p);
}
