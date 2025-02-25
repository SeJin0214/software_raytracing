/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:24:45 by yuna              #+#    #+#             */
/*   Updated: 2024/06/01 12:45:51 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		++i;
	}
	return (s);
}

void	gnl_lst_init(t_gnl *lst, int fd)
{
	gnl_memset(lst, 0, sizeof(t_gnl));
	lst->fd = fd;
	lst->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
}

void	*gnl_free_lst(t_gnl **lst_head, int fd)
{
	t_gnl	*prev;
	t_gnl	*curr;

	curr = *lst_head;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (curr->backup)
				free(curr->backup);
			if (curr->buff)
				free(curr->buff);
			if (prev == NULL)
				*lst_head = curr->next;
			else
				prev->next = curr->next;
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}

int	gnl_str_util(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == UTIL_STRLEN)
	{
		while (str[i])
			++i;
		return (i);
	}
	else if (mode == UTIL_FIND_ENTER)
	{
		if (str == 0)
			return (-1);
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			++i;
		}
	}
	return (-1);
}

char	*gnl_lcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = -1;
	dst_len = 0;
	if (size == (size_t)LCAT_MEMMOVE_MODE)
	{
		if (src == 0)
			return (gnl_memset(dst, 0, 1));
		while (src[++i])
			dst[i] = src[i];
		dst[i] = '\0';
		return (dst);
	}
	else
	{
		if (src == NULL)
			return (dst);
		while (dst[dst_len])
			++dst_len;
		while (++i + 1 < size)
			dst[dst_len + i] = src[i];
		dst[dst_len + i] = '\0';
		return (dst);
	}
}
