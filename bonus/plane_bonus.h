/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:28:16 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 04:10:40 by sejjeong         ###   ########.fr       */
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

// 플레인은 나도 이제 알겠다.
inline t_ivector2	get_uv_coordinate_in_plane(\
const void *plane, const t_vector3 hit_point)
{
	t_ivector2		uv;
	const t_plane	*pl = plane;
	const t_vector3	direction = (subtract_vector3(hit_point, \
	pl->shape.coordinates));

	uv.x = dot_product3x3(direction, pl->shape.local_basis.row[X]) / 2.5f;
	uv.y = dot_product3x3(direction, pl->shape.local_basis.row[Y]) / 2.5f;
	return (uv);
}

/* plane_action.c */
void		update_scale_diameter_plane(void *plane, \
const t_action action);
void		update_scale_height_plane(void *plane, \
const t_action action);

#endif