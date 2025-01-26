/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:47:46 by sejjeong          #+#    #+#             */
/*   Updated: 2024/08/06 14:54:22 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	swap_memory(void *data1, void *data2, size_t size)
{
	unsigned char	*temp;

	temp = malloc(sizeof(unsigned char) * size);
	ft_memmove(temp, data1, size);
	ft_memmove(data1, data2, size);
	ft_memmove(data2, temp, size);
	free(temp);
}

void	swap_int(int *int1, int *int2)
{
	const int	temp = *int1;

	*int1 = *int2;
	*int2 = temp;
}
