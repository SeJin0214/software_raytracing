# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 15:07:14 by sejjeong          #+#    #+#              #
#    Updated: 2025/02/21 20:47:45 by sejjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -mavx2 -fno-stack-protector -funroll-loops -g

RM = rm
RFLAGS = -rf

SRCS_DIR = ./mandatory
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
OBJS_NAME = objs

INCLUDE = -I $(SRCS_DIR)
LIBFT_INCLUDE = -I $(LIBFT_DIR)
MLX_INCLUDE = -I $(MLX_DIR)

LIBFT_LINK = -L $(LIBFT_DIR) -l ft
MLX_LINK = -L $(MLX_DIR) -l mlx_Linux
LIBRARY_LINK = -L/user/lib -l Xext -l X11 -l m -l bsd

LINK = $(LIBFT_LINK) $(MLX_LINK) $(LIBRARY_LINK)

SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/camera.c \
	$(SRCS_DIR)/cylinder.c \
	$(SRCS_DIR)/cylinder_object.c \
	$(SRCS_DIR)/cylinder_action.c \
	$(SRCS_DIR)/equation.c \
	$(SRCS_DIR)/hit_record.c \
	$(SRCS_DIR)/init_canvas.c \
	$(SRCS_DIR)/parse.c \
	$(SRCS_DIR)/parse_util.c \
	$(SRCS_DIR)/parse_solid_shape.c \
	$(SRCS_DIR)/plane.c \
	$(SRCS_DIR)/plane_action.c \
	$(SRCS_DIR)/ray.c \
	$(SRCS_DIR)/render.c \
	$(SRCS_DIR)/shadow.c \
	$(SRCS_DIR)/solid_shape.c \
	$(SRCS_DIR)/sphere.c \
	$(SRCS_DIR)/sphere_action.c \
	$(SRCS_DIR)/world.c \
	$(SRCS_DIR)/render_util.c \
	$(SRCS_DIR)/light.c \
	$(SRCS_DIR)/quaternion.c \
	$(SRCS_DIR)/input_object.c \
	$(SRCS_DIR)/input_camera.c \
	$(SRCS_DIR)/input_light.c \
	
BONUS_DIR = ./bonus

BONUS_SRCS = $(BONUS_DIR)/main_bonus.c \
	$(BONUS_DIR)/camera_bonus.c \
	$(BONUS_DIR)/cylinder_bonus.c \
	$(BONUS_DIR)/cylinder_object_bonus.c \
	$(BONUS_DIR)/cylinder_action_bonus.c \
	$(BONUS_DIR)/equation_bonus.c \
	$(BONUS_DIR)/hit_record_bonus.c \
	$(BONUS_DIR)/init_canvas_bonus.c \
	$(BONUS_DIR)/parse_bonus.c \
	$(BONUS_DIR)/parse_util_bonus.c \
	$(BONUS_DIR)/parse_solid_shape_bonus.c \
	$(BONUS_DIR)/plane_bonus.c \
	$(BONUS_DIR)/plane_action_bonus.c \
	$(BONUS_DIR)/ray_bonus.c \
	$(BONUS_DIR)/render_bonus.c \
	$(BONUS_DIR)/shadow_bonus.c \
	$(BONUS_DIR)/solid_shape_bonus.c \
	$(BONUS_DIR)/sphere_bonus.c \
	$(BONUS_DIR)/sphere_action_bonus.c \
	$(BONUS_DIR)/world_bonus.c \
	$(BONUS_DIR)/render_util_bonus.c \
	$(BONUS_DIR)/light_bonus.c \
	$(BONUS_DIR)/quaternion_bonus.c \
	$(BONUS_DIR)/input_object_bonus.c \
	$(BONUS_DIR)/input_camera_bonus.c \
	$(BONUS_DIR)/input_light_bonus.c \

OBJS = ${SRCS:.c=.o}
ASM = ${SRCS:.c=.s}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}


ifdef ON_BONUS_FLAG
	OBJECTS = $(BONUS_OBJS)
	INCLUDE = -I $(BONUS_DIR)
else
	OBJECTS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECTS)
		make -C $(MLX_DIR)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) $(INCLUDE) $^ $(LINK) -o $@

%.o: %.c
	touch $<
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) $(INCLUDE) -c $< -o $@
%.s: %.c
	touch $<
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(MLX_INCLUDE) $(INCLUDE) -S $< -o $@

bonus:
	make ON_BONUS_FLAG=1 all

bonusre:
	make fclean
	make bonus

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

.PHONY : all clean fclean re bonus bonusre
