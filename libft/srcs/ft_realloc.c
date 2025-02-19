/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:59 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/19 16:03:51 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "ft_math.h"

void	*ft_realloc(void *pa, size_t src_size, size_t dest_size)
{
	void	*pa_res;
	int		min_size;

	pa_res = malloc(dest_size);
	if (pa_res == NULL)
	{
		ft_assert(false, "fail, ft_realloc->malloc");
		return (NULL);
	}
	ft_memset(pa_res, 0, dest_size);
	min_size = get_min(src_size, dest_size);
	pa_res = ft_memcpy(pa_res, pa, min_size);
	free(pa);
	return (pa_res);
}
