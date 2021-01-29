/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:07 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 10:03:39 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	init_coord(t_coord *c)
{
	c->x = -1;
	c->y = -1;
	c->z = -1;
}

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
	t_scene	*scene;
	t_list	*lst;


	mlx->h = -1;
	mlx->w = -1;
	scene = (t_scene *)malloc(sizeof(t_scene));
	mlx->sc = scene;
	mlx->sc->l.r = -1;
	init_coord(&mlx->sc->l.rgb);
	mlx->save = 0;
	lst = NULL;
	mlx->sc->shape = lst;
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

t_shape	*init_shape(void)
{
	t_shape	*sh;

	sh = (t_shape *)malloc(sizeof(t_shape));
	init_coord(&sh->origin);
	init_coord(&sh->rgb);
	init_coord(&sh->vector);
	init_coord(&sh->point);
	sh->rayon = 0;
	sh->hight = 0;
	return (sh);
}