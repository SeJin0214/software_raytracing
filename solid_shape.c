/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:29 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/08 19:09:22 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "world.h"
#include "solid_shape.h"

bool	try_add_sphere_to_world(char **attributes, t_world *world)
{
	t_sphere	sphere;
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != SPHERE_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[SPHERE_ATTRIBUTE_CENTER], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[SPHERE_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT;
	
	if (is_invalid_format)
	{
		return (false);
	}
	is_invalid_value = \
	try_parse_vector3(attributes[SPHERE_ATTRIBUTE_CENTER], \
	&sphere.center) == false \
	|| try_atof(attributes[SPHERE_ATTRIBUTE_DIAMETER], \
	&sphere.diameter) == false \
	|| try_parse_color(attributes[SPHERE_ATTRIBUTE_COLORS], \
	&sphere.colors) == false;
	if (is_invalid_value)
	{
		return (false);
	}
	world->spheres.add(&world->spheres, &sphere);
	return (true);
}

bool	try_add_plane_to_world(char **attributes, t_world *world)
{
	t_plane		plane;
	bool		is_invalid_value;
	const bool	is_invalid_format = \
	get_count_to_words(attributes) != PLANE_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[PLANE_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[PLANE_ATTRIBUTE_ORIENTATION_VECTOR], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[PLANE_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT;
	
	if (is_invalid_format)
		return (false);
	is_invalid_value = \
	try_parse_vector3(attributes[PLANE_ATTRIBUTE_COORDINATES], \
	&plane.coordinates) == false \
	|| try_parse_vector3(attributes[PLANE_ATTRIBUTE_ORIENTATION_VECTOR], \
	&plane.normalized_orientation_vector_of_axis) == false \
	|| is_invalid_normalized_vector3(plane.\
	normalized_orientation_vector_of_axis) \
	|| try_parse_color(attributes[PLANE_ATTRIBUTE_COLORS], \
	&plane.colors) == false;
	if (is_invalid_value)
	{
		printf("x %.65f\n", plane.normalized_orientation_vector_of_axis.x);
		printf("y %.65f\n", plane.normalized_orientation_vector_of_axis.y);
		printf("z %.65f\n", plane.normalized_orientation_vector_of_axis.z);
		return (false);
	}
	world->planes.add(&world->planes, &plane);
	return (true);
}

bool	try_add_cylinder_to_world(char **attributes, t_world *world)
{
	t_cylinder	cylinder;

	// 다 개수 체크해야해
	if (get_count_to_words(attributes) != CYLINDER_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[CYLINDER_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[CYLINDER_ATTRIBUTE_NORMALIZED_VECTOR], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[CYLINDER_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT)
		return (false);
	if (try_parse_vector3(attributes[CYLINDER_ATTRIBUTE_COORDINATES], \
	&cylinder.coordinates) == false \
	|| try_parse_vector3(attributes[CYLINDER_ATTRIBUTE_NORMALIZED_VECTOR], \
	&cylinder.normalized_orientation_vector_of_axis) == false \
	|| is_invalid_normalized_vector3(cylinder.\
	normalized_orientation_vector_of_axis) \
	|| try_atof(attributes[CYLINDER_ATTRIBUTE_DIAMETER], \
	&cylinder.diameter) == false || try_atof(\
	attributes[CYLINDER_ATTRIBUTE_HEIGHT], &cylinder.height) == false \
	|| try_parse_color(attributes[CYLINDER_ATTRIBUTE_COLORS], \
	&cylinder.colors) == false)
		return (false);
	world->cylinders.add(&world->cylinders, &cylinder);
	return (true);
}
