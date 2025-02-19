/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:54:44 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/20 03:05:52 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "world.h"

bool	try_move_light(t_world *world, const int key)
{
	t_action		action;

	if (key == HOME)
		action = ACTION_LIGHT_MOVE_FRONT;
	else if (key == END)
		action = ACTION_LIGHT_MOVE_BACK;
	else if (key == DELETE)
		action = ACTION_LIGHT_MOVE_LEFT;
	else if (key == PGDOWN)
		action = ACTION_LIGHT_MOVE_RIGHT;
	else if (key == BACKSPACE)
		action = ACTION_LIGHT_MOVE_UP;
	else if (key == BACKSLASH)
		action = ACTION_LIGHT_MOVE_DOWN;
	else
		return (false);
	move_light(&world->light, action);
	return (true);
}
