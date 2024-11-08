/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:08:45 by sejjeong          #+#    #+#             */
/*   Updated: 2024/11/08 19:10:57 by sejjeong         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_world	world;
	
	if (try_parse(argc, argv, &world) == false)
	{
		printf("Error\n");
		return (1);
	}

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
	if (try_parse_file(argv[1], out_world) == false)
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
