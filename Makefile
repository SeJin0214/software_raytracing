# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 15:07:14 by sejjeong          #+#    #+#              #
#    Updated: 2024/11/19 21:27:51 by sejjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm
RFLAGS = -rf

SRCS_DIR = .
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

INCLUDE = -I ./
LIBFT_INCLUDE = -I $(LIBFT_DIR)
MLX_INCLUDE = -I $(MLX_DIR)

LIBFT_LINK = -L $(LIBFT_DIR) -l ft
MLX_LINK = -L $(MLX_DIR) -l mlx_Linux
LIBRARY_LINK = -L/user/lib -l Xext -l X11 -l m -l bsd

LINK = $(LIBFT_LINK) $(MLX_LINK) $(LIBRARY_LINK)

SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/solid_shape.c \
	$(SRCS_DIR)/world.c \
	$(SRCS_DIR)/init_canvas.c \

OBJS = ${SRCS:.c=.o}

all:$(NAME)

$(NAME):$(OBJS)
		make -C $(MLX_DIR)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) $(INCLUDE) $^ $(LINK) -o $@

%.o: %.c
	touch $<
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) $(INCLUDE) -c $< -o $@

bonus:
	make fclean
	make ON_BONUS_FLAG=1 all

clean:
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(RFLAGS) $(OBJS)
	$(RM) $(RFLAGS) $(BONUS_OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RFLAGS) $(NAME)

re: 
	make fclean 
	make all

.PHONY : all clean fclean re bonus
