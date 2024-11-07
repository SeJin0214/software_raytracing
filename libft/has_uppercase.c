/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_uppercase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:06:40 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 14:08:07 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	has_uppercase(const char *str)
{
	while (*str != '\0')
	{
		if (*str <= 'Z' && *str >= 'A')
		{
			return (true);
		}
		++str;
	}
	return (false);
}
