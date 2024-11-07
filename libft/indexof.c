/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:56 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:59:59 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	indexof(const char *str, const char ch)
{
	const char	*p = str;

	while (*p != '\0')
	{
		if (*p == ch)
		{
			return (p - str);
		}
		++p;
	}
	return (-1);
}
