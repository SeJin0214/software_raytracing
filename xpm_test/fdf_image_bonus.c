/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:19:34 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 17:02:25 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_image(t_vars *va, t_image *image)
{
	int		color;

	color = 0;
	image->pixel = 0;
	image->ptr = mlx_new_image(va->mlx, va->win->w, va->win->h);
	image->buffer = mlx_get_data_addr(image->ptr,
			&(image->pixel_bits), &(image->line_bytes), &(image->endian));
	if (image->pixel_bits != 32)
		color = mlx_get_color_value(va->mlx, color);
}

void	image_put_pixel(t_image *image, t_fdf_dot cnt, int color)
{
	image->pixel = (cnt.pixel_y * image->line_bytes) + (cnt.pixel_x * 4);
	image->buffer[image->pixel + 0] = (char)((color) & 0xFF);
	image->buffer[image->pixel + 1] = (color >> 8) & 0xFF;
	image->buffer[image->pixel + 2] = (color >> 16) & 0xFF;
	image->buffer[image->pixel + 3] = (color >> 24);
}
