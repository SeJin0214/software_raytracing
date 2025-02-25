/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnr_list_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:42:05 by yuna              #+#    #+#             */
/*   Updated: 2024/06/10 11:46:08 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pnr_list_del(t_stack **stack, t_node *node)
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

void	pnr_list_del_front(t_stack **stack)
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
		(*stack)->tail->next = (*stack)->head->next;
		(*stack)->head->next->prev = (*stack)->tail;
		free((*stack)->head);
		--(*stack)->size;
	}
}

void	pnr_list_del_back(t_stack **stack)
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
		(*stack)->tail->prev->next = (*stack)->head;
		(*stack)->head->prev = (*stack)->tail->prev;
		free((*stack)->tail);
	}
	--(*stack)->size;
}

void	pnr_list_clear(t_stack **stack)
{
	while ((*stack)->size != 0)
	{
		pnr_list_del_front(stack);
	}
}
