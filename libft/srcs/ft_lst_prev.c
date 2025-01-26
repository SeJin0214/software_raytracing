/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_prev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:11:37 by sejjeong          #+#    #+#             */
/*   Updated: 2024/09/24 17:42:19 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_prev_or_null(t_list *head, t_list *current)
{
	ft_assert(head != NULL, "ft_lst_prev_or_null, head null");
	ft_assert(current != NULL, "ft_lst_prev_or_null, current null");
	while (head != NULL && head->next != current)
	{
		head = head->next;
	}
	return (head);
}
