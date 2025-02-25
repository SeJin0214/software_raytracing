/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:18:43 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 17:05:35 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main()
{
	t_vars		va;

	new_window(&va);
	va.image_0 = (t_image *)ft_calloc(1, sizeof(t_image));
	put_tile(&va, 0,0);
	ft_bzero(&(va.input), sizeof(va.input));
	mlx_hook(va.win->ptr, KeyPress, 1L << 0, key_down, &va);
	mlx_hook(va.win->ptr, DestroyNotify, 1L << 17, destroy_and_close_fdf, &va);
	mlx_loop_hook(va.mlx, main_loop, &va);
	mlx_loop(va.mlx);
	return (0);
}

int	destroy_and_close_fdf(t_vars *va)
{
	mlx_loop_end(va->mlx);
	mlx_destroy_image(va->mlx, va->image_0->ptr);
	free(va->image_0);
	mlx_destroy_window(va->mlx, va->win->ptr);
	free(va->win);
	mlx_destroy_display(va->mlx);
	free(va->mlx);
	exit(0);
	return (0);
}
