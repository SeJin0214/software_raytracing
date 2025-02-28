/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/28 20:19:15 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"
#include "parse_bonus.h"
#include "render_bonus.h"
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
	render_multi_thread(&world, &canvas);
	mlx_hook(canvas.win, X_BUTTON, 0, mlx_loop_end, canvas.xvar);
	mlx_key_hook(canvas.win, input_key, &input);
	mlx_loop(canvas.xvar);
	destroy_world(&world, &canvas);
	free_canvas(&canvas);
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
	|| try_move_light(input->world, key) \
	|| try_change_light(input->world, key) \
	|| try_change_texture(input->world, key))
	{
		render_multi_thread(input->world, input->canvas);
	}
	return (0);
}

void	render_multi_thread(t_world *world, t_canvas *canvas)
{
	pthread_t	pids[16];
	size_t		i;
	t_renderer	renderer[16];

	i = 0;
	while (i < 16)
	{
		renderer[i].world = world;
		renderer[i].canvas = canvas;
		renderer[i].start_x = canvas->screen.width / 4.0f * (i % 4);
		renderer[i].last_x = canvas->screen.width / 4.0f * (i % 4 + 1);
		renderer[i].start_y = canvas->screen.height / 4.0f * (i / 4);
		renderer[i].last_y = canvas->screen.height / 4.0f * (i / 4 + 1);
		pthread_mutex_init(&renderer[i].canvas_lock, NULL);
		pthread_create(&pids[i], NULL, render, &renderer[i]);
		++i;
	}
	i = 0;
	while (i < 16)
	{
		pthread_join(pids[i], NULL);
		pthread_mutex_destroy(&renderer[i].canvas_lock);
		++i;
	}
	mlx_put_image_to_window(canvas->xvar, canvas->win, canvas->img, 0, 0);
}
