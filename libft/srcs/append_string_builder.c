/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_string_builder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 06:06:39 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/10 17:40:15 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "string_builder.h"
#include "builder_buffer.h"

void	append_to_string_builder(t_string_builder *builder, const char *str)
{
	t_list				*temp;
	t_builder_buffer	*buffer;
	size_t				remain_len;

	temp = builder->buffer;
	ft_assert(str != NULL, "append_to_string_builder, str == null");
	remain_len = ft_strlen(str);
	while (temp != NULL && remain_len > 0)
	{
		buffer = (t_builder_buffer *)temp->content;
		if (is_full_buffer(*buffer) == false)
		{
			if (get_build_buffer_size() - buffer->size <= remain_len)
			{
				ft_lstadd_back(&builder->buffer, ft_lstnew(create_buffer()));
			}
			while (is_full_buffer(*buffer) == false && *str != '\0')
			{
				buffer->str[buffer->size++] = *str++;
				--remain_len;
				++(builder->total_size);
			}
		}
		temp = temp->next;
	}
}

void	append_char_to_builder(t_string_builder *builder, const char ch)
{
	t_list				*temp;
	t_builder_buffer	*buffer;

	temp = builder->buffer;
	while (temp != NULL)
	{
		buffer = (t_builder_buffer *)temp->content;
		if (is_full_buffer(*buffer) == false)
		{
			break ;
		}
		temp = temp->next;
	}
	buffer->str[buffer->size++] = ch;
	++(builder->total_size);
	if (is_full_buffer(*buffer))
	{
		ft_lstadd_back(&builder->buffer, ft_lstnew(create_buffer()));
	}
}
