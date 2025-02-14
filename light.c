/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:49:47 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 13:15:06 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "world.h"
#include "render.h"

t_ivector3	load_diffuse_color(const t_light light, \
const t_hit_record hit_record)
{
	const t_vector3		surface_to_diffuse_light = \
	subtract_vector3(light.coordinates, hit_record.point);
	const t_vector3		direction_to_light = \
	normalize_vector3(surface_to_diffuse_light);
	const float			light_intensity = \
	fmax(dot_product3x3(direction_to_light, hit_record.normal), 0.0f);
	const t_ivector3	diffuse_source_color = \
	multiply_ivector3(light.colors, light_intensity);
	const t_ivector3	diffuse_color = \
	reflect_light(diffuse_source_color, hit_record.color);

	return (diffuse_color);
}

t_ivector3	load_ambient_color(const t_ambient_light ambient, \
const t_hit_record hit_record)
{
	const t_ivector3	reflection_color = \
	reflect_light(ambient.colors, hit_record.color);
	const float			ratio_in_range = ambient.ratio_in_range;
	const t_ivector3	ambient_color = get_ivector3(\
	ratio_in_range * 255, ratio_in_range * 255, ratio_in_range * 255);
	const t_ivector3	result_color = \
	reflect_light(ambient_color, reflection_color);

	return (result_color);
}
