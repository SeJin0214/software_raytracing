/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:34:03 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/08 16:50:10 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"
#include "libft.h"

void	init_array_list(t_array_list *list, size_t memory_offset)
{
	list->memory_offset = memory_offset;
	list->count = 0;
	list->size = 10;
	list->list = ft_calloc(list->memory_offset, list->size);
	list->get_count = get_count_in_list;
	list->add = add_in_list;
	list->clear = clear_in_list;
	list->foreach = do_foreach;
	list->get_element_or_null = get_element_or_null_in_list;
}

void	add_in_list(t_array_list *list, void *element)
{
	if (list->count == list->size)
	{
		list->list = ft_realloc(list->list, list->size * list->memory_offset, \
		list->size * list->memory_offset * 2);
		list->size *= list->memory_offset * 2;
		if (list->list == NULL)
		{
			return ;
		}
	}
	ft_memcpy(list->list + list->count, element, list->memory_offset);
	++list->count;
}

void	clear_in_list(t_array_list *list, void (*del)(void *))
{
	do_foreach(list, del);
}

void	do_foreach(t_array_list *list, void (*execute)(void *))
{
	size_t	i;

	i = 0;
	while (i < list->count)
	{
		execute(list->list + i);
		++i;
	}
}
