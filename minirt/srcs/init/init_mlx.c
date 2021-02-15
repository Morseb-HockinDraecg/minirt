/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 07:43:56 by smorel            #+#    #+#             */
/*   Updated: 2021/02/15 09:56:20 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			init_minrt(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		return (error_minirt(10, mlx));
	if (!(mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, "miniRT")))
		return (error_minirt(11, mlx));
	return (-1);
}
