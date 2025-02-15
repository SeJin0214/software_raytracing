/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:29 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 15:08:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "libft.h"
#include "world.h"
#include "solid_shape.h"
#include "vector.h"

void	move_shape(void *obj, const t_action action)
{
	t_solid_shape	*shape;

	shape = obj;
	if (action == ACTION_OBJECT_MOVE_UP)
		shape->coordinates = add_vector3(shape->coordinates, \
		shape->local_basis.row[Y]);
	else if (action == ACTION_OBJECT_MOVE_DOWN)
		shape->coordinates = subtract_vector3(shape->coordinates, \
		shape->local_basis.row[Y]);
	else if (action == ACTION_OBJECT_MOVE_LEFT)
		shape->coordinates = subtract_vector3(shape->coordinates, \
		shape->local_basis.row[X]);
	else if (action == ACTION_OBJECT_MOVE_RIGHT)
		shape->coordinates = add_vector3(shape->coordinates, \
		shape->local_basis.row[X]);
	else if (action == ACTION_OBJECT_MOVE_FRONT)
		shape->coordinates = add_vector3(shape->coordinates, \
		shape->local_basis.row[Z]);
	else if (action == ACTION_OBJECT_MOVE_BACK)
		shape->coordinates = subtract_vector3(shape->coordinates, \
		shape->local_basis.row[Z]);
}

void	rotate_shape(void *obj, const t_action action)
{
	t_solid_shape	*shape;

	shape = obj;
	// 나중에 변경
	if (action == ACTION_X_AXIS_ROTATING_OBJECT_CLOCKWISE)
		shape->coordinates = add_vector3(shape->coordinates, \
		shape->local_basis.row[Y]);
	else if (action == ACTION_X_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE)
		shape->coordinates = subtract_vector3(shape->coordinates, \
		shape->local_basis.row[Y]);
	else if (action == ACTION_Y_AXIS_ROTATING_OBJECT_CLOCKWISE)
		shape->coordinates = subtract_vector3(shape->coordinates, \
		shape->local_basis.row[X]);
	else if (action == ACTION_Y_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE)
		shape->coordinates = add_vector3(shape->coordinates, \
		shape->local_basis.row[X]);
	else if (action == ACTION_Z_AXIS_ROTATING_OBJECT_CLOCKWISE)
		shape->coordinates = add_vector3(shape->coordinates, \
		shape->local_basis.row[Z]);
	else if (action == ACTION_Z_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE)
		shape->coordinates = subtract_vector3(shape->coordinates, \
		shape->local_basis.row[Z]);
}

t_matrix3x3	get_local_basis(t_vector3 n)
{
	t_matrix3x3	result;
	t_vector3	up;

	up = get_vector3(0.0f, 1.0f, 0.0f);
	if (is_uneqaul_vector3(up, n) == false)
	{
		up = get_vector3(0.0f, 0.0f, -1.0f);
	}
	result.row[X] = cross_product3x3(up, n);
	result.row[Y] = cross_product3x3(n, result.row[X]);
	result.row[Z] = n;
	return (result);
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
