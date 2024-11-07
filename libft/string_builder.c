/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:10:37 by sejjeong          #+#    #+#             */
/*   Updated: 2024/10/08 13:34:23 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string_builder.h"
#include "builder_buffer.h"

void	init_string_builder(t_string_builder *builder)
{
	builder->total_size = 0;
	builder->buffer = ft_lstnew(create_buffer());
	builder->append = append_to_string_builder;
	builder->append_char = append_char_to_builder;
	builder->delete_builder = delete_to_string_builder;
	builder->clear = clear_to_string_builder;
	builder->is_empty = is_empty_builder;
	builder->to_string = build_string;
}

bool	is_empty_builder(t_string_builder *builder)
{
	return (builder->total_size == 0);
}

void	delete_to_string_builder(t_string_builder *builder)
{
	ft_lstclear(&builder->buffer, clear_buffer);
	builder->total_size = 0;
}

void	clear_to_string_builder(t_string_builder *builder)
{
	ft_lstclear(&builder->buffer, clear_buffer);
	init_string_builder(builder);
}
