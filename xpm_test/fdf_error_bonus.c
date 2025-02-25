/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:52:23 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 17:06:30 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	fdf_error(int err)
{
	if (err == ERR_FOPEN)
		perror("File open error");
	else if (err == ERR_EMPTY)
		ft_putstr_fd("Empty file.\n", 2);
	exit(1);
}
