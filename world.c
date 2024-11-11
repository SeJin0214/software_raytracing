/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:04:43 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/11 11:54:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "libft.h"
#include "world.h"

void	init_world(t_world *world)
{
	world->is_valid_ambient_light = false;
	world->is_valid_camera = false;
	world->is_valid_light = false;
	init_array_list(&world->cylinders, sizeof(t_cylinder));
	init_array_list(&world->planes, sizeof(t_plane));
	init_array_list(&world->spheres, sizeof(t_sphere));
}

void	destroy_world(t_world *world)
{
	world->planes.destroy(&world->planes);
	world->spheres.destroy(&world->spheres);
	world->cylinders.destroy(&world->cylinders);
}

bool	try_add_ambient_light_to_world(char **attributes, t_world *world)
{
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != AMBIENT_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[AMBIENT_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT;
	
	if (is_invalid_format)
	{
		return (false);
	}
	is_invalid_value = \
	try_atof(attributes[AMBIENT_ATTRIBUTE_RATIO_IN_RANGE], \
	&world->ambient_light.ratio_in_range) == false \
	|| is_invalid_ratio_in_range(world->ambient_light.ratio_in_range) \
	|| try_parse_color(attributes[AMBIENT_ATTRIBUTE_COLORS], \
	&world->ambient_light.colors) == false;
	if (is_invalid_value)
	{
		return (false);
	}
	world->is_valid_ambient_light = true;
	return (true);
}

bool	try_add_camera_to_world(char **attributes, t_world *world)
{
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != CAMERA_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[CAMERA_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[CAMERA_ATTRIBUTE_ORIENTATION_VECTOR], ',') \
	!= VECTOR_ATTRIBUTE_COUNT;
	 
	if (is_invalid_format)
	{
		return (false);
	}
	is_invalid_value = \
	try_parse_vector3(attributes[CAMERA_ATTRIBUTE_COORDINATES], \
	&world->camera.coordinates) == false \
	|| try_parse_vector3(attributes[CAMERA_ATTRIBUTE_ORIENTATION_VECTOR], \
	&world->camera.normalized_orientation_vector_of_axis) == false \
	|| try_atoi(attributes[CAMERA_ATTRIBUTE_FOV], \
	&world->camera.field_of_view) == false \
	|| world->camera.field_of_view > 180 || world->camera.field_of_view < 0;
	if (is_invalid_value)
	{
		return (false);
	}
	world->is_valid_camera = true;
	return (true);
}

bool	try_add_light_to_world(char **attributes, t_world *world)
{
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
	&world->light.coordinates) == false \
	|| try_atof(attributes[LIGHT_ATTRIBUTE_RATIO_IN_RANGE], \
	&world->light.ratio_in_range) == false \
	|| is_invalid_ratio_in_range(world->light.ratio_in_range) \
	|| try_parse_color(attributes[LIGHT_ATTRIBUTE_COLORS], \
	&world->light.colors) == false;
	if (is_invalid_value)
	{
		return (false);
	}
	world->is_valid_light = true;
	return (true);
}

bool	try_parse_vector3(char *attribute, t_vector3 *out_result)
{
	char	**temp;
	bool	is_succeed_x;
	bool	is_succeed_y;
	bool	is_succeed_z;

	temp = ft_split(attribute, ',');
	is_succeed_x = try_atof(temp[0], &out_result->x);
	is_succeed_y = try_atof(temp[1], &out_result->y);
	is_succeed_z = try_atof(temp[2], &out_result->z);
	clear_words(temp);
	return (is_succeed_x && is_succeed_y && is_succeed_z);
}

bool	try_parse_color(char *attribute, int *out_result)
{
	char		**temp;
	bool		is_succeed_r;
	bool		is_succeed_g;
	bool		is_succeed_b;
	t_ivector3	colors;

	temp = ft_split(attribute, ',');
	is_succeed_r = try_atoi(temp[0], &colors.x);
	is_succeed_g = try_atoi(temp[1], &colors.y);
	is_succeed_b = try_atoi(temp[2], &colors.z);
	clear_words(temp);
	if (is_succeed_r == false || is_succeed_g == false \
	|| is_succeed_b == false || is_invalid_colors(colors))
	{
		*out_result = 0;
		return (false);
	}
	*out_result = convert_colors(colors);
	return (true);
}

int	convert_colors(t_ivector3 colors)
{
	return ((colors.x << 16) + (colors.y << 8) + colors.z);
}

bool	is_invalid_normalized_vector3(t_vector3 vector)
{
	return (vector.x > 1.0f || vector.x < -1.0f \
	|| vector.y > 1.0f || vector.y < -1.0f \
	|| vector.z > 1.0f || vector.z < -1.0f);
}

bool	is_invalid_ratio_in_range(float ratio_in_range)
{
	return (ratio_in_range < 0.0f || ratio_in_range > 1.0f);
}

bool	is_invalid_colors(t_ivector3 colors)
{
	return (colors.x > 255 || colors.x < 0 \
	|| colors.y > 255 || colors.y < 0 \
	|| colors.z > 255 || colors.z < 0);
}