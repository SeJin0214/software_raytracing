/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:07:00 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/24 09:23:26 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "render.h"

extern inline t_ivector3	add_color(const t_ivector3 color0, \
const t_ivector3 color1);
extern inline int			convert_colors(t_ivector3 colors);
