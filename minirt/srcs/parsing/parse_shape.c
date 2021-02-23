/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:38:57 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 10:29:52 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	parse_cylindre(char *line, t_mlx *mlx)
{
	t_shape	*cy;

	cy = init_shape();
	cy->id = 'y';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(24, mlx);
	trim_ws(&line);
	trim_coord(&line, &cy->origin, mlx);
	trim_ws(&line);
	trim_coord(&line, &cy->vector, mlx);
	if (!check_orientation_3d(&cy->vector))
		error_minirt(23, mlx);
	trim_ws(&line);
	if ((cy->r = trim_float(&line, mlx) / 2) < 0)
		error_minirt(23, mlx);
	trim_ws(&line);
	if ((cy->height = trim_float(&line, mlx)) < 0)
		error_minirt(23, mlx);
	trim_ws(&line);
	trim_coord(&line, &cy->rgb, mlx);
	if (!check_rgb(&cy->rgb))
		error_minirt(13, mlx);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(cy));
	add_disk_cylinder(mlx, cy);
}

void	parse_sphere(char *line, t_mlx *mlx)
{
	t_shape	*sp;

	sp = init_shape();
	sp->id = 'p';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(24, mlx);
	trim_ws(&line);
	trim_coord(&line, &sp->origin, mlx);
	trim_ws(&line);
	if ((sp->r = trim_float(&line, mlx) / 2) < 0)
		error_minirt(23, mlx);
	trim_ws(&line);
	trim_coord(&line, &sp->rgb, mlx);
	if (!check_rgb(&sp->rgb))
		error_minirt(13, mlx);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(&(*sp)));
}

void	parse_square(char *line, t_mlx *mlx)
{
	t_shape	*sq;

	sq = init_shape();
	sq->id = 'q';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(24, mlx);
	trim_ws(&line);
	trim_coord(&line, &sq->origin, mlx);
	trim_ws(&line);
	trim_coord(&line, &sq->vector, mlx);
	if (!check_orientation_3d(&sq->vector))
		error_minirt(23, mlx);
	trim_ws(&line);
	if ((sq->height = trim_float(&line, mlx)) < 0)
		error_minirt(23, mlx);
	trim_ws(&line);
	trim_coord(&line, &sq->rgb, mlx);
	if (!check_rgb(&sq->rgb))
		error_minirt(13, mlx);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(sq));
}

void	parse_plane(char *line, t_mlx *mlx)
{
	t_shape	*pl;

	pl = init_shape();
	pl->id = 'l';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(24, mlx);
	trim_ws(&line);
	trim_coord(&line, &pl->origin, mlx);
	trim_ws(&line);
	trim_coord(&line, &pl->vector, mlx);
	if (!check_orientation_3d(&pl->vector))
		error_minirt(23, mlx);
	trim_ws(&line);
	trim_coord(&line, &pl->rgb, mlx);
	if (!check_rgb(&pl->rgb))
		error_minirt(13, mlx);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(pl));
}

void	parse_triangle(char *line, t_mlx *mlx)
{
	t_shape	*tr;

	tr = init_shape();
	tr->id = 'r';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(24, mlx);
	trim_ws(&line);
	trim_coord(&line, &tr->origin, mlx);
	trim_ws(&line);
	trim_coord(&line, &tr->vector, mlx);
	trim_ws(&line);
	trim_coord(&line, &tr->pt, mlx);
	trim_ws(&line);
	trim_coord(&line, &tr->rgb, mlx);
	if (!check_rgb(&tr->rgb))
		error_minirt(13, mlx);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(tr));
}
