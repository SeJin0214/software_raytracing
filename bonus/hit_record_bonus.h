/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:25:48 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 16:46:54 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_BONUS_H
# define HIT_RECORD_BONUS_H
# include "vector.h"

typedef struct s_hit_record
{
	t_vector3	point;
	t_vector3	normal;
	t_ivector3	color;
	float		t;
	void		*object;
}	t_hit_record;

t_hit_record	get_hit_record(void);

#endif
