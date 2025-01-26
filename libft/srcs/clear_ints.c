/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:42:56 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 15:48:42 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	clear_ints(int **ints, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ints[i]);
		++i;
	}
	free(ints);
}
