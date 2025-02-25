/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_mod_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:03:05 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 16:49:08 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	put_tile(t_vars *va, int i, int j)
{
	t_image	*image = va->image_0;
	int		tile_size = 160;

	if (image->ptr == NULL)
	{
		image->ptr = mlx_xpm_file_to_image(va->mlx, "github.xpm",
						&tile_size, &tile_size);
		if (image->ptr == NULL)
		{
			destroy_and_close_fdf(va);
			fdf_error(ERR_FOPEN);
		}
		mlx_put_image_to_window(va->mlx, va->win->ptr, image->ptr, 64*j, 64*i);
	}
}
