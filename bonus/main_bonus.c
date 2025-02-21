/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 04:54:08 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "world_bonus.h"
#include "mlx.h"
#include "mlx_int.h"
#include "canvas_bonus.h"
#include "parse_bonus.h"
#include "render_bonus.h"
#include "input_bonus.h"
#include <sys/time.h>

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
	struct timeval start, end;
    double elapsedTime;

    gettimeofday(&start, NULL);


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
	|| try_move_light(input->world, key) \
	|| try_change_light(input->world, key))
	{
		render(input->world, input->canvas);
	}
	gettimeofday(&end, NULL);

    elapsedTime = (end.tv_sec - start.tv_sec) +
                  (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("myFunction() 실행 시간: %f 초\n", elapsedTime);
	return (0);
}
