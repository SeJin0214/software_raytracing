/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:53:56 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 20:18:59 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "equation_bonus.h"
#include "cylinder_bonus.h"
#include "ft_math.h"
#include <stdio.h>

// t1      t2 
// 0    r    t2 /  
// r     lerp( (1 - t) * a + t * b ) ; 

// n * x = r^2


bool	is_hit_cone(const t_ray ray, \
const void *obj, t_hit_record *out)
{
	// const t_cone				*cone = obj;
	// const t_quadratic_equation	quadratic = load_hit_cone_equation(ray, *cone);
	// float						solution;
	// bool						is_hit;
	// float						height;

	(void) ray;
	(void) obj;
	(void) out;
	// is_hit = is_hit_down_cap(ray, cone, cone->shape.coordinates, out);
	// // 무조건 원뿔로 판별식 세워야 해
	// solution = get_quadtatic_root_minus(quadratic);
	// if (solution <= 0 || out->t <= solution)
	// {
	// 	solution = get_quadtatic_root_plus(quadratic);
	// 	if (solution <= 0 || out->t <= solution)
	// 		return (is_hit);
	// }


	// height = calculate_cylinder_hit_height(ray, *cone, solution);
	// if (quadratic.discriminant <= 0 || height > cone->height || height <= __FLT_EPSILON__)
	// 	return (is_hit);




	// t_vector3	p = get_point_in_ray(ray, solution);
	// t_vector3	c = multiply_vector3(cone->shape.local_basis.row[Z], height);
	// t_vector3	p_sub_c = subtract_vector3(p, c);
	// p_sub_c.z -= 10.f;
	// float		radius = lerp(0, cone->diameter / 2, height / cone->height);
	// if (dot_product3x3(p_sub_c, p_sub_c) > radius * radius)
	// {
	// 	return (is_hit);
	// }
	// t_vector3	vertex = cone->shape.local_basis.row[Z];
	// t_vector3	vertex_to_p = normalize_vector3(subtract_vector3(p, vertex));
	// t_vector3	proj_c = multiply_vector3(vertex_to_p, dot_product3x3(c, vertex_to_p));
	// t_vector3	normal_surface = subtract_vector3(proj_c, c);
	// // p - c 하면 되고 
	// // 이게 되는지 판별하고 
	// // 기울기로 normal 구하고

	// out->t = solution;
	// out->point = p;
	// out->normal = normal_surface;
	// out->color = get_color_at_hit_point(cone->shape, out->point);
	// out->object = (void *)cone;
	return (true);
}