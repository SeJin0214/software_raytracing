/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:10 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:12 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_strn_fd(const char *str, const int fd, const int n)
{
	const int	length = ft_strlen(str);

	if (n < length)
	{
		write(fd, str, n);
		return (n);
	}
	ft_putstr_fd((char *)str, fd);
	return (length);
}

int	write_repeated_char(const char ch, const int fd, const int n)
{
	int		count;
	int		result;
	char	arr[1024];

	if (n <= 0)
	{
		return (0);
	}
	ft_memset(arr, ch, sizeof(char) * 1024);
	count = 0;
	result = 0;
	while (count < n)
	{
		count += 1024;
		if (count > n)
		{
			result += write(fd, arr, count + (n - count));
		}
		else
		{
			result += write(fd, arr, 1024);
		}
	}
	return (result);
}
