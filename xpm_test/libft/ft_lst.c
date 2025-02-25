/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuna <yuna@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:04:33 by yuna              #+#    #+#             */
/*   Updated: 2024/05/08 10:02:42 by yuna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != 0)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != (void *)0)
	{
		while (lst->next != (void *)0)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	t_list	**insertion_point;

	insertion_point = &new_lst;
	while (lst != NULL)
	{
		current = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			if (insertion_point != &new_lst)
				ft_lstclear(&new_lst, del);
			break ;
		}
		*insertion_point = current;
		insertion_point = &(current->next);
		lst = lst->next;
	}
	return (new_lst);
}
