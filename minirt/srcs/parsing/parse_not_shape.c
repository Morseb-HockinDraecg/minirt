/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_not_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:03:53 by smorel            #+#    #+#             */
/*   Updated: 2021/02/15 08:58:09 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	parse_resolution(char *line, t_mlx *mlx)
{
	if (!check_r(mlx))
		error_minirt(20, mlx);
	if (!ft_isspace(*line) && !ft_isdigit(*line))
		error_minirt(22, mlx);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22, mlx);
	if ((mlx->w = trim_int(&line)) > 2560)
		mlx->w = 2560;
	trim_ws(&line);
	if ((mlx->h = trim_int(&line)) > 1395)
		mlx->h = 1395;
	check_mandatories_values(mlx);
}

void	parse_light(char *line, t_mlx *mlx)
{
	if (!check_a(mlx))
		error_minirt(20, mlx);
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22, mlx);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22, mlx);
	if ((mlx->sc->l.r = trim_float(&line, mlx)) < 0)
		error_minirt(21, mlx);
	if (mlx->sc->l.r > 1)
		error_minirt(21, mlx);
	trim_ws(&line);
	trim_coord(&line, &mlx->sc->l.rgb, mlx);
	if (!check_rgb(&mlx->sc->l.rgb))
		error_minirt(21, mlx);
}

void	parse_cam(char *line, t_mlx *mlx)
{
	t_cam *cam;

	cam = init_cam();
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22, mlx);
	trim_ws(&line);
	if (!ft_isdigit(*line) && *line != '-')
		error_minirt(22, mlx);
	trim_coord(&line, &cam->origin, mlx);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22, mlx);
	trim_coord(&line, &cam->vector, mlx);
	if (!check_orientation_3d(&cam->vector))
		error_minirt(21, mlx);
	trim_ws(&line);
	cam->fov = trim_float(&line, mlx);
	if (cam->fov < 0 || cam->fov > 180)
		error_minirt(21, mlx);
	cam->fov *= M_PI / 180;
	ft_lstadd_back(&mlx->sc->c, ft_lstnew(cam));
}

void	parse_spot(char *line, t_mlx *mlx)
{
	t_spot	*s;

	s = init_spot();
	s->id = 'L';
	if (!ft_isspace(*line++) && !ft_isdigit(*line))
		error_minirt(22, mlx);
	trim_ws(&line);
	if (!ft_isdigit(*line) && *line != '-')
		error_minirt(22, mlx);
	trim_coord(&line, &s->origin, mlx);
	trim_ws(&line);
	if (!ft_isdigit(*line))
		error_minirt(22, mlx);
	if ((s->r = trim_float(&line, mlx)) < 0)
		error_minirt(21, mlx);
	if (s->r > 1)
		error_minirt(21, mlx);
	trim_ws(&line);
	trim_coord(&line, &s->rgb, mlx);
	ft_lstadd_back(&mlx->sc->s, ft_lstnew(s));
}
