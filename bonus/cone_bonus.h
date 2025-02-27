/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:44:26 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 20:20:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_BONUS_H
# define CONE_BONUS_H
# include "solid_shape_bonus.h"
# include "solid_shape_getter_bonus.h"

typedef struct s_cone
{
	t_solid_shape	shape;
	float			diameter;
	float			height;
}	t_cone;

/* cone_bonus.c */
bool	is_hit_cone(const t_ray ray, \
const void *obj, t_hit_record *out);

/* cone_object_bonus.c */
t_cone	*copy_construction_to_cone(const t_cone cone);
void	delete_cone(void *obj);
inline t_vector2	get_uv_coordinate_in_cone(const void *cone, const t_vector3 hit_point)
{
	t_vector2	uv;
	
	
	uv.x = 0;
	(void) cone;
	(void) hit_point;
	return (uv);
}

/* cone_action_bonus.c */
void	update_scale_diameter_cone(void *cone, \
const t_action action);
void	update_scale_height_cone(void *cone, \
const t_action action);

#endif