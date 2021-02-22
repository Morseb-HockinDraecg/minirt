/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:15:42 by smorel            #+#    #+#             */
/*   Updated: 2021/02/15 09:04:58 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			check_rgb(t_coord *coord)
{
	if (coord->x < 0 && coord->x > 255)
		return (0);
	if (coord->y < 0 && coord->y > 255)
		return (0);
	if (coord->z < 0 && coord->z > 255)
		return (0);
	return (1);
}

int			check_orientation_3d(t_coord *coord)
{
	if (coord->x < -1 || coord->x > 1)
		return (0);
	if (coord->y < -1 || coord->y > 1)
		return (0);
	if (coord->z < -1 || coord->z > 1)
		return (0);
	return (1);
}

void		check_mandatories_values(t_mlx *mlx)
{
	if (mlx->h <= 0 || mlx->w <= 0 || (mlx->h == 1400 && mlx->w == 1400))
		error_minirt(21, mlx);
}

int			check_r(t_mlx *mlx)
{
	return (mlx->h == 1400 && mlx->w == 1400);
}

int			check_a(t_mlx *mlx)
{
	return (mlx->sc->l.r < 0 &&
	mlx->sc->l.rgb.x < 0 &&
	mlx->sc->l.rgb.y < 0 &&
	mlx->sc->l.rgb.z < 0);
}
