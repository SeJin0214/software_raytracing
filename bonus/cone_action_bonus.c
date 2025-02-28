/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_action_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:52:54 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/28 18:56:18 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"

void	update_scale_diameter_cone(void *obj, \
const t_action action)
{
	t_cone	*cone;

	cone = obj;
	if (action == ACTION_OBJECT_DIAMETER_SCALE_UP)
	{
		cone->diameter += 0.5f;
	}
	else if (action == ACTION_OBJECT_DIAMETER_SCALE_DOWN)
	{
		cone->diameter = fmaxf(cone->diameter - 0.5f, 0.5f);
	}
}

void	update_scale_height_cone(void *obj, \
const t_action action)
{
	t_cone	*cone;

	cone = obj;
	if (action == ACTION_OBJECT_HEIGHT_SCALE_UP)
	{
		cone->height += 0.5f;
	}
	else if (action == ACTION_OBJECT_HEIGHT_SCALE_DOWN)
	{
		cone->height = fmaxf(cone->height - 0.5f, 0.5f);
	}
}
