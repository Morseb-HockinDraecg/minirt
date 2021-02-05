/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:38:57 by smorel            #+#    #+#             */
/*   Updated: 2021/02/05 09:13:19 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	parse_cylindre(char *line, t_mlx *mlx)
{
	t_shape	*cy;

	cy = init_shape();
	cy->id = 'y';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	trim_coord(&line, &cy->origin);
	trim_ws(&line);
	trim_coord(&line, &cy->vector);
	trim_ws(&line);
	if ((cy->r = trim_float(&line) / 2) < 0)
		error_minirt(21);
	trim_ws(&line);
	if ((cy->hight = trim_float(&line)) < 0)
		error_minirt(21);
	trim_ws(&line);
	trim_coord(&line, &cy->rgb);
	check_rgb(&cy->rgb);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(cy));
}

void	parse_sphere(char *line, t_mlx *mlx)
{
	t_shape	*sp;

	sp = init_shape();
	sp->id = 'p';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	trim_coord(&line, &sp->origin);
	trim_ws(&line);
	if ((sp->r = trim_float(&line) / 2) < 0)
		error_minirt(23);
	trim_ws(&line);
	trim_coord(&line, &sp->rgb);
	check_rgb(&sp->rgb);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(&(*sp)));
}

void	parse_square(char *line, t_mlx *mlx)
{
	t_shape	*sq;

	sq = init_shape();
	sq->id = 'q';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	trim_coord(&line, &sq->origin);
	trim_ws(&line);
	trim_coord(&line, &sq->vector);
	trim_ws(&line);
	if ((sq->hight = trim_float(&line)) < 0)
		error_minirt(21);
	trim_ws(&line);
	trim_coord(&line, &sq->rgb);
	check_rgb(&sq->rgb);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(sq));
}

void	parse_plane(char *line, t_mlx *mlx)
{
	t_shape	*pl;

	pl = init_shape();
	pl->id = 'l';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	trim_coord(&line, &pl->origin);
	trim_ws(&line);
	trim_coord(&line, &pl->vector);
	trim_ws(&line);
	trim_coord(&line, &pl->rgb);
	check_rgb(&pl->rgb);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(pl));
}

void	parse_triangle(char *line, t_mlx *mlx)
{
	t_shape	*tr;

	tr = init_shape();
	tr->id = 'r';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	trim_coord(&line, &tr->origin);
	trim_ws(&line);
	trim_coord(&line, &tr->vector);
	trim_ws(&line);
	trim_coord(&line, &tr->pt);
	trim_ws(&line);
	trim_coord(&line, &tr->rgb);
	check_rgb(&tr->rgb);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(tr));
}
