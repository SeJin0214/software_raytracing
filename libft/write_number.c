/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:01:38 by sejjeong          #+#    #+#             */
/*   Updated: 2024/04/30 16:17:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	write_nbr_recursive_fd(unsigned long nb, const int fd);

int	write_uint_fd(unsigned int ui, const int fd)
{
	int	count;

	if (ui == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	count = write_nbr_recursive_fd(ui, fd);
	return (count);
}

int	write_int_fd(int nbr, const int fd)
{
	int		count;
	long	num;

	count = 0;
	num = nbr;
	if (num == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (num < 0)
	{
		write(fd, "-", 1);
		++count;
		num *= -1;
	}
	count += write_nbr_recursive_fd(num, fd);
	return (count);
}

int	write_number_in_buffer(const char *buffer, const int fd, const size_t size)
{
	size_t	i;

	i = 0;
	while (buffer[i] == '0')
	{
		++i;
	}
	if (i == size)
	{
		return (write(fd, "0", 1));
	}
	return (write(fd, buffer + i, size - i));
}

static int	write_nbr_recursive_fd(unsigned long nb, const int fd)
{
	char	remain;
	int		count;

	if (nb == 0)
	{
		return (0);
	}
	remain = nb % 10 + '0';
	nb /= 10;
	count = 1;
	count += write_nbr_recursive_fd(nb, fd);
	write(fd, &remain, 1);
	return (count);
}
