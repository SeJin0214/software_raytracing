/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/26 16:23:40 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "world.h"
#include "mlx.h"
#include "mlx_int.h"
#include "canvas.h"
#include "parse.h"
#include "render.h"
#define X_BUTTON (17)


void	print_world(t_world world);
void	print_plane(void *arg);
void	print_sphere(void *arg);
void	print_cylinder(void *arg);


// transform 컴포넌트를 들고 있어야 할 거 같다.

// 카메라 위치로 보여주는 것 

// 카메라 시선에 보여주기 

// fov

// viewport

// 월드 좌표 -> 카메라 좌표

// 자르는 과정이 클립 스페이스를 이용
// 어디까지 클리핑 하는 가?

// 회전, 무브, 스케일 (모델링 행렬)

// 뷰 행렬

// 원근 투영

// point

// 벡터의 방정식

// 좌표를 찍긴 했지만, 가득 채워줄 래스터라이저가 필요하긴 하다.


int	main(int argc, char **argv)
{
	t_world		world;
	t_canvas	canvas;

	ft_memset(&world, 0, sizeof(t_world));
	init_canvas(&canvas);
	if (try_parse(argc, argv, &world, &canvas) == false)
	{
		printf("Error\n");
		return (1);
	}
	//print_world(world);

	// update_camera
	// update_light
	render(&world, &canvas);
	
	mlx_hook(canvas.win, X_BUTTON, 0, mlx_loop_end, canvas.xvar);
	mlx_loop(canvas.xvar);
	free_canvas(&canvas);
	destroy_world(&world);
	return (0);
}


void	print_world(t_world world)
{
	printf("---------------------ambient_light------------------\n");
	printf("color->%d, %d, %d|\n", world.ambient_light.colors.x, world.ambient_light.colors.y, world.ambient_light.colors.z);
	printf("ratio_in_range->%f|\n", world.ambient_light.ratio_in_range);
	printf("\n\n\n");

	printf("---------------------camera------------------\n");
	printf("cordinate_x->%f\n", world.camera.coordinates.x);
	printf("cordinate_y->%f\n", world.camera.coordinates.y);
	printf("cordinate_z->%f\n", world.camera.coordinates.z);
	printf("field_of_view->%d\n", world.camera.field_of_view);
	printf("normalized_orientation_vector_of_axis_x->%f\n", world.camera.normalized_orientation_vector_of_axis.x);
	printf("normalized_orientation_vector_of_axis_y->%f\n", world.camera.normalized_orientation_vector_of_axis.y);
	printf("normalized_orientation_vector_of_axis_z->%f\n", world.camera.normalized_orientation_vector_of_axis.z);
	printf("\n\n\n");

	printf("---------------------light------------------\n");
	printf("color->%d, %d, %d|\n", world.light.colors.x, world.light.colors.y, world.light.colors.z);
	printf("cordinate_x->%f\n", world.light.coordinates.x);
	printf("cordinate_y->%f\n", world.light.coordinates.y);
	printf("cordinate_z->%f\n", world.light.coordinates.z);
	printf("ratio_in_range->%f|\n", world.light.ratio_in_range);
	printf("\n\n\n");

	printf("---------------------plane------------------\n");
	world.planes.foreach(&world.planes, print_plane);
	printf("\n\n\n");

	printf("---------------------sphere------------------\n");
	world.spheres.foreach(&world.spheres, print_sphere);
	printf("\n\n\n");

	printf("---------------------cylinder------------------\n");
	world.cylinders.foreach(&world.cylinders, print_cylinder);
	printf("\n\n\n");
}

void	print_plane(void *arg)
{
	t_plane	*plane = arg;
	
	printf("color->%d, %d, %d|\n", plane->colors.x, plane->colors.y, plane->colors.z);
	printf("cordinate_x->%f\n", plane->coordinates.x);
	printf("cordinate_y->%f\n", plane->coordinates.y);
	printf("cordinate_z->%f\n", plane->coordinates.z);
	printf("normalized_orientation_vector_of_axis_x->%f\n", plane->normalized_orientation_vector_of_axis.x);
	printf("normalized_orientation_vector_of_axis_y->%f\n", plane->normalized_orientation_vector_of_axis.y);
	printf("normalized_orientation_vector_of_axis_z->%f\n", plane->normalized_orientation_vector_of_axis.z);
	printf("\n\n");
}

void	print_sphere(void *arg)
{
	t_sphere	*sphere = arg;

	printf("color->%d, %d, %d|\n", sphere->colors.x, sphere->colors.y, sphere->colors.z);
	printf("center-> x = %f, y = %f, z = %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
	printf("diameter->%f\n", sphere->diameter);

	// for (size_t i = 0; i < sphere->points.count; ++i)
	// {
	// 	t_vector4 *point = sphere->points.get_element_or_null(&sphere->points, i);
	// 	printf("x = %f, y = %f, z = %f, a = %f\n", point->x, point->y, point->z, point->a);
	// }
	printf("\n\n");
}

void	print_cylinder(void *arg)
{
	t_cylinder	*cylinder = arg;

	printf("color->%d, %d, %d|\n", cylinder->colors.x, cylinder->colors.y, cylinder->colors.z);
	printf("cordinate_x->%f\n", cylinder->coordinates.x);
	printf("cordinate_y->%f\n", cylinder->coordinates.y);
	printf("cordinate_z->%f\n", cylinder->coordinates.z);
	printf("diameter->%f\n", cylinder->diameter);
	printf("height->%f|\n", cylinder->height);
	printf("normalized_orientation_vector_of_axis_x->%f\n", cylinder->normalized_orientation_vector_of_axis.x);
	printf("normalized_orientation_vector_of_axis_y->%f\n", cylinder->normalized_orientation_vector_of_axis.y);
	printf("normalized_orientation_vector_of_axis_z->%f\n", cylinder->normalized_orientation_vector_of_axis.z);
	printf("\n\n");
}