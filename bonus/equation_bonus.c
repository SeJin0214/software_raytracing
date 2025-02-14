/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:22:38 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/14 16:47:34 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "equation_bonus.h"
#include "vector.h"

/**
 * O  : camera origin
 * P  : camera Ray -> O + t0D
 * C  : cylinder center
 * N  : cylinder normal
 * F  : P - C,    hypotenuse 
 * G  : (N * F) * N,  perpendicular     (N * (O + t0D - C))
 * r' : F - G,    base
 * r' dot r' = r^2
 * M : O - C
 * M┵ = M - N(M * N)
 * D┴ = D - N(D * N)
 * || (F - G) dot (F - G) ||^2 = r^2
 * || (P - C - G) ||^2 = r^2
 * || ((M + t0D) - N(M + t0D) * N) ||^2 = r^2
 * || (M + t0D - N(N * M) - t0N(N * D)) ||^2 = r^2
 * || (M - N(M * N) + t0(D - N(D * N)) ||^2 = r^2
 * || M┵ + tD┴ ||^2 = r^2
 * (M┵ + tD┴) * (M┵ + tD┴) = r^2
 * (D┴ * D┴)t^2 + 2t(D┴ * M┵) + (M┵ * M┵) - r^2 = 0
 * a : (D┴ * D┴)
 * b : 2 * (D┴ * M┵)
 * c : (M┵ * M┵) - r^2
*/

t_quadratic_equation	load_hit_cylinder_equation(const t_ray ray, \
const t_cylinder cylinder)
{
	t_quadratic_equation	result;
	const t_vector3			n = cylinder.normalized_orientation_vector_of_axis;
	const t_vector3			m = subtract_vector3(ray.origin, \
	cylinder.shape.coordinates);
	const t_vector3			orthogonal_d = subtract_vector3(ray.direction, \
	multiply_vector3(n, dot_product3x3(ray.direction, n)));
	const t_vector3			orthogonal_m = subtract_vector3(m, \
	multiply_vector3(n, dot_product3x3(m, n)));

	result.a = dot_product3x3(orthogonal_d, orthogonal_d);
	result.b = 2.0f * dot_product3x3(orthogonal_d, orthogonal_m);
	result.c = dot_product3x3(orthogonal_m, orthogonal_m) \
	- (cylinder.diameter / 2) * (cylinder.diameter / 2);
	result.discriminant = result.b * result.b - 4.0f * result.a * result.c;
	return (result);
}

float	calculate_cylinder_hit_height(const t_ray ray, \
const t_cylinder cylinder, float t)
{
	const t_vector3	n = cylinder.normalized_orientation_vector_of_axis;
	const t_vector3	p = add_vector3(ray.origin, \
	multiply_vector3(ray.direction, t));

	return (fabsf(dot_product3x3(n, \
	subtract_vector3(p, cylinder.shape.coordinates))));
}
