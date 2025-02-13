/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/02/13 16:24:41 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"
#include "float.h"
#include "libft.h"
#include "equation.h"

#define PI 3.141592f

void	render(t_world *world, t_canvas *canvas)
{
	size_t	y;
	size_t	x;
	float	y_angle_to_convert;
	float	x_angle_to_convert;
	int		color;

	y = 0;
	while (y < canvas->screen.height)
	{
		y_angle_to_convert = lerp(world->camera.y_theta, 
		-world->camera.y_theta, (float)y / canvas->screen.height);
		x = 0;
		while (x < canvas->screen.width)
		{
			t_vector3 y_axis_vec = multiply_vector3(world->camera.local_basis.row[Y], tanf(get_radian(y_angle_to_convert)));
			x_angle_to_convert = lerp(-world->camera.x_theta, world->camera.x_theta, (float)x / canvas->screen.width);
			
			t_vector3 x_axis_vec = multiply_vector3(world->camera.local_basis.row[X], tanf(get_radian(x_angle_to_convert)));
			t_vector3 direction = normalize_vector3(add_vector3(world->camera.local_basis.row[Z], add_vector3(y_axis_vec, x_axis_vec)));
			
			t_ray ray = get_ray(world->camera.coordinates, direction);
			color = load_pixel_color(world, ray);
			put_color_in_image_frame(canvas, (int)x, (int)y, color);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(canvas->xvar, canvas->win, \
			canvas->img, 0, 0);
}

void	put_color_in_image_frame(t_canvas *canvas, const int x, \
const int y, const int color)
{
	int			*image_frame_buffer;
	const int	offset = canvas->screen.width * y + x;

	image_frame_buffer = (int *)canvas->img->data;
	if (x >= 0 && y >= 0 && y < (int)canvas->screen.height \
			&& x < (int)canvas->screen.width)
	{
		*(image_frame_buffer + offset) = color;
	}
}

t_matrix3x3	get_rotation_matrix(const float x, const float y, const float z)
{
	const t_vector3	radian = {{ get_radian(x), get_radian(y), get_radian(z) }};
	const t_matrix3x3 x_matrix = {{
		{1, 0, 0},
		{0, cosf(radian.x), sinf(radian.x)},
		{0, -sinf(radian.x), cosf(radian.x)}
	}};
	const t_matrix3x3 y_matrix = {{
		{cosf(radian.y), 0, -sinf(radian.y)},
		{0, 1, 0},
		{sinf(radian.y), 0, cosf(radian.y)}
	}};
	const t_matrix3x3 z_matrix = {{
		{cosf(radian.z), sinf(radian.z), 0},
		{-sinf(radian.z), cosf(radian.z), 0},
		{0, 0, 1},
	}};
	
	return (transpose(multiply_matrix3x3(x_matrix, \
	multiply_matrix3x3(z_matrix, y_matrix))));
}

t_ivector3	reflect_light(const t_ivector3 ligth_resource_color, const t_ivector3 surface_color)
{
	const t_ivector3	refloection_color = \
	{{\
		ligth_resource_color.x * surface_color.x / 255, \
		ligth_resource_color.y * surface_color.y / 255, \
		ligth_resource_color.z * surface_color.z / 255, \
	}};

	return (refloection_color);
}

bool	is_hit_sphere(const t_ray ray, const t_sphere *sphere, t_hit_record *out)
{
	const t_vector3			oc = subtract_vector3(ray.origin, sphere->center);
	t_quadratic_equation	equation;
	float					solution;

	equation.a = dot_product3x3(ray.direction, ray.direction);
	equation.b = 2.0f * dot_product3x3(oc, ray.direction);
	equation.c = dot_product3x3(oc, oc) - (sphere->diameter / 2) \
	* (sphere->diameter / 2);
	equation.discriminant = equation.b * equation.b \
	- 4 * equation.a * equation.c;
	if (equation.discriminant <= 0)
		return (false);
	solution = (-equation.b - sqrtf(equation.b * equation.b \
	- 4 * equation.a * equation.c)) / (2 * equation.a);
	if (solution <= 0 || out->t <= solution)
	{
		solution = (-equation.b + sqrtf(equation.b * equation.b \
		- 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution <= 0 || out->t <= solution)
			return (false);
	}
	out->t = solution;
	out->point = get_point_in_ray(ray, out->t);
	out->normal = divide_vector3(subtract_vector3(out->point, \
	sphere->center), sphere->diameter);
	out->color = sphere->colors;
	out->object = (void *)sphere;
	return (true);
}

bool	is_hit_cylinder(const t_ray ray, const t_cylinder *cylinder, t_hit_record *out)
{
	const t_quadratic_equation	equation = load_hit_cylinder_equation(ray, *cylinder);
	float						solution;
	float						height;
	
	solution = (-equation.b - sqrtf(equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
	if (solution <= 0 || out->t <= solution)
	{
		solution = (-equation.b + sqrtf(equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution <= 0 || out->t <= solution)
		{
			return (false);
		}
	}
	height = calculate_cylinder_hit_height(ray, *cylinder, solution);
	if (equation.discriminant > 0 && height <= cylinder->height / 2)
	{
		out->t = solution;
		out->point = get_point_in_ray(ray, out->t);
		out->normal = divide_vector3(subtract_vector3(out->point, cylinder->coordinates), cylinder->diameter / 2);
		out->color = cylinder->colors;
		out->object = (void *)cylinder;
		return (true);
	}
	// (p - c) * N = 0
	// (O + sD - (C + hB)) * N = 0
	// NO + sND - NC = 0
	// s = N(C + hB - O) / ND 
	
	const t_vector3	n = cylinder->normalized_orientation_vector_of_axis;
	const t_ray		upward_ray = get_ray(cylinder->coordinates, n);
	const t_vector3	up_c = get_point_in_ray(upward_ray, cylinder->height / 2); 
	//  C + hB : up_c or down_c
	//  O + sD : 
	float		numerator = dot_product3x3(n, \
	subtract_vector3(up_c, ray.origin));
	float		denominator = dot_product3x3(n, ray.direction);
	if (denominator != 0 \
	|| numerator / denominator > 0 \
	|| numerator / denominator < out->t)
	{
		solution = numerator / denominator;
		const t_vector3 p = get_point_in_ray(ray, solution);
		t_vector3 p_sub_c = subtract_vector3(p, up_c);
		if (dot_product3x3(p_sub_c, p_sub_c) < (cylinder->diameter / 2) * (cylinder->diameter / 2))
		{
			out->t = solution;
			out->point = p;
			out->normal = n;
			out->color = cylinder->colors;
			out->object = (void *)cylinder;
			return (true);
		}
	}
	const t_vector3 down_c = get_point_in_ray(upward_ray, -(cylinder->height / 2));
	
	numerator = dot_product3x3(n, \
	subtract_vector3(down_c, ray.origin));
	denominator = dot_product3x3(n, ray.direction);
	if (denominator != 0 || numerator / denominator > 0 || numerator / denominator < out->t)
	{
		solution = numerator / denominator;
		const t_vector3 p = get_point_in_ray(ray, solution);
		t_vector3 p_sub_c = subtract_vector3(p, down_c);
		if (dot_product3x3(p_sub_c, p_sub_c) < (cylinder->diameter / 2) * (cylinder->diameter / 2))
		{
			out->t = solution;
			out->point = p;
			out->normal = multiply_vector3(n, -1);
			out->color = cylinder->colors;
			out->object = (void *)cylinder;
			return (true);
		}
	}
	return (false);
}

// 다형성을 구현해보는게 좋을 수도?
// 아마 플레인 밑으로는 그림자가 없을 거임
// 실린더 밑에도 ㅇㅋ
bool	is_shadowed_surface(t_world *world, const t_vector3 surface, void *object)
{
	const t_ray		ray = get_ray(world->light.coordinates, \
	normalize_vector3(subtract_vector3(surface, world->light.coordinates)));
	t_hit_record	hit_record;
	size_t			i;

	i = 0;
	hit_record = get_hit_record();
	while (i < world->spheres.count)
	{
		t_sphere *sphere = world->spheres.get_element_or_null(&world->spheres, i);
		++i;
		// 거리가 더 먼 것을 찍어야 함
		// record 는 늘 작은 게 우선
		if (object == sphere)
		{
			continue;
		}
		// 다 돌고 나면 늘 surface가 더 클 거임
		if (is_hit_sphere(ray, sphere, &hit_record) 
		&& get_length_in_vector3(subtract_vector3(surface, world->light.coordinates)) \
		> get_length_in_vector3(subtract_vector3(hit_record.point, world->light.coordinates)))
		{
			return (true);
		}
	}
	return (false);
}

int	load_pixel_color(t_world *world, const t_ray ray)
{
	t_ivector3		result;
	size_t			i;
	t_hit_record	hit_record;

	i = 0;
	hit_record = get_hit_record();
	while (i < world->spheres.count)
	{
		t_sphere *sphere = world->spheres.get_element_or_null(&world->spheres, i);
		++i;
		is_hit_sphere(ray, sphere, &hit_record);
	}

	i = 0;
	while (i < world->planes.count)
	{
		t_plane *plane = world->planes.get_element_or_null(&world->planes, i);
		++i;
		is_hit_plane(ray, plane, &hit_record);
	}

	i = 0;
	while (i < world->cylinders.count)
	{
		t_cylinder *cylinder = world->cylinders.get_element_or_null(&world->cylinders, i);
		++i;
		is_hit_cylinder(ray, cylinder, &hit_record);
	}

	if (is_collision(hit_record))
	{
		t_vector3 surface_to_diffuse_light = subtract_vector3(world->light.coordinates, hit_record.point);
		t_vector3 direction_to_light = normalize_vector3(surface_to_diffuse_light);
		float light_intensity = fmax(dot_product3x3(direction_to_light, hit_record.normal), 0.0f);
		t_ivector3 diffuse_source_color = multiply_ivector3(world->light.colors, light_intensity);
		t_ivector3 diffuse_color = reflect_light(diffuse_source_color, hit_record.color);
		t_ivector3 ambient_color = reflect_light(world->ambient_light.colors, hit_record.color);
		float ratio_in_range = world->ambient_light.ratio_in_range;
		t_ivector3 ambient = get_ivector3(ratio_in_range * 255, ratio_in_range * 255, ratio_in_range * 255);
		ambient_color = reflect_light(ambient, ambient_color);
		result = add_color(diffuse_color, ambient_color);
		if (is_shadowed_surface(world, hit_record.point, hit_record.object))
		{
			result.x /= 2;
			result.y /= 2;
			result.z /= 2;
		}
		return (convert_colors(result));
	}
	return convert_colors((t_ivector3){{0, 0, 0}});
}

t_ivector3	add_color(const t_ivector3 color0, const t_ivector3 color1)
{
	t_ivector3	result;

	result.x = get_min(color0.x + color1.x , 255);
	result.y = get_min(color0.y + color1.y , 255);
	result.z = get_min(color0.z + color1.z , 255);
	return (result);
}

bool	is_collision(const t_hit_record record)
{
	return (FLT_MAX != record.t);
}

float	get_radian(const float degree)
{
	return (degree * PI / 180);
}