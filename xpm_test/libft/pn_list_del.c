/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pn_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:42:05 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 20:06:18 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pn_list_del(t_stack **stack, t_node *node)
{
	if ((*stack)->size == 0)
		return ;
	else if ((*stack)->size == 1)
	{
		free((*stack)->head);
		(*stack)->head = NULL;
		(*stack)->tail = NULL;
		(*stack)->size = 0;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
		--(*stack)->size;
	}
}

void	pn_list_del_front(t_stack **stack)
{
	if ((*stack)->size == 0)
		return ;
	else if ((*stack)->size == 1)
	{
		free((*stack)->head);
		(*stack)->head = NULL;
		(*stack)->tail = NULL;
		--(*stack)->size;
	}
	else
	{
		(*stack)->head = (*stack)->head->next;
		free((*stack)->head->prev);
		(*stack)->head->prev = NULL;
		--(*stack)->size;
	}
}

void	pn_list_del_back(t_stack **stack)
{
	if ((*stack)->size == 0)
		return ;
	else if ((*stack)->size == 1)
	{
		free((*stack)->head);
		(*stack)->head = NULL;
		(*stack)->tail = NULL;
	}
	else
	{
		(*stack)->tail = (*stack)->tail->prev;
		free((*stack)->tail->next);
		(*stack)->tail->next = NULL;
		--(*stack)->size;
	}
	--(*stack)->size;
}

void	pn_list_clear(t_stack **stack)
{
	while ((*stack)->size != 0)
	{
		pn_list_del_front(stack);
	}
}
