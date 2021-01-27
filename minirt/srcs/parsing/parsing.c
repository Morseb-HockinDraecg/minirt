/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:12 by smorel            #+#    #+#             */
/*   Updated: 2021/01/27 08:12:58 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	parse_line_(char *line, t_mlx *mlx)
{
	if (*line == 's')
	{
		if (*(++line) == 'p')
			parse_sphere(++line, mlx);
		else if (*line == 'q')
			parse_square(++line, mlx);
	}
	else if (*line == 'p')
	{
		if (*(++line) == 'l')
			parse_plane(++line, mlx);
	}
	else if (*line == 't')
	{
		if (*(++line) == 'r')
			parse_triangle(++line, mlx);
	}
	else
	{
		error_minirt(20);
	}
}

static void	parse_line(char *line, t_mlx *mlx)
{
//
	// static int i = 0;
	// printf("|%d|%s\n", i++, line);
//
	trim_ws(&line);
	if (*line == 'R')
		parse_resolution(++line, mlx);
	else if (*line == 'A')
		parse_light(++line, mlx);
	else if (*line == 'c')
	{
		if (*(++line) == 'y')
			parse_cylindre(++line, mlx);
		else
			parse_cam(++line, mlx);
	}
	else if (*line == 'l')
		parse_spot(++line, mlx);
	else
		parse_line_(line, mlx);
}

void		ft_parse(char *rt_file, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*line;

	set_value_4_pars(mlx);
	if ((fd = open(rt_file, O_RDONLY)) < 0)
		error_minirt(20);
	ret = 1;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			error_minirt(21);
		parse_line(line, mlx);
		free(line);
	}
	check_mandatories_values(mlx);
	init_minrt(mlx);
}
