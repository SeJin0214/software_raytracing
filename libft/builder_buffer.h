/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_buffer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:28:02 by sejjeong          #+#    #+#             */
/*   Updated: 2024/10/11 17:01:57 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDER_BUFFER_H
# define BUILDER_BUFFER_H
# include <stddef.h>
# include <stdbool.h>

typedef struct s_builder_buffer
{
	size_t	size;
	char	*str;
}t_builder_buffer;

void				clear_buffer(void *buffer);
t_builder_buffer	*create_buffer(void);
bool				is_full_buffer(t_builder_buffer buffer);
size_t				get_build_buffer_size(void);

#endif
