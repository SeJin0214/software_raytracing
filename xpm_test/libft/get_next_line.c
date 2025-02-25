/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:20:52 by yuna              #+#    #+#             */
/*   Updated: 2024/05/17 14:53:49 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	*lst_head;
	t_gnl			*lst;
	int				enter_idx;
	ssize_t			ret;
	char			*line;

	lst = gnl_cur_lst(&lst_head, fd);
	if (lst == NULL)
		return (NULL);
	while (1)
	{
		enter_idx = gnl_str_util(lst->backup, UTIL_FIND_ENTER);
		if (enter_idx >= 0)
			return (gnl_make_line(lst, enter_idx, &lst_head));
		ret = read(fd, lst->buff, BUFFER_SIZE);
		line = gnl_do_if_no_read(ret, lst, &lst_head);
		if (line == (char *)BREAK)
			break ;
		else if (line)
			return (line);
		if (gnl_update_backup(ret, lst, &lst_head) == NULL)
			return (NULL);
	}
	return (NULL);
}

void	*gnl_cur_lst(t_gnl **lst_head, int fd)
{
	t_gnl	*curr;
	t_gnl	*lst;

	curr = *lst_head;
	while (curr)
	{
		if (curr->fd == fd)
		{
			lst = curr;
			break ;
		}
		curr = curr->next;
	}
	if (curr)
		return (lst);
	lst = (t_gnl *)malloc(sizeof(t_gnl));
	if (lst == NULL)
		return (NULL);
	gnl_lst_init(lst, fd);
	if (lst->buff == NULL)
		return (NULL);
	if (*lst_head)
		lst->next = *lst_head;
	*lst_head = lst;
	return (lst);
}

char	*gnl_do_if_no_read(ssize_t ret, t_gnl *lst, t_gnl **lst_head)
{
	if (ret == RET_ERROR)
	{
		gnl_free_lst(lst_head, lst->fd);
		return ((char *)BREAK);
	}
	if (ret == RET_NOTHING)
	{
		if (lst->backup == NULL || lst->backup[0] == '\0')
		{
			gnl_free_lst(lst_head, lst->fd);
			return ((char *)BREAK);
		}
		else
			return (gnl_make_line(lst, LAST_LINE, lst_head));
	}
	return (NULL);
}

char	*gnl_make_line(t_gnl *lst, int ret, t_gnl **lst_head)
{
	char	*line;
	int		len;

	if (ret == LAST_LINE)
	{
		len = gnl_str_util(lst->backup, UTIL_STRLEN);
		line = (char *)malloc(sizeof(char) * (len + 1));
		if (line == NULL)
			return (gnl_free_lst(lst_head, lst->fd));
		line[0] = '\0';
		gnl_lcat(line, lst->backup, len + 1);
		gnl_free_lst(lst_head, lst->fd);
		return (line);
	}
	else
	{
		line = (char *)malloc(sizeof(char) * (ret + 2));
		if (line == NULL)
			return (gnl_free_lst(lst_head, lst->fd));
		line[0] = '\0';
		gnl_lcat(line, lst->backup, ret + 2);
		gnl_lcat(lst->backup, lst->backup + ret + 1, LCAT_MEMMOVE_MODE);
		return (line);
	}
}

char	*gnl_update_backup(ssize_t buff_len, t_gnl *lst, t_gnl **lst_head)
{
	int		backup_len;
	char	*temp;

	backup_len = 0;
	while (lst->backup && (lst->backup)[backup_len])
		++backup_len;
	temp = (char *)malloc(sizeof(char) * (buff_len + backup_len + 1));
	if (temp == NULL)
		return (gnl_free_lst(lst_head, lst->fd));
	temp[0] = '\0';
	gnl_lcat(temp, lst->backup, backup_len + 1);
	gnl_lcat(temp, lst->buff, buff_len + 1);
	free(lst->backup);
	lst->backup = temp;
	return (lst->backup);
}
