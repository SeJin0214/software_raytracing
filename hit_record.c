/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:25:07 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/26 14:33:14 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <limits.h>
#include "hit_record.h"
#include "libft.h"

t_hit_record	get_hit_record()
{
	t_hit_record	result;

	result.t = FLT_MAX;
	ft_memset(&result.color, INT_MIN, sizeof(t_ivector3));
	ft_memset(&result.point, INT_MIN, sizeof(t_vector3));
	ft_memset(&result.normal, INT_MIN, sizeof(t_vector3));
	return (result);
}