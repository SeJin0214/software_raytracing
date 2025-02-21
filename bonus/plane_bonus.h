/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:28:16 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/21 17:05:11 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_BONUS_H
# define PLANE_BONUS_H
# include "solid_shape_bonus.h"

typedef struct s_plane
{
	t_solid_shape	shape;
}	t_plane;

/* plane.c */
t_plane		*copy_construction_to_plane(const t_plane plane);
void		delete_plane(void *obj);
bool		is_hit_plane(const t_ray ray, const void *plane, t_hit_record *out);

/* plane_action.c */
void		update_scale_diameter_plane(void *plane, \
const t_action action);
void		update_scale_height_plane(void *plane, \
const t_action action);

#endif