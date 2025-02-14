/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:29 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 16:50:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "libft.h"
#include "vector.h"
#include "world_bonus.h"
#include "solid_shape_bonus.h"

void	destroy_shapes(t_array_list *list)
{
	size_t			i;
	t_solid_shape	**shape;

	i = 0;
	while (i < list->count)
	{
		shape = list->get_element_or_null(list, i);
		(*shape)->delete((*shape));
		++i;
	}
	free(list->list);
	list->list = NULL;
}
