/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/01/27 11:39:56 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	//FREE ALL !!
	exit(0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	t_data	img;

	if (keycode == 53)
		close_win(mlx);
	else
	{
		img.img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
		img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		mlx->ptr_img = &img;
		print_img(mlx);
	}
	return (keycode);
}
