/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:18 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/14 15:14:53 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H
# include <stddef.h>

typedef struct s_array_list
{
	void	*list;
	size_t	count;
	size_t	capacity;
	size_t	memory_offset;
	size_t	(*get_count)(struct s_array_list *);
	void	(*add)(struct s_array_list *, void *);
	void	(*clear)(struct s_array_list *, void (*del)(void *));
	void	(*destroy)(struct s_array_list *, void (*del)(void *));
	void	(*foreach)(struct s_array_list *, void (*execute)(void *));
	void	*(*get_element_or_null)(struct s_array_list *, size_t);
}	t_array_list;

/* array_list.c */
void	init_array_list(t_array_list *list, size_t memory_offset);
void	add_in_list(t_array_list *list, void *element);
void	clear_in_list(t_array_list *list, void (*del)(void *));
void	do_foreach(t_array_list *list, void (*execute)(void *));
void	destroy_list(t_array_list *list, void (*del)(void *));

/* list_getter.c */
void	*get_element_or_null_in_list(t_array_list *list, size_t index);
size_t	get_count_in_list(t_array_list *list);

#endif