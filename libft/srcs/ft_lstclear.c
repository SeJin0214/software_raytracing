/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:13:43 by sejjeong          #+#    #+#             */
/*   Updated: 2024/09/11 13:07:17 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst_or_null, void (*del)(void *))
{
	t_list	*temp;

	while (*lst_or_null != NULL)
	{
		(*del)((*lst_or_null)->content);
		temp = *lst_or_null;
		*lst_or_null = (*lst_or_null)->next;
		free(temp);
		temp = NULL;
	}
}
