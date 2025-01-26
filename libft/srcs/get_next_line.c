/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:44 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:59:47 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*get_next_line(int fd)
{
	static t_hashtable	table;
	const char			*remain;
	char				*read;
	char				*result;

	remain = get_value_or_null(&table, fd);
	if (remain == NULL)
	{
		read = read_line_in_file_malloc(fd);
		if (read == NULL)
		{
			return (NULL);
		}
		update_key(&table, fd, read);
	}
	result = find_next_line_malloc(&table, fd);
	remain = get_value_or_null(&table, fd);
	if (remain != NULL && ft_strlen(remain) == 0)
	{
		remove_key(&table, fd);
		remain = NULL;
	}
	return (result);
}

char	*read_line_in_file_malloc(const int fd)
{
	ssize_t		read_length;
	char		*buffer;
	int			i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		++i;
	}
	read_length = read(fd, buffer, BUFFER_SIZE);
	if (read_length <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*find_next_line_malloc(t_hashtable *table, const int fd)
{
	int			i;
	char		*next;
	char		*temp;
	const char	*remain;

	remain = get_value_or_null(table, fd);
	while (remain != NULL)
	{
		i = 0;
		while (remain[i] != '\0' && remain[i] != '\n')
			++i;
		if (remain[i] == '\n')
		{
			next = ft_strndup_malloc(remain, i + 1);
			temp = ft_strndup_malloc(remain + i + 1, ft_strlen(remain) - i - 1);
			update_key(table, fd, temp);
			return (next);
		}
		if (join_buffer_in_table_malloc(table, fd) == false)
			break ;
		remain = get_value_or_null(table, fd);
	}
	next = ft_strndup_malloc(remain, ft_strlen(remain));
	remove_key(table, fd);
	return (next);
}

bool	join_buffer_in_table_malloc(t_hashtable *table, const int fd)
{
	const char	*remain;
	char		*pa_read;
	char		*pa_result;
	int			i;
	int			j;

	pa_read = read_line_in_file_malloc(fd);
	if (pa_read == NULL)
	{
		return (false);
	}
	remain = get_value_or_null(table, fd);
	pa_result = malloc(sizeof(char) * \
	(ft_strlen(remain) + ft_strlen(pa_read) + 1));
	i = -1;
	while (remain[++i] != '\0')
		pa_result[i] = remain[i];
	j = 0;
	while (pa_read[j] != '\0')
		pa_result[i++] = pa_read[j++];
	pa_result[i] = '\0';
	free(pa_read);
	update_key(table, fd, pa_result);
	return (true);
}
