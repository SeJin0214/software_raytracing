/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape_getter_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:14:03 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/27 02:55:42 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_SHAPE_GETTER_BONUS_H
# define SOLID_SHAPE_GETTER_BONUS_H
# include "solid_shape_bonus.h"
# include "render_bonus.h"

inline t_ivector3	get_checkerboard_color_at_hit_point(\
const void *shape, const t_vector3 hit_point)
{
	const t_solid_shape	*sh = shape;
	const t_vector2		uv = sh->get_uv_coordinate(sh, hit_point);

	if ((int)floor((uv.x * sh->checkerboard_scale) + (int)floor(uv.y * sh->checkerboard_scale)) % 2 == 0)
	{
		//printf("uv.x %d, y %d\n", uv.x, uv.y);
		return (get_ivector3(0, 0, 0));
	}
	return (get_ivector3(255, 255, 255));
}

inline t_ivector3	get_image_color_at_hit_point(\
const void *shape, const t_vector3 hit_point)
{
	const t_solid_shape	*sh = shape;
	const t_vector2		uv = sh->get_uv_coordinate(sh, hit_point);
	const t_ivector2	xy = {{ uv.x * sh->texture.width, uv.y * sh->texture.height }};
	int					offset = sh->texture.width * xy.y + xy.x;
	int					*image_frame_buffer;

	if (xy.y < 0)
	{
		offset += sh->texture.height;
	}
	if (xy.x < 0)
	{
		offset += sh->texture.width;
	}
	if (xy.y < 0 || xy.x < 0 || xy.y >= sh->texture.height \
	|| xy.x >= sh->texture.width)
	{
		return (get_ivector3(0, 0, 0));
	}
	image_frame_buffer = (int *)sh->texture.image->data;
	return (convert_color_to_ivec3(*(image_frame_buffer + offset)));
}

inline t_vector3	get_normal_at_hit_point(const void *shape, \
const t_vector3 n, const t_vector3 hit_point)
{
	const t_solid_shape	*sh = shape;
	t_ivector3			color;

	if (sh->texture_type == TEXTURE_BASIC \
	|| sh->texture_type == TEXTURE_CHECKERBOARD)
	{
		return (n);
	}
	else if (sh->texture_type == TEXTURE_IMAGE)
	{
		color = get_image_color_at_hit_point(sh, hit_point);
		(void) color;
		return (n);
	}
	ft_assert(false, "invalid texture type");
	return (n);
}

inline t_ivector3	get_color_at_hit_point(const void *shape, \
const t_vector3 hit_point)
{
	const t_solid_shape	*sh = shape; 
	
	if (sh->texture_type == TEXTURE_BASIC)
	{
		return (sh->colors);
	}
	else if (sh->texture_type == TEXTURE_CHECKERBOARD)
	{
		return (get_checkerboard_color_at_hit_point(sh, hit_point));
	}
	else if (sh->texture_type == TEXTURE_IMAGE)
	{
		return (get_image_color_at_hit_point(sh, hit_point));
	}
	ft_assert(false, "get_color_at_hit_point, invalid texture type");
	return (sh->colors);
}

#endif