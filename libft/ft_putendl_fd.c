/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:00:54 by sejjeong          #+#    #+#             */
/*   Updated: 2024/04/30 20:05:25 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	const int	count = ft_putstr_fd(s, fd);

	write(fd, "\n", 1);
	return (count + 1);
}
