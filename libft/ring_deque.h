/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_deque.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:00:27 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 12:00:29 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RING_DEQUE_H
# define RING_DEQUE_H
# include <stddef.h>

typedef struct s_ring_deque
{
	int		front;
	int		back;
	int		*arr;
	size_t	count;
	size_t	size;
}t_ring_deque;

/* ring_deque.c */
t_ring_deque	*init_ring_deque(const size_t size);
int				pop_back_in_ring_deque(t_ring_deque *ring_deque);
int				pop_front_in_ring_deque(t_ring_deque *ring_deque);
bool			push_back_in_ring_deque(t_ring_deque *ring_deque, \
		const int value);
bool			push_front_in_ring_deque(t_ring_deque *ring_deque, \
		const int value);

/* ring_deque2.c */
int				peek_back_in_ring_deque(t_ring_deque *ring_deque);
int				peek_front_in_ring_deque(t_ring_deque *ring_deque);
bool			is_empty_in_ring_deque(t_ring_deque *ring_deque);
bool			is_full_in_ring_deque(t_ring_deque *ring_deque);
void			free_ring_deque(t_ring_deque *ring_deque);

/* ring_deque3.c */
int				get_back_index(t_ring_deque *ring_deque);
int				get_front_index(t_ring_deque *ring_deque);
size_t			get_full_size(t_ring_deque *ring_deque);
int				get_offset_to_front(t_ring_deque *ring_deque, int i);
int				get_offset_to_back(t_ring_deque *ring_deque, int i);

#endif
