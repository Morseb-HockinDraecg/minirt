#include "mini_rt.h"

void             close(t_mlx *mlx)
{
    mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

int             key_hook(int keycode, t_mlx *mlx)
{
    // mlx_string_put(mlx->ptr, mlx->win, 20, 20, 0x00FF0000, "Hello !!!!!");
    // int x = 0, y = 0;
    // while (x++ < 10)
    // {
    // 	y = 0;
    // 	while (y++ < 25)
    // 		mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x00FF0000);
    //         // mlx_pixel_put(mlx->ptr, mlx->img1, x, y, 0x00FF0000);
    // }
    // mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img1, 0, 0);
    (void)mlx;
    if (keycode == 53)
        close(mlx);
    printf("keycode is |=> %d\n", keycode);
    return (keycode);
}