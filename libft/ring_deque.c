/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:20 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:23 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ring_deque.h"

t_ring_deque	*init_ring_deque(const size_t size)
{
	t_ring_deque	*ring_deque;

	if (size == 0)
	{
		ft_putstr_fd("init_ring_deque, invalid argument -> 0", 2);
	}
	ring_deque = malloc(sizeof(t_ring_deque));
	ring_deque->front = 0;
	ring_deque->back = 0;
	ring_deque->count = 0;
	ring_deque->size = size + 1;
	ring_deque->arr = malloc(sizeof(int) * (size + 1));
	ft_memset(ring_deque->arr, 0, sizeof(int) * (size + 1));
	return (ring_deque);
}

int	pop_front_in_ring_deque(t_ring_deque *ring_deque)
{
	int	pop;

	pop = ring_deque->arr[ring_deque->front];
	ring_deque->front = (ring_deque->front + 1) % ring_deque->size;
	--(ring_deque->count);
	return (pop);
}

int	pop_back_in_ring_deque(t_ring_deque *ring_deque)
{
	int	pop;

	--(ring_deque->back);
	if (ring_deque->back < 0)
	{
		ring_deque->back = ring_deque->size - 1;
	}
	pop = ring_deque->arr[ring_deque->back];
	--(ring_deque->count);
	return (pop);
}

bool	push_front_in_ring_deque(t_ring_deque *ring_deque, const int value)
{
	if (is_full_in_ring_deque(ring_deque))
	{
		return (false);
	}
	--(ring_deque->front);
	if (ring_deque->front < 0)
	{
		ring_deque->front = ring_deque->size - 1;
	}
	ring_deque->arr[ring_deque->front] = value;
	++(ring_deque->count);
	return (true);
}

bool	push_back_in_ring_deque(t_ring_deque *ring_deque, const int value)
{
	if (is_full_in_ring_deque(ring_deque))
	{
		return (false);
	}
	ring_deque->arr[ring_deque->back] = value;
	ring_deque->back = (ring_deque->back + 1) % ring_deque->size;
	++(ring_deque->count);
	return (true);
}
