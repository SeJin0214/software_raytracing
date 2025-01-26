/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:28:55 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/26 17:20:21 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "render.h"
#include "libft.h"
#include "quadratic_equation.h"

// 가능한 것은 모두 캐시로 저장하기
void	render(t_world *world, t_canvas *canvas)
{
	size_t	y;
	size_t	x;

	y = 0;

	while (y < canvas->screen.height)
	{
		float y_angle_to_convert = lerp(world->camera.y_theta, \
		-world->camera.y_theta, (float)y / canvas->screen.height);
		x = 0;
		while (x < canvas->screen.width)
		{
			float x_angle_to_convert = lerp(world->camera.x_theta, \
			-world->camera.x_theta, (float)x / canvas->screen.width);
			// ray 변경하기 
			// focal length 길이 10, focal length가 10배 커질 때마다 길이는 100배 커짐 
			// focal length 곱한 좌표  + (tan(0) * focal length 곱한 좌표) + (tan(y_angle) * focal length 곱한 좌표)
			t_vector3 direction = multiply_vector_and_matrix3x3(world->camera.normalized_orientation_vector_of_axis, \
			get_rotation_matrix(x_angle_to_convert, y_angle_to_convert, 0));
					// tan 두 개 써서 
					// camera ray 
			t_ray ray = get_ray(world->camera.coordinates, direction);
			int color = load_pixel_color(world, ray);    
			put_color_in_image_frame(canvas, (int)y, (int)x, color);
			++x;
		}
		++y;
	}
	
	// 직선 거리를 focal length라고 하나?
	// 직선 거리가 10이라면 12.1951219512 = 빗변 
	// 그래서 이동 벡터의 거리가 저 값까지인 곳만 검출하기
	
// 회전 행렬
// x, y, z

	// +theta ~ -theta 사이를 픽셀 프레임의 맞게끔 보간해줘야 한다.
	// x 각도에 맞춰서 y는 비율에 맞게 각도를 조정한다.
	// screen.y / screen.x * (fovx / 2) = y 각도
	
	// 카메라 정면이 뷰포트 중심이고, 화면 정중앙 
	
	// 외적 (직교 벡터)
	// 저 픽셀 값이 위치한 
	// 카메라 방향 벡터와      x, y, z
	
	//					 1, 0, 0     0, 1, 0    0, 0, 1   standard basis

	// 카메라 직교하는 벡터 (위와 옆) 0, 1, 1  ????????? 

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
	const float x_radian = x * 3.14 / 180;
	const float y_radian = y * 3.14 / 180;
	const float z_radian = z * 3.14 / 180;
	
	const t_matrix3x3 x_matrix = {{
		{1, 0, 0},
		{0, cos(x_radian), sin(x_radian)},
		{0, -sin(x_radian), cos(x_radian)}
	}};
	const t_matrix3x3 y_matrix = {{
		{cos(y_radian), 0, -sin(y_radian)},
		{0, 1, 0},
		{sin(y_radian), 0, cos(y_radian)}
	}};
	const t_matrix3x3 z_matrix = {{
		{cos(z_radian), sin(z_radian), 0},
		{-sin(z_radian), cos(z_radian), 0},
		{0, 0, 1},
	}};
	 
	// const t_matrix3x3	result = 
	// {{                                                                              
	// 	{ cos(z_radian) * cos(y_radian), -sin(z_radian) * cos(y_radian), sin(y_radian) },
	// 	{ cos(z_radian) * -sin(y_radian) * -sin(x_radian) + sin(z_radian) * cos(x_radian), -sin(z_radian) * -sin(y_radian) - sin(x_radian) + cos(z_radian) * cos(x_radian), -sin(x_radian) * cos(y_radian) },
	// 	{ cos(z_radian) * -sin(y_radian) * cos(x_radian) + sin(z_radian) * sin(x_radian), -sin(z_radian) * -sin(y_radian) * cos(x_radian) + cos(z_radian) * sin(x_radian), cos(y_radian) * cos(x_radian) }
	// }};
	
	t_matrix3x3 temp = multiply_matrix3x3(x_matrix, z_matrix);
	t_matrix3x3 result1 = multiply_matrix3x3(y_matrix, temp); // 전치행렬 만들어주기 
	
	//print_matrix3x3(result);
	// print_matrix3x3(transpose(result1));
	// printf("%f %f %f\n", x, y, z);
	// printf("x = %f, y = %f\n", x_radian, y_radian);
	return (transpose(result1));
}

