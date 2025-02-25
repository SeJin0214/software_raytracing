/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:21:20 by yuna              #+#    #+#             */
/*   Updated: 2024/06/01 13:41:34 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define BREAK 1
# define LAST_LINE -1
# define LCAT_MEMMOVE_MODE -1
# define UTIL_STRLEN 1
# define UTIL_FIND_ENTER 2
# define RET_ERROR -1
# define RET_NOTHING 0
# define FREE_NODE 0
# define FREE_BUFF_ONLY 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_gnl
{
	int				fd;
	char			*buff;
	char			*backup;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
void	*gnl_cur_lst(t_gnl **lst_head, int fd);
char	*gnl_do_if_no_read(ssize_t ret, t_gnl *lst, t_gnl **lst_head);
char	*gnl_make_line(t_gnl *lst, int ret, t_gnl **lst_head);
char	*gnl_update_backup(ssize_t buff_len, t_gnl *lst, t_gnl **lst_head);
char	*gnl_lcat(char *dst, char *src, size_t size);
void	*gnl_memset(void *s, int c, size_t n);
int		gnl_str_util(char *str, int mode);
void	gnl_lst_init(t_gnl *lst, int fd);
void	*gnl_free_lst(t_gnl **lst_head, int fd);
#endif
