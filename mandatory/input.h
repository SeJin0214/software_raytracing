/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:32 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 21:13:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "world.h"
# define ESC 0xFF1B
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define X_BUTTON 17

typedef	struct s_input
{
	t_world		*world;
	t_canvas	*canvas;
}	t_input;

typedef enum action
{
	ACTION_NEXT_OBJECT,
	ACTION_PREVIOUS_OBJECT,
	ACTION_OBJECT_ROTATION_TO_X_AXIS,
	ACTION_OBJECT_ROTATION_TO_Y_AXIS,
	ACTION_OBJECT_ROTATION_TO_Z_AXIS,
	ACTION_OBJECT_DIAMETER_SCALE_UP,
	ACTION_OBJECT_DIAMETER_SCALE_DOWN,
	ACTION_OBJECT_HEIGHT_SCALE_UP,
	ACTION_OBJECT_HEIGHT_SCALE_DOWN,
	ACTION_OBJECT_MOVE_UP,
	ACTION_OBJECT_MOVE_DOWN,
	ACTION_OBJECT_MOVE_LEFT,
	ACTION_OBJECT_MOVE_RIGHT,
	ACTION_OBJECT_MOVE_FRONT,
	ACTION_OBJECT_MOVE_BACK,
}	t_action;

int	input_key(int key, t_input *input);

#endif