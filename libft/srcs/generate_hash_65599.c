/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_hash_65599.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:30 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:59:32 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	generate_hash_65599(const char *str)
{
	unsigned int	hash;

	hash = 0;
	while (*str != '\0')
	{
		hash = 65599 * hash + *str;
		++str;
	}
	return (hash ^ (hash >> 16));
}
