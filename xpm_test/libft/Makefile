CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a

SRCS = \
	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_check_char.c\
	ft_itoa.c\
	ft_lower_upper.c\
	ft_lst_add_del.c\
	ft_lst.c\
	ft_mem.c\
	ft_putnbr_fd.c\
	ft_putstring_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	pn_list_del.c\
	pn_list_new.c\
	pnr_list_del.c\
	pnr_list_new.c\
	ft_range.c\
	ft_math.c

OBJS = $(SRCS:.c=.o)

PRINTF_SRCS = \
	ft_printf.c\
	ft_printf_int.c\
	ft_printf_uint.c\
	ft_printf_flag.c\
	ft_printf_hex.c\
	ft_printf_string.c\
	ft_printf_util.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

GNL_SRCS = \
	get_next_line_utils.c\
	get_next_line.c

GNL_OBJS = $(GNL_SRCS:.c=.o)

.PHONY: all clean fclean re

$(NAME): $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	ar rc $@ $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
