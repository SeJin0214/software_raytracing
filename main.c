/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/11 11:56:48 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "world.h"


bool	try_parse(int argc, char **argv, t_world *out_world);
bool	is_valid_file(char *filename);
bool	try_parse_file(char *filename, t_world *out_world);
bool	try_parse_attributes(char **attributes, t_world *out_world);
void	print_world(t_world world);
void	print_plane(void *arg);
void	print_sphere(void *arg);
void	print_cylinder(void *arg);

int	main(int argc, char **argv)
{
	t_world	world;
	
	ft_memset(&world, 0, sizeof(t_world));
	if (try_parse(argc, argv, &world) == false)
	{
		printf("Error\n");
		return (1);
	}
	print_world(world);
	// 오브젝트가 모두 잘 들어갔는지 출력하기
	// 전체 다 출력 foreach 돌면서
	destroy_world(&world);
	return (0);
}

bool	try_parse(int argc, char **argv, t_world *out_world)
{
	if (argc != 2 && is_valid_file(argv[1]) == false)
	{
		return (false);
	}
	init_world(out_world);
	if (try_parse_file(argv[1], out_world) == false \
	|| out_world->is_valid_ambient_light == false \
	|| out_world->is_valid_camera == false \
	|| out_world->is_valid_light == false)	
	{
		destroy_world(out_world);
		return (false);
	}
	return (true);
}

bool	is_valid_file(char *filename)
{
	while (*filename != '\0')
	{
		if (ft_strcmp(filename, ".rt") == 0)
		{
			return (true);
		}
		++filename;
	}
	return (false);
}

bool	try_parse_file(char *filename, t_world *out_world)
{
	int			fd;
	char		*line;
	char		**attributes;
	bool		is_succeed;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	is_succeed = true;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		attributes = ft_split(line, ' ');
		if (attributes[0] != NULL)
			is_succeed = try_parse_attributes(attributes, out_world);
		clear_words(attributes);
		free(line);
		if (is_succeed == false)
			break ;
	}
	close(fd);
	return (is_succeed);
}

bool	try_parse_attributes(char **attributes, t_world *out_world)
{
	bool	is_succeed;

	if (ft_strcmp(attributes[0], "A") == 0)
	{
		is_succeed = try_add_ambient_light_to_world(attributes, out_world);
	}
	else if (ft_strcmp(attributes[0], "L") == 0)
	{
		is_succeed = try_add_light_to_world(attributes, out_world);
	}
	else if (ft_strcmp(attributes[0], "C") == 0)
	{
		is_succeed = try_add_camera_to_world(attributes, out_world);
	}
	else if (ft_strcmp(attributes[0], "sp") == 0)
	{
		is_succeed = try_add_sphere_to_world(attributes, out_world);
	}
	else if (ft_strcmp(attributes[0], "pl") == 0)
	{
		is_succeed = try_add_plane_to_world(attributes, out_world);
	}
	else if (ft_strcmp(attributes[0], "cy") == 0)
	{
		is_succeed = try_add_cylinder_to_world(attributes, out_world);
	}
	else
	{
		return (false);
	}
	return (is_succeed);
}

void	print_world(t_world world)
{
	printf("---------------------ambient_light------------------\n");
	printf("color->%d|\n", world.ambient_light.colors);
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
	printf("color->%d|\n", world.light.colors);
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
	
	printf("color->%d|\n", plane->colors);
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

	printf("color->%d|\n", sphere->colors);
	printf("center->%f\n", sphere->center.x);
	printf("center->%f\n", sphere->center.y);
	printf("center->%f\n", sphere->center.z);
	printf("diameter->%f\n", sphere->diameter);
	printf("\n\n");
}

void	print_cylinder(void *arg)
{
	t_cylinder	*cylinder = arg;

	printf("color->%d|\n", cylinder->colors);
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