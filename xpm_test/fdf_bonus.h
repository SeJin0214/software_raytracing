/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:18:39 by yuna              #+#    #+#             */
/*   Updated: 2025/02/25 17:07:35 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define KEY_SHIFT 65505

# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_WHEEL 2
# define MOUSE_CLICK_RIGHT 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define WIN_W 1920
# define WIN_H 1010

# define ERR_FOPEN 1
# define ERR_EMPTY 2
# define ERR_DFCOL 3

# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_fdf_dot
{
	int					index;
	int					height;
	unsigned int		color;
	int					pixel_x;
	int					pixel_y;
	struct s_fdf_dot	*prev;
	struct s_fdf_dot	*next;
}	t_fdf_dot;

typedef struct s_double_dot
{
	double	x;
	double	y;
}	t_double_dot;

typedef struct s_fdf_row
{
	int					index;
	int					size;
	t_fdf_dot			*head;
	t_fdf_dot			*tail;
	struct s_fdf_row	*next;
}	t_fdf_row;

typedef struct s_fdf_map
{
	int			size;
	t_fdf_row	*head;
	t_fdf_row	*tail;
}	t_fdf_map;

typedef struct s_image
{
	void	*ptr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		pixel;
}	t_image;

typedef struct s_window
{
	void	*ptr;
	int		w;
	int		h;
	int		margin_ud;
	int		margin_lr;
	int		rate;
	int		height_rate;
	int		theta;
	int		theta_updown;
}	t_window;

typedef struct s_input
{
	char	left;
	char	right;
	char	up;
	char	down;
	char	size_changed;
	char	mouse_l;
	int		mouse_l_x;
	int		mouse_l_y;
	char	mouse_r;
	int		mouse_r_x;
	int		mouse_r_y;
	char	shift;
}	t_input;

typedef struct s_vars
{
	void		*mlx;
	t_window	*win;
	t_image		*image_0;
	t_fdf_map	*map;
	t_input		input;
}	t_vars;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	double	delta_r;
	double	delta_g;
	double	delta_b;
	int		temp;
}	t_color;

void	put_tile(t_vars *va, int i, int j);

int		key_down(int keycode, t_vars *va);

// fdf_error_bonus.c
void		fdf_error(int err);

// fdf_bonus.c
int			destroy_and_close_fdf(t_vars *vars);

// fdf_hook_bonus.c
int			main_loop();

// fdf_window_bonus.c
void		new_window(t_vars *va);

// fdf_image_bonus.c
void		set_image(t_vars *va, t_image *image);
void		image_put_pixel(t_image *image, t_fdf_dot cnt, int color);

#endif
