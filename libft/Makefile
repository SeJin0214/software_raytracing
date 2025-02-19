#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:11:40 by sejjeong          #+#    #+#              #
#    Updated: 2025/02/18 13:29:32 by sejjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -mavx2 -fno-stack-protector -funroll-loops
 

AR = ar
AR_FLAGS = rc

RM =rm
RM_FLAGS = -rf

SRC_DIR = ./srcs

SRCS = $(SRC_DIR)/ft_isalpha.c \
	$(SRC_DIR)/ft_isdigit.c \
	$(SRC_DIR)/ft_isalnum.c \
	$(SRC_DIR)/ft_isascii.c \
	$(SRC_DIR)/ft_isprint.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_memset.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/ft_memcpy.c \
	$(SRC_DIR)/ft_memmove.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strlcat.c \
	$(SRC_DIR)/ft_toupper.c \
	$(SRC_DIR)/ft_tolower.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strrchr.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_memchr.c \
	$(SRC_DIR)/ft_memcmp.c \
	$(SRC_DIR)/ft_strnstr.c \
	$(SRC_DIR)/ft_atoi.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_strjoin.c \
	$(SRC_DIR)/ft_strtrim.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_strmapi.c \
	$(SRC_DIR)/ft_striteri.c \
	$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/write_number.c \
	$(SRC_DIR)/sprint_toa.c \
	$(SRC_DIR)/ft_math.c \
	$(SRC_DIR)/indexof.c \
	$(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/hashtable.c \
	$(SRC_DIR)/generate_hash_65599.c \
	$(SRC_DIR)/check_conversion_digit.c \
	$(SRC_DIR)/check_conversion_letter.c \
	$(SRC_DIR)/format_conversion.c \
	$(SRC_DIR)/print_digit.c \
	$(SRC_DIR)/print_str.c \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_lstnew.c \
	$(SRC_DIR)/ft_lstadd_front.c \
	$(SRC_DIR)/ft_lstsize.c \
	$(SRC_DIR)/ft_lstlast.c \
	$(SRC_DIR)/ft_lstadd_back.c \
	$(SRC_DIR)/ft_lstdelone.c \
	$(SRC_DIR)/ft_lstclear.c \
	$(SRC_DIR)/ft_lstiter.c \
	$(SRC_DIR)/ft_lstmap.c \
	$(SRC_DIR)/ring_deque.c \
	$(SRC_DIR)/ring_deque2.c \
	$(SRC_DIR)/ring_deque3.c \
	$(SRC_DIR)/assert.c \
	$(SRC_DIR)/ft_atoi_base.c \
	$(SRC_DIR)/ft_strs_len.c \
	$(SRC_DIR)/ft_realloc.c \
	$(SRC_DIR)/has_uppercase.c \
	$(SRC_DIR)/clear_ints.c \
	$(SRC_DIR)/exit_by_error.c \
	$(SRC_DIR)/swap_type.c \
	$(SRC_DIR)/string_builder.c \
	$(SRC_DIR)/builder_buffer.c \
	$(SRC_DIR)/is_whitespace.c \
	$(SRC_DIR)/ft_lst_prev.c \
	$(SRC_DIR)/append_string_builder.c \
	$(SRC_DIR)/build_string.c \
	$(SRC_DIR)/do_nothing.c \
	$(SRC_DIR)/try_atof.c \
	$(SRC_DIR)/array_list.c \
	$(SRC_DIR)/list_getter.c \
	$(SRC_DIR)/vector.c \
	$(SRC_DIR)/vector_operation.c \
	$(SRC_DIR)/vector_product.c \
	$(SRC_DIR)/ivector.c \
	$(SRC_DIR)/matrix.c \

HEADER_DIR = -I .

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@
	
$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(RM_FLAGS) $(OBJS)

fclean: clean	
	$(RM) $(RM_FLAGS) $(NAME)	

re: fclean all

.PHONY: all clean fclean re
