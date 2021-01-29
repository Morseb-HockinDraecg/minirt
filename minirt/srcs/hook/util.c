#include "mini_rt.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    int    *dst;

    dst = mlx->ptr_img->addr + ((mlx->h - x - 1) * mlx->ptr_img->line_length / (mlx->ptr_img->bits_per_pixel / 8) + y);
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