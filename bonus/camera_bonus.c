/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:21:41 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 16:47:22 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world_bonus.h"

void	init_camera(t_world *world, t_canvas *canvas)
{
	t_vector3	n;
	t_vector3	up;

	world->camera.normalized_orientation_vector_of_axis = \
	normalize_vector3(world->camera.normalized_orientation_vector_of_axis);
	n = world->camera.normalized_orientation_vector_of_axis;
	up = get_vector3(0.0f, 1.0f, 0.0f);
	if (is_uneqaul_vector3(up, n) == false)
	{
		up = get_vector3(0.0f, 0.0f, -1.0f);
	}
	world->camera.local_basis.row[X] = cross_product3x3(up, n);
	world->camera.local_basis.row[Y] = \
	cross_product3x3(n, world->camera.local_basis.row[X]);
	world->camera.local_basis.row[Z] = n;
	world->camera.x_theta = world->camera.field_of_view / 2.0f;
	world->camera.y_theta = world->camera.x_theta * \
	((float)canvas->screen.height / canvas->screen.width);
	world->is_valid_camera = true;
}
