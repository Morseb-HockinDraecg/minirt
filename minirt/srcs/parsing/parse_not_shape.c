/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_not_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:03:53 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 16:01:23 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	parse_resolution(char *line, t_mlx *mlx)
{
	if (!check_r(mlx))
		error_minirt(20);
	if (!ft_isspace(*line) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22);
	mlx->w = trim_int(&line);
	trim_ws(&line);
	mlx->h = trim_int(&line);
}

void	parse_light(char *line, t_mlx *mlx)
{
	if (!check_a(mlx))
		error_minirt(20);
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22);
	if ((mlx->sc->l.r = trim_float(&line)) < 0)
		error_minirt(23);
	trim_ws(&line);
	trim_coord(&line, &mlx->sc->l.rgb);
	if (!check_rgb(&mlx->sc->l.rgb))
		error_minirt(20);
}

void	parse_cam(char *line, t_mlx *mlx)
{
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	if (!ft_isdigit(*line) && *line != '-')
		error_minirt(22);
	trim_coord(&line, &mlx->sc->c.origin);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22);
	trim_coord(&line, &mlx->sc->c.vector);
	if (!check_orientation_3d(&mlx->sc->c.vector))
		error_minirt(20);
	trim_ws(&line);
	mlx->sc->c.fov = trim_float(&line);
	if (mlx->sc->c.fov < 0 || mlx->sc->c.fov > 180)
		error_minirt(23);
	mlx->sc->c.fov *= M_PI / 180;
}

void	parse_spot(char *line, t_mlx *mlx)
{
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22);
	trim_ws(&line);
	if (!ft_isdigit(*line) && *line != '-')
		error_minirt(22);
	trim_coord(&line, &mlx->sc->s.origin);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22);
	mlx->sc->s.r = trim_float(&line);
	trim_ws(&line);
	trim_coord(&line, &mlx->sc->s.rgb);
}
