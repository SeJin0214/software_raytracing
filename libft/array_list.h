/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:27:18 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/05 16:21:18 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H
# include <stddef.h>

typedef struct s_array_list
{
	void	*list;
	size_t	count;
	size_t	size;
	size_t	memory_offset;
	size_t	(*get_count)(t_array_list *);
	void	(*add)(t_array_list *, void *);
	void	(*clear)(t_array_list *, void (*del)(void *));
	void	(*foreach)(t_array_list *, void (*execute)(void *));
	void	(*get_element_or_null)(t_array_list *, int);
}	t_array_list;

void	init_array_list(t_array_list *list, size_t memory_offset);
size_t	get_count_in_list(t_array_list *list);
void	add_in_list(t_array_list *list, void *element);
void	clear_in_list(t_array_list *list, void (*del)(void *));
void	do_foreach(t_array_list *list, void (*execute)(void *));
void	*get_element_or_null_in_list(t_array_list *list, int index);

#endif