/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:22:44 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/14 13:43:58 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

void	*get_element_or_null_in_list(t_array_list *list, size_t index)
{
	if (index >= list->count)
	{
		return (NULL);
	}
	return (list->list + (index * list->memory_offset));
}

size_t	get_count_in_list(t_array_list *list)
{
	return (list->count);
}
