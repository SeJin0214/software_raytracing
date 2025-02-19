/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:13:28 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/20 02:26:06 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "render.h"

extern inline t_ivector3	reflect_light(\
const t_ivector3 ligth_resource_color, const t_ivector3 surface_color);

bool	is_shadowed_surface(t_world *world, \
const t_vector3 surface, void *object)
{
	const t_ray		light_ray = get_ray(world->light.coordinates, \
	normalize_vector3(subtract_vector3(surface, world->light.coordinates)));
	t_hit_record	hit_record;
	t_solid_shape	**shape;
	int				i;
	const t_vector3	surface_to_light = \
	subtract_vector3(world->light.coordinates, surface);

	i = -1;
	hit_record = get_hit_record();
	while ((size_t)++i < world->solid_shapes.count)
	{
		shape = get_element_or_null_in_list(&world->solid_shapes, i);
		if (object == *shape)
			continue ;
		if ((*shape)->is_hit(light_ray, *shape, &hit_record))
		{
			if (get_length_squared(subtract_vector3(world->light.coordinates, \
			add_vector3(surface, normalize_vector3(surface_to_light)))) \
			> get_length_squared(subtract_vector3(\
			hit_record.point, world->light.coordinates)))
				return (true);
		}
	}
	return (false);
}
