/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:29:54 by smorel            #+#    #+#             */
/*   Updated: 2021/01/15 15:31:07 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	display(void)
{
	t_mlx	mlx;
	int		x;
	int		y;

	mlx.W = 2000;
	mlx.H = 1000;

	x = 0;
	y = 0;
	init_minrt(&mlx);
	// mlx_mouse_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, 2, 1L << 4, key_hook, &mlx);
	mlx_loop(mlx.ptr);
}
