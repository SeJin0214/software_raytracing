/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_object_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:31:39 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 00:28:30 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cylinder_bonus.h"

t_cylinder	*copy_construction_to_cylinder(const t_cylinder cylinder)
{
	t_cylinder	*result;

	result = malloc(sizeof(t_cylinder));
	result->shape = cylinder.shape;
	result->shape.is_hit = is_hit_cylinder;
	result->shape.delete = delete_cylinder;
	result->shape.get_uv_coordinate = get_uv_coordinate_in_cylinder;
	result->shape.scale_diameter = update_scale_diameter_cylinder;
	result->shape.scale_height = update_scale_height_cylinder;
	result->diameter = cylinder.diameter;
	result->height = cylinder.height;
	return (result);
}

void	delete_cylinder(void *obj)
{
	free(obj);
}

extern inline t_ivector2	get_uv_coordinate_in_cylinder(\
const void *cylinder, const t_vector3 hit_point);
