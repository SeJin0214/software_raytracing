/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:24:34 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/25 15:11:09 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_BONUS_H
# define EQUATION_BONUS_H
# include "ray_bonus.h"
# include "cylinder_bonus.h"
# include "cone_bonus.h"

typedef struct s_quadratic_equation
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
}	t_quadratic_equation;

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
 * N * F = height
*/

inline t_quadratic_equation	load_hit_cy_equation(const t_ray ray, \
const t_cylinder cylinder)
{
	t_quadratic_equation	result;
	const t_vector3			n = cylinder.shape.local_basis.row[Z];
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

inline t_quadratic_equation	load_hit_cone_equation(const t_ray ray, \
const t_cone cone)
{
	t_quadratic_equation	result;
	
	result.a = 0;
	(void) ray;
	(void) cone;
	return (result);
}

inline float	calculate_cylinder_hit_height(const t_ray ray, \
const t_cylinder cylinder, float t)
{
	const t_vector3	n = cylinder.shape.local_basis.row[Z];
	const t_vector3	p = get_point_in_ray(ray, t);

	return (dot_product3x3(n, \
	subtract_vector3(p, cylinder.shape.coordinates)));
}

inline float	get_quadtatic_root_plus(const t_quadratic_equation quadtatic)
{
	return ((-quadtatic.b + sqrtf(quadtatic.b * quadtatic.b \
	- 4 * quadtatic.a * quadtatic.c)) / (2 * quadtatic.a));
}

inline float	get_quadtatic_root_minus(const t_quadratic_equation quadtatic)
{
	return ((-quadtatic.b - sqrtf(quadtatic.b * quadtatic.b \
	- 4 * quadtatic.a * quadtatic.c)) / (2 * quadtatic.a));
}

#endif
