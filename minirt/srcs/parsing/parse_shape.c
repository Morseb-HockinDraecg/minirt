/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:38:57 by smorel            #+#    #+#             */
/*   Updated: 2021/01/27 10:17:56 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	parse_cylindre(char *line, t_mlx *mlx)
{
// printf("Hi from cy\n");
(void)line;
(void)mlx;
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
	if ((sp->rayon = trim_float(&line) / 2) < 0)
		error_minirt(23);
	trim_ws(&line);
	trim_coord(&line, &sp->rgb);
	check_rgb(&sp->rgb);

	ft_lstadd_back(&mlx->sc->shape, ft_lstnew(&(*sp)));
	// mlx->sc->shape = sp;
}

void	parse_square(char *line, t_mlx *mlx)
{
// printf("Hi from sq\n");
(void)line;
(void)mlx;
}

void	parse_plane(char *line, t_mlx *mlx)
{
// printf("Hi from pl\n");
(void)line;
(void)mlx;
}

void	parse_triangle(char *line, t_mlx *mlx)
{
// printf("Hi from tri\n");
(void)line;
(void)mlx;
}