float	lerp(const float a, const float b, const float t)
{
	return ((1 - t) * a + t * b);
}

t_ivector3	reflect_light(const t_ivector3 ligth_resource_color, const t_ivector3 surface_color)
{
	const t_ivector3	refloection_color = 
	{{
		// 1 * 0.5
		// 255 * 127 / 255
		ligth_resource_color.x * surface_color.x / 255, 
		ligth_resource_color.y * surface_color.y / 255,
		ligth_resource_color.z * surface_color.z / 255,
	}};

	return (refloection_color);
}

bool	is_hit_sphere(const t_ray ray, const t_sphere *sphere, t_hit_record *out)
{
	const t_vector3			oc = subtract_vector3(ray.origin, sphere->center);
	t_quadratic_equation	equation;
	float					discriminant;
	float					solution;

	equation.a = dot_product3x3(ray.direction, ray.direction);
	equation.b = 2.0f * dot_product3x3(oc, ray.direction);
	equation.c = dot_product3x3(oc, oc) - (sphere->diameter / 2) \
	* (sphere->diameter / 2);
	discriminant = equation.b * equation.b - 4 * equation.a * equation.c;
	if (discriminant > 0)
	{
		solution = (-equation.b - sqrt(equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution > 0 && solution < out->t) // view port max 길이까지
		{
			out->t = solution;
			out->point = get_point_in_ray(ray, out->t);
			out->normal = divide_vector3(subtract_vector3(out->point, sphere->center), sphere->diameter);
			out->color = sphere->colors;
			out->object = (void *)sphere;
			return (true);
		}
		solution = (-equation.b + sqrt(equation.b * equation.b - 4 * equation.a * equation.c)) / (2 * equation.a);
		if (solution > 0 && 0 && solution < out->t)
		{
			out->t = solution;
			out->point = get_point_in_ray(ray, out->t);
			out->normal = divide_vector3(subtract_vector3(out->point, sphere->center), sphere->diameter);
			out->color = sphere->colors;
			out->object = (void *)sphere;
			return (true);
		}
	}
	return (false);
}

bool	is_hit_plane(const t_ray ray, const t_plane *plane, t_hit_record *out)
{
	// 벡터의 직선의 방정식 
	
	// z가 방향이 앞임   0, 0, 1 이면 
	// z가 0인 평면
	
	// 0, 0.7, 0.7 이면?
	// y도 z도 x도 바뀔 수 있네?

	// A + tB 인 것은 같음

	return (false);
}

bool	is_hit_cylinder(const t_ray ray, const t_cylinder *cylinder, t_hit_record *out)
{
	return (false);
}

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
			// printf("sur = %f, hit = %f\n", get_length_in_vector3(subtract_vector3(surface, world->light.coordinates))
			// , get_length_in_vector3(subtract_vector3(hit_record.point, world->light.coordinates)));
			// // printf("bool = %d\n", ft_memcmp(&hit_record.point, &surface, sizeof(t_vector3)));
			// // printf("sphere -> ");
			// // print_vector3(sphere->center);
			// printf("surface -> ");
			// print_vector3(surface);
			// printf("hit_point -> ");
			// print_vector3(hit_record.point);
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

	while (i < world->planes.count)
	{
		t_plane *plane = world->planes.get_element_or_null(&world->planes, i);
		++i;
		is_hit_plane(ray, plane, &hit_record);
	}

	while (i < world->cylinders.count)
	{
		t_cylinder *cylinder = world->cylinders.get_element_or_null(&world->cylinders, i);
		++i;
		is_hit_cylinder(ray, cylinder, &hit_record);
	}

	if (FLT_MAX != hit_record.t)
	{
		t_vector3 surface_to_diffuse_light = subtract_vector3(world->light.coordinates, hit_record.point);
		t_vector3 direction_to_light = normalize_vector3(surface_to_diffuse_light);
		float light_intensity = fmax(dot_product3x3(direction_to_light, hit_record.normal), 0.0f);
		t_ivector3 diffuse_source_color = multiply_ivector3(world->light.colors, light_intensity);
		t_ivector3 diffuse_color = reflect_light(diffuse_source_color, hit_record.color);

		t_ivector3 ambient_color = reflect_light(world->ambient_light.colors, hit_record.color);
		t_ivector3 ambient = {{world->ambient_light.ratio_in_range * 255, world->ambient_light.ratio_in_range * 255, world->ambient_light.ratio_in_range * 255}};
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