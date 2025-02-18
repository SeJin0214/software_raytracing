/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 15:18:52 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "world.h"
#include "mlx.h"
#include "mlx_int.h"
#include "canvas.h"
#include "parse.h"
#include "render.h"
#include "input.h"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_world		world;
	t_canvas	canvas;
	t_input		input;

	ft_memset(&world, 0, sizeof(t_world));
	init_canvas(&canvas);
	if (try_parse(argc, argv, &world, &canvas) == false)
	{
		printf("Error\n");
		free_canvas(&canvas);
		return (1);
	}
	input.canvas = &canvas;
	input.world = &world;
	render(&world, &canvas);
	mlx_hook(canvas.win, X_BUTTON, 0, mlx_loop_end, canvas.xvar);
	mlx_key_hook(canvas.win, input_key, &input);
	mlx_loop(canvas.xvar);
	free_canvas(&canvas);
	destroy_world(&world);
	return (0);
}

int	input_key(int key, t_input *input)
{
	if (key == ESC)
	{
		mlx_loop_end(input->canvas->xvar);
	}
	if (try_move_shape(input->world, key) \
	|| try_rotate_shape(input->world, key) \
	|| try_update_shape_scale(input->world, key) \
	|| try_change_shape(input->world, key))
	{
		render(input->world, input->canvas);
	}
	return (0);
}

bool	try_move_shape(t_world *world, const int key)
{
	t_solid_shape	**shape;
	t_action		action;

	if (key != 'w' && key != 's' && key != 'a' && key != 'd' \
	&& key != 'q' && key != 'z')
		return (false);
	if (key == 'w')
		action = ACTION_OBJECT_MOVE_FRONT;
	else if (key == 's')
		action = ACTION_OBJECT_MOVE_BACK;
	else if (key == 'a')
		action = ACTION_OBJECT_MOVE_LEFT;
	else if (key == 'd')
		action = ACTION_OBJECT_MOVE_RIGHT;
	else if (key == 'q')
		action = ACTION_OBJECT_MOVE_UP;
	else if (key == 'z')
		action = ACTION_OBJECT_MOVE_DOWN;
	shape = world->solid_shapes.get_element_or_null(\
	&world->solid_shapes, world->current_object_index);
	move_shape(*shape, action);
	return (true);
}

bool	try_rotate_shape(t_world *world, const int key)
{
	t_solid_shape	**shape;
	t_action		action;

	if (key != 'f' && key != 'h' && key != 'v' && key != 'n' \
	&& key != 'g' && key != 'b')
		return (false);
	if (key == 'f')
		action = ACTION_Z_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE;
	else if (key == 'h')
		action = ACTION_Z_AXIS_ROTATING_OBJECT_CLOCKWISE;
	else if (key == 'v')
		action = ACTION_Y_AXIS_ROTATING_OBJECT_CLOCKWISE;
	else if (key == 'n')
		action = ACTION_Y_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE;
	else if (key == 'g')
		action = ACTION_X_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE;
	else if (key == 'b')
		action = ACTION_X_AXIS_ROTATING_OBJECT_CLOCKWISE;
	shape = world->solid_shapes.get_element_or_null(\
	&world->solid_shapes, world->current_object_index);
	rotate_shape(*shape, action);
	return (true);
}

bool	try_update_shape_scale(t_world *world, const int key)
{
	t_solid_shape	**shape;
	t_action		action;

	if (key != 'u' && key != 'j' && key != 'i' && key != 'k')
	{
		return (false);
	}
	if (key == 'u')
		action = ACTION_OBJECT_DIAMETER_SCALE_UP;
	else if (key == 'j')
		action = ACTION_OBJECT_DIAMETER_SCALE_DOWN;
	else if (key == 'i')
		action = ACTION_OBJECT_HEIGHT_SCALE_UP;
	else if (key == 'k')
		action = ACTION_OBJECT_HEIGHT_SCALE_DOWN;
	shape = world->solid_shapes.get_element_or_null(\
	&world->solid_shapes, world->current_object_index);
	(*shape)->scale_diameter(*shape, action);
	(*shape)->scale_height(*shape, action);
	return (true);
}

bool	try_change_shape(t_world *world, const int key)
{
	if (key == ',')
	{
		if (world->current_object_index == 0)
		{
			world->current_object_index = \
			get_count_in_list(&world->solid_shapes) - 1;
		}
		else
		{
			world->current_object_index -= 1;
		}
		return (true);
	}
	else if (key == '.')
	{
		world->current_object_index = \
		(world->current_object_index + 1) \
		% get_count_in_list(&world->solid_shapes);
		return (true);
	}
	return (false);
}
