/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:49:47 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 14:49:58 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "world.h"
#include "render.h"

extern inline t_ivector3	load_diffuse_color(const t_light light, \
const t_hit_record hit_record);

extern inline t_ivector3	load_ambient_color(const t_ambient_light ambient, \
const t_hit_record hit_record);
