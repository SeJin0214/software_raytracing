/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:15 by sejjeong          #+#    #+#             */
/*   Updated: 2024/07/22 11:58:17 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *num, const char *base)
{
	int			res;
	int			temp;
	int			i;
	const int	base_len = ft_strlen(base);

	ft_assert(base != NULL, "base is NULL");
	ft_assert(num != NULL, "num is NULL");
	i = 0;
	res = 0;
	if (num[i] == '+' || num[i] == '-')
		++i;
	while (num[i] != '\0')
	{
		res *= base_len;
		temp = indexof(base, num[i]);
		if (temp == -1)
		{
			break ;
		}
		res += temp;
		++i;
	}
	if (num[0] == '-')
		res *= -1;
	return (res);
}
