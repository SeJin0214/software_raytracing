/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/20 03:09:07 by sejjeong         ###   ########.fr       */
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
	|| try_change_shape(input->world, key) \
	|| try_move_camera(input->world, key) \
	|| try_rotate_camera(input->world, key) \
	|| try_move_light(input->world, key))
	{
		render(input->world, input->canvas);
	}
	return (0);
}
