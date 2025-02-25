/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_shape_getter_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:14:03 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/26 07:10:49 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_SHAPE_GETTER_BONUS_H
# define SOLID_SHAPE_GETTER_BONUS_H
# include "solid_shape_bonus.h"
# include "render_bonus.h"
# define CHECKERBOARD_SCALE 80

inline t_ivector3	get_checkerboard_color_at_hit_point(\
const t_solid_shape shape, const t_vector3 hit_point)
{
	const t_ivector2	uv = shape.get_uv_coordinate(&shape, hit_point);

	if ((uv.y / CHECKERBOARD_SCALE % 2 == 0 \
	&& uv.x / CHECKERBOARD_SCALE % 2 != 0) 
	|| (uv.y / CHECKERBOARD_SCALE % 2 != 0 \
	&& uv.x / CHECKERBOARD_SCALE % 2 == 0))
	{
		return (get_ivector3(0, 0, 0));
	}
	return (get_ivector3(255, 255, 255));
}

inline t_ivector3	get_image_color_at_hit_point(\
const t_solid_shape shape, const t_vector3 hit_point)
{
	t_ivector2	uv = shape.get_uv_coordinate(&shape, hit_point);
	int			offset = shape.texture.width * uv.y + uv.x;
	int			color;
	int			*image_frame_buffer;

	if (uv.y < 0)
	{
		offset += shape.texture.height;
	}
	if (uv.x < 0)
	{
		offset += shape.texture.width;
	}
	if (uv.y < 0 || uv.x < 0 || uv.y >= shape.texture.height \
	|| uv.x >= shape.texture.width)
	{
		//printf("%d %d \n", uv.y, uv.x);
		return (get_ivector3(0, 0, 0));
	}
	image_frame_buffer = (int *)shape.texture.image->data;
	color = *(image_frame_buffer + offset);	
	return (convert_color_to_ivec3(color));
}

inline t_vector3	get_normal_at_hit_point(const t_solid_shape shape, \
const t_vector3 n, const t_vector3 hit_point)
{
	t_ivector3	color;

	if (shape.texture_type == TEXTURE_BASIC \
	|| shape.texture_type == TEXTURE_CHECKERBOARD)
	{
		return (n);
	}
	else if (shape.texture_type == TEXTURE_IMAGE)
	{
		color = get_image_color_at_hit_point(shape, hit_point);
		(void) color;
		return (n);
	}
	ft_assert(false, "invalid texture type");
	return (n);
}

inline t_ivector3	get_color_at_hit_point(const t_solid_shape shape, \
const t_vector3 hit_point)
{
	if (shape.texture_type == TEXTURE_BASIC)
	{
		return (shape.colors);
	}
	else if (shape.texture_type == TEXTURE_CHECKERBOARD)
	{
		return (get_checkerboard_color_at_hit_point(shape, hit_point));
	}
	else if (shape.texture_type == TEXTURE_IMAGE)
	{
		return (get_image_color_at_hit_point(shape, hit_point));
	}
	ft_assert(false, "get_color_at_hit_point, invalid texture type");
	return (shape.colors);
}

#endif