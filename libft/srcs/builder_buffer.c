/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:30:04 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 16:49:37 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "builder_buffer.h"
#include "libft.h"

t_builder_buffer	*create_buffer(void)
{
	t_builder_buffer	*buffer;

	buffer = ft_calloc(sizeof(t_builder_buffer), 1);
	buffer->str = ft_calloc(sizeof(char), get_build_buffer_capacity() + 1);
	buffer->size = 0;
	return (buffer);
}

void	clear_buffer(void *buffer)
{
	t_builder_buffer	*temp;

	ft_assert(buffer != NULL, "clear_buffer, invalid buffer");
	temp = (t_builder_buffer *)buffer;
	free(temp->str);
	temp->str = NULL;
	free(temp);
}

bool	is_full_buffer(t_builder_buffer buffer)
{
	return (buffer.size == get_build_buffer_capacity());
}

size_t	get_build_buffer_capacity(void)
{
	return (1024u);
}
