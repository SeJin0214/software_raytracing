/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:21:41 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 15:17:01 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	init_camera(t_world *world, t_canvas *canvas)
{
	world->camera.local_basis.row[Z] = \
	normalize_vector3(world->camera.local_basis.row[Z]);
	world->camera.local_basis = get_local_basis(\
	world->camera.local_basis.row[Z]);
	world->camera.x_theta = world->camera.field_of_view / 2.0f;
	world->camera.y_theta = world->camera.x_theta * \
	((float)canvas->screen.height / canvas->screen.width);
	world->is_valid_camera = true;
}
