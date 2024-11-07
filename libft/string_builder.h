/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:10:34 by sejjeong          #+#    #+#             */
/*   Updated: 2024/10/08 13:38:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUILDER_H
# define STRING_BUILDER_H
# include <stdbool.h>
# include "libft.h"

typedef struct s_string_builder
{
	size_t	total_size;
	t_list	*buffer;
	void	(*append)(struct s_string_builder *builder, const char *str);
	void	(*append_char)(struct s_string_builder *builder, const char ch);
	void	(*delete_builder)(struct s_string_builder *builder);
	void	(*clear)(struct s_string_builder *builder);
	bool	(*is_empty)(struct s_string_builder *);
	char	*(*to_string)(struct s_string_builder *builder);
}t_string_builder;

/* string_builder.c */
void	init_string_builder(t_string_builder *builder);
bool	is_empty_builder(t_string_builder *builder);
void	delete_to_string_builder(t_string_builder *builder);
void	clear_to_string_builder(t_string_builder *builder);

/* build_string.c */
char	*build_string(t_string_builder *builder);
char	*copy_buffer(t_string_builder *builder);

/* append_string_builder.c */
void	append_to_string_builder(t_string_builder *builder, const char *str);
void	append_char_to_builder(t_string_builder *builder, const char ch);

#endif
