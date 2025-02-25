/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:50:48 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 16:51:53 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_down(int keycode, t_vars *va)
{
	if (keycode == KEY_ESC)
		destroy_and_close_fdf(va);
	return (0);
}


int	main_loop()
{
	return (0);
}
