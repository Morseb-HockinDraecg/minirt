#include "mini_rt.h"

int             close(int keycode, t_mlx *mlx)
{
        mlx_destroy_window(mlx->ptr, mlx->win);
    (void)mlx;
    return (keycode);
}

int             key_hook(int keycode, t_mlx *mlx)
{
    if (keycode == 53)
        close(keycode, mlx);
    printf("keycode is |=> %d\n", keycode);
    return (keycode);
}