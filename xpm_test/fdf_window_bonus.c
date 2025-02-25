/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:20:48 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 16:59:03 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_window_size(t_window *win, int rows, int dots);
void	window_size_rate(t_window *win, int rows, int dots);

void	new_window(t_vars *va)
{
	va->win = (t_window *)ft_calloc(1, sizeof(t_window));
	set_window_size(va->win, 300, 500);
	va->mlx = mlx_init();
	va->win->ptr = mlx_new_window(va->mlx, va->win->w, va->win->h,
			"Yuna's FdF");
	mlx_clear_window(va->mlx, va->win->ptr);
}

void	set_window_size(t_window *win, int rows, int dots)
{
	double	rad;
	double	rad_ud;

	win->rate = 30;
	win->height_rate = 10;
	win->theta = 45;
	win->theta_updown = 35;
	rad = ft_get_radian(win->theta);
	rad_ud = ft_get_radian(win->theta_updown);
	win->w = (dots * cos(rad) + rows * sin(rad)) * win->rate + 100;
	win->h = (rows * cos(rad) + dots * sin(rad)) * win->rate
		* sin(rad_ud) + 100;
	win->margin_lr = (rows) * sin(rad) * win->rate + 50;
	win->margin_ud = 50;
	window_size_rate(win, rows, dots);
}

void	window_size_rate(t_window *win, int rows, int dots)
{
	double	rad;
	double	rad_ud;

	rad = ft_get_radian(win->theta);
	rad_ud = ft_get_radian(win->theta_updown);
	if (win->w <= WIN_W && win->h <= WIN_H)
		return ;
	while (win->rate > 1 && (win->w > WIN_W || win->h > WIN_H))
	{
		--win->rate;
		win->w = (dots * cos(rad) + rows * sin(rad)) * win->rate + 100;
		win->h = (rows * cos(rad) + dots * sin(rad)) * win->rate
			* sin(rad_ud) + 100;
	}
	win->margin_lr = (rows) * sin(rad) * win->rate + 50;
	if (win->rate == 1)
	{
		win->w = WIN_W;
		win->h = WIN_H;
		win->margin_lr = (WIN_W - (dots * cos(rad) + rows * sin(rad))
				* win->rate) / 2 + (rows) * sin(rad) * win->rate;
		win->margin_ud = (WIN_H - (rows * cos(rad) + dots * sin(rad))
				* win->rate * sin(rad_ud)) / 2;
	}
}
