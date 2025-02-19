/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:48 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/20 03:13:07 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H
# include "world.h"
# include "vector_struct.h"

bool		is_shadowed_surface(t_world *world, \
const t_vector3 surface, void *object);

inline t_ivector3	reflect_light(const t_ivector3 ligth_resource_color, \
const t_ivector3 surface_color)
{
	const t_ivector3	refloection_color = \
	{{\
		ligth_resource_color.x * surface_color.x / 255, \
		ligth_resource_color.y * surface_color.y / 255, \
		ligth_resource_color.z * surface_color.z / 255, \
	}};

	return (refloection_color);
}

#endif