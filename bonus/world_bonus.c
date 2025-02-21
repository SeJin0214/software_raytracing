/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:04:43 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 06:29:47 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "float_bonus.h"
#include "world_bonus.h"
#include "solid_shape_bonus.h"
#include "parse_bonus.h"

void	init_world(t_world *world)
{
	world->is_valid_ambient_light = false;
	world->is_valid_camera = false;
	world->current_object_index = 0;
	world->current_light_index = 0;
	init_array_list(&world->solid_shapes, sizeof(t_solid_shape *));
	init_array_list(&world->lights, sizeof(t_light));
}

void	destroy_world(t_world *world)
{
	destroy_shapes(&world->solid_shapes);
	world->lights.destroy(&world->lights, do_nothing);
}

bool	try_add_ambient_light_to_world(char **attributes, t_world *world)
{
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != AMBIENT_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[AMBIENT_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT;

	if (is_invalid_format || world->is_valid_ambient_light)
	{
		return (false);
	}
	is_invalid_value = \
	try_atof(attributes[AMBIENT_ATTRIBUTE_RATIO_IN_RANGE], \
	&world->ambient_light.brightness) == false \
	|| is_invalid_ratio_in_range(world->ambient_light.brightness) \
	|| try_parse_color(attributes[AMBIENT_ATTRIBUTE_COLORS], \
	&world->ambient_light.colors) == false;
	if (is_invalid_value)
	{
		return (false);
	}
	world->is_valid_ambient_light = true;
	return (true);
}

bool	try_add_camera_to_world(char **attributes, \
t_world *world, t_canvas *canvas)
{
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != CAMERA_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[CAMERA_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[CAMERA_ATTRIBUTE_ORIENTATION_VECTOR], ',') \
	!= VECTOR_ATTRIBUTE_COUNT;

	if (is_invalid_format || world->is_valid_camera)
		return (false);
	is_invalid_value = \
	try_parse_vector3(attributes[CAMERA_ATTRIBUTE_COORDINATES], \
	&world->camera.coordinates) == false \
	|| try_parse_vector3(attributes[CAMERA_ATTRIBUTE_ORIENTATION_VECTOR], \
	&world->camera.local_basis.row[Z]) == false \
	|| try_atof(attributes[CAMERA_ATTRIBUTE_FOV], \
	&world->camera.field_of_view) == false \
	|| world->camera.field_of_view > 180.0f \
	|| world->camera.field_of_view < 0.0f;
	if (is_invalid_value)
		return (false);
	init_camera(world, canvas);
	return (true);
}

bool	try_add_light_to_world(char **attributes, t_world *world)
{
	t_light		light;
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != LIGHT_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[LIGHT_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[LIGHT_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT;

	if (is_invalid_format)
	{
		return (false);
	}
	is_invalid_value = \
	try_parse_vector3(attributes[LIGHT_ATTRIBUTE_COORDINATES], \
	&light.coordinates) == false \
	|| try_atof(attributes[LIGHT_ATTRIBUTE_RATIO_IN_RANGE], \
	&light.brightness) == false \
	|| is_invalid_ratio_in_range(light.brightness) \
	|| try_parse_color(attributes[LIGHT_ATTRIBUTE_COLORS], \
	&light.colors) == false;
	if (is_invalid_value)
		return (false);
	world->lights.add(&world->lights, &light);
	return (true);
}
