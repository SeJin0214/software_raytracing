/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:50 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/12 19:46:38 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# define TABLE_SIZE 67

typedef struct s_node
{
	int				key;
	const char		*value;
	struct s_node	*next;
}	t_table_node;

typedef struct s_hashtable
{
	t_table_node	*node[TABLE_SIZE];
}	t_hashtable;

char		*get_next_line(int fd);
char		*read_line_in_file_malloc(const int fd);
char		*find_next_line_malloc(t_hashtable *table, const int fd);
bool		join_buffer_in_table_malloc(t_hashtable *table, const int fd);

const char	*get_value_or_null(const t_hashtable *table, const int key);
bool		remove_key(t_hashtable *table, const int key);
bool		update_key(t_hashtable *table, const int key, const char *pa_value);
bool		add_last_node_malloc(t_hashtable *table, \
const int key, const char *value);

#endif
