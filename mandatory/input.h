/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:32 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 14:22:15 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# define ESC 0xFF1B
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define X_BUTTON 17
# define COMMA 44
# define PREIOD 46
# define TENKEY_1 65436
# define TENKEY_2 65433
# define TENKEY_3 65435
# define TENKEY_4 65430
# define TENKEY_8 65431
# define TENKEY_6 65432
# define TENKEY_PLUS 65451
# define TENKEY_MINUS 65453
# include <stdbool.h>
# include "canvas.h"

typedef struct s_world	t_world;

typedef	struct s_input
{
	t_world		*world;
	t_canvas	*canvas;
}	t_input;

typedef enum action
{
	ACTION_NEXT_OBJECT,
	ACTION_PREVIOUS_OBJECT,
	ACTION_X_AXIS_ROTATING_OBJECT_CLOCKWISE,
	ACTION_X_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE,
	ACTION_Y_AXIS_ROTATING_OBJECT_CLOCKWISE,
	ACTION_Y_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE,
	ACTION_Z_AXIS_ROTATING_OBJECT_CLOCKWISE,
	ACTION_Z_AXIS_ROTATING_OBJECT_COUNTERCLOCKWISE,
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

int		input_key(int key, t_input *input);
bool	try_move_shape(t_world *world, const int key);
bool	try_rotate_shape(t_world *world, const int key);
bool	try_update_shape_scale(t_world *world, const int key);
bool	try_change_shape(t_world *world, const int key);

#endif