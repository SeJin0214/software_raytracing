/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:34:03 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 17:22:21 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	
#include <stdlib.h>
#include "array_list.h"
#include "libft.h"

void	init_array_list(t_array_list *list, size_t memory_offset)
{
	list->memory_offset = memory_offset;
	list->count = 0;
	list->capacity = 10;
	list->list = ft_calloc(list->memory_offset, list->capacity);
	list->get_count = get_count_in_list;
	list->add = add_in_list;
	list->clear = clear_in_list;
	list->destroy = destroy_list;
	list->foreach = do_foreach;
	list->get_element_or_null = get_element_or_null_in_list;
}

void	add_in_list(t_array_list *list, void *element)
{
	char	*p;

	if (list->count == list->capacity)
	{
		list->list = ft_realloc(list->list, list->capacity * \
		list->memory_offset, list->capacity * list->memory_offset * 2);
		list->capacity *= 2;
		if (list->list == NULL)
		{
			return ;
		}
	}
	p = list->list;
	ft_memcpy(p + (list->count * list->memory_offset), \
	element, list->memory_offset);
	++list->count;
}

void	clear_in_list(t_array_list *list, void (*del)(void *))
{
	do_foreach(list, del);
	free(list->list);
	init_array_list(list, list->memory_offset);
}

void	destroy_list(t_array_list *list, void (*del)(void *))
{
	do_foreach(list, del);
	free(list->list);
	list->list = NULL;
}

void	do_foreach(t_array_list *list, void (*execute)(void *))
{
	size_t	i;
	char	*p;

	i = 0;
	p = list->list;
	while (i < list->count)
	{
		execute(p + (i * list->memory_offset));
		++i;
	}
}
