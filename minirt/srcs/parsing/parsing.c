/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:12 by smorel            #+#    #+#             */
/*   Updated: 2021/02/15 10:02:17 by smorel           ###   ########lyon.fr   */
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
	else if (*line == '\0' || *line == '#')
		;
	else
		error_minirt(21, mlx);
}

void		parse_line(char *line, t_mlx *mlx)
{
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
	else if (*line == 'k')
		parse_disk(++line, mlx);
	else
		parse_line_(line, mlx);
}

void		ft_parse(char *rt_file, t_mlx *mlx)
{
	int		fd;
	int		ret;
	char	*line;

	set_value_4_pars(mlx);
	init_minrt(mlx);
	if ((fd = open(rt_file, O_RDONLY)) < 0)
		error_minirt(20, mlx);
	ret = 1;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			error_minirt(12, mlx);
		parse_line(line, mlx);
		free(line);
	}
	mlx_destroy_window(mlx->ptr, mlx->win);
	init_minrt(mlx);
	if (!mlx->sc->c)
		error_minirt(20, mlx);
}
