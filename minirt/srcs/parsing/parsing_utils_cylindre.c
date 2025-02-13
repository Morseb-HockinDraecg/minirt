/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_cylindre.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:24:21 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 10:30:22 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	add_disk_cylinder(t_mlx *mlx, t_shape *cy)
{
	t_shape	*sq;
	t_shape	*sq2;

	sq = init_shape();
	sq->id = 'k';
	sq->origin = cy->origin;
	sq->rgb = cy->rgb;
	sq->height = 2 * cy->r;
	sq->vector = v_mult(&cy->vector, -1);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(sq));
	sq2 = init_shape();
	sq2->id = 'k';
	sq2->origin = v_plus(cy->origin, v_mult(&cy->vector, cy->height));
	sq2->rgb = cy->rgb;
	sq2->height = 2 * cy->r;
	sq2->vector = cy->vector;
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(sq2));
}

void	parse_disk(char *line, t_mlx *mlx)
{
	t_shape	*sq;

	sq = init_shape();
	sq->id = 'k';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(24, mlx);
	trim_ws(&line);
	trim_coord(&line, &sq->origin, mlx);
	trim_ws(&line);
	trim_coord(&line, &sq->vector, mlx);
	trim_ws(&line);
	if ((sq->height = trim_float(&line, mlx)) < 0)
		error_minirt(23, mlx);
	trim_ws(&line);
	trim_coord(&line, &sq->rgb, mlx);
	if (!check_rgb(&sq->rgb))
		error_minirt(13, mlx);
	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(sq));
}
