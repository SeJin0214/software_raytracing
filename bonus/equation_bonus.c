/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:22:38 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/22 16:38:57 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "equation_bonus.h"
#include "vector.h"

extern inline t_quadratic_equation	load_hit_cy_equation(const t_ray ray, \
const t_cylinder cylinder);
extern inline t_quadratic_equation	load_hit_cone_equation(const t_ray ray, \
const t_cone cone);
extern inline float					calculate_cylinder_hit_height(\
const t_ray ray, const t_cylinder cylinder, float t);
extern inline float	get_quadtatic_root_plus(\
const t_quadratic_equation quadtatic);
extern inline float	get_quadtatic_root_minus(\
const t_quadratic_equation quadtatic);
