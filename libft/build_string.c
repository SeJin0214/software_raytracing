/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:32:48 by sejjeong          #+#    #+#             */
/*   Updated: 2024/10/08 16:07:23 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder_buffer.h"
#include "libft.h"
#include "string_builder.h"

char	*build_string(t_string_builder *builder)
{
	char	*string;

	if (is_empty_builder(builder))
	{
		string = ft_calloc(sizeof(char), 1);
		if (string == NULL)
		{
			exit_by_error("build_string", "fail malloc");
		}
		return (string);
	}
	return (copy_buffer(builder));
}

char	*copy_buffer(t_string_builder *builder)
{
	char				*string;
	t_list				*temp;
	size_t				i;
	size_t				j;
	t_builder_buffer	*buffer;

	string = ft_calloc(sizeof(char), builder->total_size + 1);
	if (string == NULL)
	{
		exit_by_error("build_string", "string fail");
	}
	j = 0;
	temp = builder->buffer;
	while (temp != NULL)
	{
		buffer = (t_builder_buffer *)temp->content;
		i = 0;
		while (buffer->str[i] != '\0')
		{
			string[j++] = buffer->str[i++];
		}
		temp = temp->next;
	}
	return (string);
}
