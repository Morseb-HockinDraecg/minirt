/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:35:43 by smorel            #+#    #+#             */
/*   Updated: 2021/02/12 15:33:41 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int	*dst;

	dst = mlx->ptr_img->addr + ((mlx->h - x - 1) * mlx->ptr_img->line_length\
	/ (mlx->ptr_img->bits_per_pixel / 8) + y);
	*(unsigned int*)dst = color;
}

void		display_or_save_img(t_mlx *mlx)
{
	if (mlx->save)
	{
		save_bmp("img.bmp", mlx);
		close_win(mlx);
	}
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->ptr_img->img, 0, 0);
}

static void	display_msg(void)
{
	printf("Salut a toi correcteur !\n");
	printf("La scene que tu as mis en param vient d'etre generee !\n");
	printf("l = lst light\n");
	printf("o = lst obj \n");
	printf("c = next cam \n");
	printf("\n");
}

void		display_scene(t_mlx *mlx)
{
	t_data		img;
	static int	i = 0;

	img.img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,\
	&img.line_length, &img.endian);
	mlx->ptr_img = &img;
	if (!(i++))
	{
		display_msg();
		mlx->sc->cam_activ = mlx->sc->c->content;
	}
	print_img(mlx);
}
