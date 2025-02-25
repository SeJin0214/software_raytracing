/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pn_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:42:05 by yuna              #+#    #+#             */
/*   Updated: 2024/06/10 11:43:40 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*pn_list_new(void *data)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

void	pn_list_add_front(t_stack **stack, t_node *new)
{
	new->next = (*stack)->head;
	(*stack)->head = new;
	++(*stack)->size;
}

void	pn_list_add_back(t_stack **stack, t_node *new)
{
	if (new != NULL)
	{
		if ((*stack)->head == NULL)
		{
			(*stack)->head = new;
			(*stack)->tail = new;
		}
		else
		{
			(*stack)->tail->next = new;
			(*stack)->tail = new;
		}
		++(*stack)->size;
	}
}
