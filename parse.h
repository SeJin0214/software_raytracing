/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejjeong <sejjeong@student.42gyeongsan>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:20:41 by sejjeong          #+#    #+#             */
/*   Updated: 2025/01/23 10:39:55 by sejjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "world.h"
# include "canvas.h"

bool	try_parse(int argc, char **argv, t_world *out_world, t_canvas *canvas);
bool	is_valid_file(char *filename);
bool	try_parse_file(char *filename, t_world *out_world, t_canvas *canvas);
bool	try_parse_attributes(char **attributes, t_world *out_world, t_canvas *canvas);

#endif