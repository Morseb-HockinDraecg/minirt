/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:35:43 by smorel            #+#    #+#             */
/*   Updated: 2021/02/01 16:04:20 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	int	*dst;

	dst = mlx->ptr_img->addr + ((mlx->h - x - 1) * mlx->ptr_img->line_length\
	/ (mlx->ptr_img->bits_per_pixel / 8) + y);
	*(unsigned int*)dst = color;
}

void	ft_print_img(t_mlx *mlx)
{
	if (mlx->save)
	{
		save_bmp("img.bmp", mlx);
		close_win(mlx);
	}
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->ptr_img->img, 0, 0);
}

static void display_msg(void)
{
	printf("Salut a toi correcteur !\n");
	printf("La scene que tu as mis en param vient d'etre generee !\n");
	printf("Si tu veux voir les objets que tu as mis a l'ecran ");
	printf("press \"l\" (comme list) une fois que tu es sur la ");
	printf("fenetre de minilibx.\nL'id : rang + type\n");
 
}

void	display_scene(t_mlx *mlx)
{
	t_data	img;

	img.img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,\
	&img.line_length, &img.endian);
	mlx->ptr_img = &img;
	print_img(mlx);
	display_msg();
}
