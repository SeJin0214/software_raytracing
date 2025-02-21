/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:38:54 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 08:00:33 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_BONUS_H
# define LIGHT_BONUS_H
# include "vector.h"
# include "shadow_bonus.h"
# include "light_struct_bonus.h"

inline t_ivector3	load_diffuse_color(const t_light light, \
const t_hit_record hit_record)
{
	const t_vector3		surface_to_diffuse_light = \
	subtract_vector3(light.coordinates, hit_record.point);
	const t_vector3		direction_to_light = \
	normalize_vector3(surface_to_diffuse_light);
	const float			light_intensity = \
	fmaxf(dot_product3x3(direction_to_light, hit_record.normal), 0.0f);
	const t_ivector3	diffuse_source_color = \
	multiply_ivector3(multiply_ivector3(light.colors, light_intensity), \
	light.brightness);
	const t_ivector3	diffuse_color = \
	reflect_light(diffuse_source_color, hit_record.color);

	return (diffuse_color);
}

inline t_ivector3	load_ambient_color(const t_ambient_light ambient, \
const t_hit_record hit_record)
{
	const t_ivector3	reflection_color = \
	reflect_light(ambient.colors, hit_record.color);
	const float			brightness = ambient.brightness;
	const t_ivector3	ambient_color = get_ivector3(\
	brightness * 255, brightness * 255, brightness * 255);
	const t_ivector3	result_color = \
	reflect_light(ambient_color, reflection_color);

	return (result_color);
}

/**
 * r = 2 * n * n * l - l
 * (r * v)^sh
*/

inline t_ivector3	load_specular_color(const t_camera camera, \
const t_light light, const t_hit_record hit_record)
{
	const t_vector3		surface_to_camera = normalize_vector3(\
	subtract_vector3(camera.coordinates, hit_record.point));
	const t_vector3		surface_to_light = normalize_vector3(\
	subtract_vector3(light.coordinates, hit_record.point));
	const t_vector3		reflection_v = normalize_vector3(\
	subtract_vector3(multiply_vector3(hit_record.normal, \
	dot_product3x3(hit_record.normal, surface_to_light) * 2), \
	surface_to_light));
	const float			light_intensity = \
	powf(fmaxf(dot_product3x3(reflection_v, surface_to_camera), 0.0f), 32);
	const t_ivector3	specular_color = \
	multiply_ivector3(light.colors, light_intensity);

	return (multiply_ivector3(specular_color, light.brightness));
}

void	move_light(t_light *light, const t_action action);

#endif