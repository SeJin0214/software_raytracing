/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:27:10 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 08:07:13 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "solid_shape.h"

typedef struct s_sphere
{
	t_solid_shape	shape;
	float			diameter;
}	t_sphere;

/* sphere.c */
t_sphere	*copy_construction_to_sphere(const t_sphere sphere);
void		delete_sphere(void *obj);
bool		is_hit_sphere(const t_ray ray, \
const void *sphere, t_hit_record *out);

inline void	set_hit_record_by_sphere(t_hit_record *out, \
const float solution, const t_ray ray, const t_sphere *sphere)
{
	out->t = solution;
	out->point = get_point_in_ray(ray, out->t);
	out->normal = normalize_vector3(subtract_vector3(out->point, \
	sphere->shape.coordinates));
	out->color = sphere->shape.colors;
	out->object = (void *)sphere;
}

/* sphere_action.c */
void		update_scale_diameter_sphere(void *sphere, \
const t_action action);
void		update_scale_height_sphere(void *sphere, \
const t_action action);

#endif