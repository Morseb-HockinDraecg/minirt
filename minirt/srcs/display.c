/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:29:54 by smorel            #+#    #+#             */
/*   Updated: 2021/01/25 13:51:59 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	display(t_mlx *mlx)
{
	// x = 0;
	// y = 0;
	// init_minrt(&mlx);
	// mlx_mouse_hook(mlx.win, key_hook, &mlx);
	// mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, close_win, &mlx);
	mlx_loop(mlx->ptr);
}
