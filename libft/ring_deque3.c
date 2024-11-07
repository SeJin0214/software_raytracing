/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_deque3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:39 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:41 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ring_deque.h"

int	get_back_index(t_ring_deque *ring_deque)
{
	if (ring_deque->back - 1 >= 0)
	{
		return (ring_deque->back - 1);
	}
	else
	{
		return (ring_deque->size - 1);
	}
}

int	get_front_index(t_ring_deque *ring_deque)
{
	return (ring_deque->front);
}

size_t	get_full_size(t_ring_deque *ring_deque)
{
	return (ring_deque->size - 1);
}

int	get_offset_to_back(t_ring_deque *ring_deque, int i)
{
	int			offset;
	const int	back = get_back_index(ring_deque);

	if (back >= i)
	{
		offset = back - i;
	}
	else
	{
		offset = (ring_deque->size - 1) - i + back + 1;
	}
	return (offset);
}

int	get_offset_to_front(t_ring_deque *ring_deque, int i)
{
	int			offset;
	const int	front = get_front_index(ring_deque);

	if (front <= i)
	{
		offset = i - front;
	}
	else
	{
		offset = ring_deque->size - front + i;
	}
	return (offset);
}
