/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:22:44 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/08 16:58:05 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

void	*get_element_or_null_in_list(t_array_list *list, size_t index)
{
	if (index >= list->get_count(list))
	{
		return (NULL);
	}
	return (list->list + index);
}

size_t	get_count_in_list(t_array_list *list)
{
	return (list->count);
}
