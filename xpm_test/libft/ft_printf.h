/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:16:41 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 10:30:54 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define CONVERSION_C 0
# define CONVERSION_S 1
# define CONVERSION_P 2
# define CONVERSION_D 3
# define CONVERSION_I 4
# define CONVERSION_U 5
# define CONVERSION_LOWER_X 6
# define CONVERSION_X 7
# define CONVERSION_PERCENT 8

# define INT_STRING_LEN 12
# define VOID_POINTER_SIZE 16

typedef struct s_flag
{
	char	sharp;
	char	zero;
	char	minus;
	char	space;
	char	plus;
	char	field;
	char	use_p;
	int		prec;
}	t_flag;

typedef struct s_conversion
{
	int		start_idx;
	int		end_idx;
	char	conversion;
	t_flag	flag;
}	t_conv;

int		ft_printf(const char *format, ...);

int		print_char(unsigned char c, t_flag flag);
int		print_string(const char *str, t_flag flag);
int		print_address(void *ptr, t_flag flag);
int		print_int(int num, t_flag flag);
int		print_uint(unsigned int num, t_flag flag);
int		print_hex(unsigned int num, t_flag flag, char conversion);
int		print_percent(void);

void	scan_for_flag(t_conv *munja, const char *str);
int		repeat_char(char chr, int repeat, int str_len, int condition);

size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	str_toupper(char *str, int i, char conversion);

#endif
