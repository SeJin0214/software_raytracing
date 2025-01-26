/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:19 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:59:23 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strs_len(const char **strs)
{
	size_t	i;

	if (strs == NULL)
	{
		return (0);
	}
	i = 0;
	while (strs[i] != NULL)
	{
		++i;
	}
	return (i);
}
