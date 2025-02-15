/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:24:34 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/15 13:45:02 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_H
# define EQUATION_H
# include "ray.h"
# include "solid_shape.h"

typedef struct s_quadratic_equation
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
}	t_quadratic_equation;

t_quadratic_equation	load_hit_cylinder_equation(const t_ray ray, \
const t_cylinder cylinder);
float					calculate_cylinder_hit_height(const t_ray ray, \
const t_cylinder cylinder, float t);

#endif
