/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/01/15 17:10:28 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    int    *dst;

    // dst = data->addr + ((y * data->line_length / 4 + x));
    dst = data->addr + ((y * data->line_length /4 + x));
    *(unsigned int*)dst = color;
}

void		print_img(t_mlx *mlx)
{
	int x = 0, y = 0;
	float r, g, b;
	t_data	img;
	
	mlx->ptr_img = &img;
	img.img = mlx_new_image(mlx->ptr, mlx->W, mlx->H);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x++ < mlx->W)
	{
		y = mlx->H - 1;
		while (y--)
		{
			r = (float)y/(float)(mlx->W);
			g = (float)x/(float)(mlx->H);
			// r = 0.5;
			// g = 0.8;
			b = 0.2;
			my_mlx_pixel_put(&img, x, y, create_trgb(00, (int)(255.99 * r) * 2, (int)(255.99 * g), (int)(255.99 * b)));
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img.img, 0, 0);

	// unsigned char image[mlx->H][mlx->W][3];
	// 	img.img = image;
	// 	int i, j;
	// 	for (i = 0; i < mlx->H; i++) {
	// 	for (j = 0; j < mlx->W; j++) {
	// 		image[i][j][2] = (unsigned char) ( i * 255 / mlx->H );             ///red
	// 		image[i][j][1] = (unsigned char) ( j * 255 / mlx->W );              ///green
	// 		image[i][j][0] = (unsigned char) ( (i+j) * 255 / (mlx->H+mlx->W) ); ///blue
	// 	}
	// }
	// 	mlx_put_image_to_window(mlx->ptr, mlx->win, img.img, 0, 0);

	save_bmp("img_test.bmp", &img, mlx);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_win(mlx);
	else
		print_img(mlx);
	
	printf("keycode is |=> %d\n", keycode);
	return (keycode);
}
