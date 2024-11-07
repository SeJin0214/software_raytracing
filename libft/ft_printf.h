/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:49 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:58:51 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# define NULL_SIZE (6)
# define NIL_SIZE (5)
# define BIT_SIZE64 (64)
# define MAX_DIGIT8 (8)
# define MAX_DIGIT_INT (11)
# define MAX_DIGIT_LONG_HEXA (16)
# define BUFFER_SIZE (1024)

typedef struct s_data
{
	struct			s_state
	{
		unsigned char	state_plus : 1;
		unsigned char	state_minus : 1;
		unsigned char	state_space : 1;
		unsigned char	state_zero : 1;
		unsigned char	state_number_sign : 1;
		unsigned char	state_precision : 1;	
		unsigned char	state_upper_hexa : 1;
		unsigned char	state_neg_decimal : 1;
	} t_state;
	unsigned int	width;
	unsigned int	precision;
}	t_data;

int		ft_printf(const char *str, ...);
int		try_format_str(const char **str, va_list ap, t_data *data);
void	check_flags(const char **str, t_data *data);
void	check_width(const char **str, va_list ap, t_data *data);
void	check_precision(const char **str, va_list ap, t_data *data);
int		check_conversion(const char **str, va_list ap, t_data *data);
int		format_conversion_c(char ch, t_data *data);
int		format_conversion_s(char *str, t_data *data);
int		convert_flag_s_width(t_data *data, const char *arg_str, \
		const int length);
int		format_conversion_percent(void);
int		format_conversion_p(void *address, t_data *data);

int		convert_digit(t_data *data, const char *num);
int		write_special_flag(t_data *data);
int		get_count_by_flag(t_data *data);
int		write_basic(t_data *data, const char *num);
int		convert_zero_flag(t_data *data, const char *num);
int		format_conversion_d_i(int num, t_data *data);
int		format_conversion_u(unsigned int num, t_data *data);
int		format_conversion_x(unsigned int num, t_data *data);
int		format_conversion_upper_x(unsigned int num, t_data *data);

int		print_str_fd(const char *str_or_null, const int fd);
int		print_strn_fd(const char *str_or_null, const int fd, const int n);
int		write_repeated_char(const char ch, const int fd, const int n);
void	sprint_long_hexa(char *dest, unsigned long nbr, const char *base);
size_t	get_ascii_digit(const char *dest);

#endif
