/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:07 by smorel            #+#    #+#             */
/*   Updated: 2021/01/13 09:55:52 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	init_minrt(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (error_minirt(0));
	if (!(mlx->win = mlx_new_window(mlx->ptr, mlx->W, mlx->H, "miniRT")))
		return (error_minirt(1));
	return (-1);
}
