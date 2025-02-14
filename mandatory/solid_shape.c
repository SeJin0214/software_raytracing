/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:29 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 21:13:54 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "libft.h"
#include "world.h"
#include "solid_shape.h"
#include "vector.h"

void	move_shape(void *obj, t_action action)
{
	t_solid_shape	*shape;

	shape = obj;
	if (action == ACTION_OBJECT_MOVE_UP)
	{
		shape->coordinates.y += 1.0f;
	}
	else if (action == ACTION_OBJECT_MOVE_DOWN)
	{
		shape->coordinates.y -= 1.0f;
	}
	else if (action == ACTION_OBJECT_MOVE_LEFT)
	{
		shape->coordinates.x -= 1.0f;
	}
	else if (action == ACTION_OBJECT_MOVE_RIGHT)
	{
		shape->coordinates.x += 1.0f;
	}
	else if (action == ACTION_OBJECT_MOVE_FRONT)
	{
		shape->coordinates.z += 1.0f;
	}
	else if (action == ACTION_OBJECT_MOVE_BACK)
	{
		shape->coordinates.z -= 1.0f;
	}
}

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
