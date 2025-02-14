/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 19:53:14 by sejjeong         ###   ########.fr       */
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
#define X_BUTTON 17

int	main(int argc, char **argv)
{
	t_world		world;
	t_canvas	canvas;

	ft_memset(&world, 0, sizeof(t_world));
	init_canvas(&canvas);
	if (try_parse(argc, argv, &world, &canvas) == false)
	{
		printf("Error\n");
		free_canvas(&canvas);
		return (1);
	}
	render(&world, &canvas);
	mlx_hook(canvas.win, X_BUTTON, 0, mlx_loop_end, canvas.xvar);
	mlx_loop(canvas.xvar);
	free_canvas(&canvas);
	destroy_world(&world);
	return (0);
}
