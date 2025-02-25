/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:28:44 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/24 09:26:50 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

extern int			lerp_int(const int from, const int to, const float t);
extern float		lerp(const float a, const float b, const float t);
extern inline float		get_radian(const float degree);
extern inline int			get_min(int num0, int num1);
extern inline int			get_max(int num0, int num1);
