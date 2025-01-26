/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_deque2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:31 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:36 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ring_deque.h"

int	peek_back_in_ring_deque(t_ring_deque *ring_deque)
{
	return (ring_deque->arr[get_back_index(ring_deque)]);
}

int	peek_front_in_ring_deque(t_ring_deque *ring_deque)
{
	return (ring_deque->arr[get_front_index(ring_deque)]);
}

bool	is_empty_in_ring_deque(t_ring_deque *ring_deque)
{
	return (ring_deque->count == 0);
}

bool	is_full_in_ring_deque(t_ring_deque *ring_deque)
{
	return (ring_deque->count == ring_deque->size - 1);
}

void	free_ring_deque(t_ring_deque *ring_deque)
{
	free(ring_deque->arr);
	free(ring_deque);
}
