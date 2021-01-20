/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:07 by smorel            #+#    #+#             */
/*   Updated: 2021/01/20 13:53:46 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	init_minrt(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (error_minirt(98));
	if (!(mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "miniRT")))
		return (error_minirt(99));
	return (-1);
}

void	set_value_4_pars(t_mlx *mlx)
{
	mlx->h = -1;
	mlx->w = -1;
	mlx->sc->l.r = -1;
	mlx->sc->l.rgb.x = -1;
	mlx->sc->l.rgb.y = -1;
	mlx->sc->l.rgb.z = -1;
}

void	check_mandatories_values(t_mlx *mlx)
{
	if (mlx->h < 0 ||
	mlx->w < 0 ||
	mlx->sc->l.r < 0 ||
	mlx->sc->l.rgb.x < 0 ||
	mlx->sc->l.rgb.y < 0 ||
	mlx->sc->l.rgb.z < 0)
	error_parsing(25);
}