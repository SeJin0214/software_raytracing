/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnr_list_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:44:12 by yuna              #+#    #+#             */
/*   Updated: 2024/06/10 11:46:14 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*pnr_list_new(void *data)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

void	pnr_list_add_front(t_stack **stack, t_node *new)
{
	new->next = (*stack)->head;
	(*stack)->head = new;
	(*stack)->tail->next = new;
	++(*stack)->size;
}

void	pnr_list_add_back(t_stack **stack, t_node *new)
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
			(*stack)->head->prev = new;
		}
		++(*stack)->size;
	}
}
