/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_by_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:29:29 by sejjeong          #+#    #+#             */
/*   Updated: 2024/08/07 11:42:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

void	exit_by_error(const char *func_name, const char *message)
{
	perror("fail");
	ft_putstr_fd(func_name, 2);
	ft_putstr_fd(", ", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	exit_by_exception(const char *func_name, const char *message)
{
	ft_printf("exception! -> %s, %s\n", func_name, message);
	exit(EXIT_SUCCESS);
}
