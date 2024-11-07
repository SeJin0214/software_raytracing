/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:49:29 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/07 20:32:42 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "world.h"
#include "solid_shape.h"

bool	try_add_sphere_to_world(char **attributes, t_world *world)
{
	if (get_count_to_words(attributes) != SPHERE_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[SPHERE_ATTRIBUTE_CENTER], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[SPHERE_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT)
	{
		return (false);
	}
	
}

bool	try_add_plane_to_world(char **attributes, t_world *world)
{
	if (get_count_to_words(attributes) != PLANE_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[PLANE_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[PLANE_ATTRIBUTE_ORIENTATION_VECTOR], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[PLANE_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT)
	{
		return (false);
	}	
}

bool	try_add_cylinder_to_world(char **attributes, t_world *world)
{
	if (get_count_to_words(attributes) != CYLINDER_ATTRIBUTE_LENGTH \
	|| get_count_words(attributes[CYLINDER_ATTRIBUTE_COORDINATES], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[CYLINDER_ATTRIBUTE_NORMALIZED_VECTOR], ',') \
	!= VECTOR_ATTRIBUTE_COUNT \
	|| get_count_words(attributes[CYLINDER_ATTRIBUTE_COLORS], ',') \
	!= COLORS_ATTRIBUTE_COUNT)
	{
		return (false);
	}
}
