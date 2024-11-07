/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:11:06 by sejjeong          #+#    #+#             */
/*   Updated: 2024/09/11 13:06:46 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst_or_null, t_list *new)
{
	t_list	*temp;

	if (*lst_or_null == NULL)
	{
		*lst_or_null = new;
		return ;
	}
	temp = *lst_or_null;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}
