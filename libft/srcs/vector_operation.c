/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:01:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/18 14:35:18 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdalign.h>
#include "vector.h"
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

extern inline t_vector3	add_vector3(const t_vector3 v0, const t_vector3 v1);

extern inline t_vector3	subtract_vector3(const t_vector3 v0, \
const t_vector3 v1);

extern inline t_vector3	multiply_vector3(const t_vector3 v, const float t);

extern inline t_vector3	divide_vector3(const t_vector3 v, const float t);
