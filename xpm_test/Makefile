CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fdf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

SRCS = \
	fdf.c\
	fdf_error.c\
	fdf_parse.c\
	fdf_list_row.c\
	fdf_list_map.c\
	fdf_window.c\
	fdf_image.c\
	fdf_draw.c\
	fdf_dda.c\

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = \
	fdf_bonus.c\
	fdf_hook_bonus.c\
	fdf_error_bonus.c\
	fdf_window_bonus.c\
	fdf_image_bonus.c\
	fdf_image_mod_bonus.c\

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: make_mandatory
bonus: make_bonus

make_mandatory: $(OBJS)
	rm -f make_bonus
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS)
	touch $@

make_bonus: $(BONUS_OBJS)
	rm -f make_mandatory
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS)
	touch $@

$(NAME): make_mandatory

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -O3 -c $^

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS) make_mandatory make_bonus

fclean:
	make -C $(LIBFT_DIR) fclean
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
