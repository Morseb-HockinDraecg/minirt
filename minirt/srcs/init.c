#include "mini_rt.h"

int init_minrt(t_mlx *mlx)
{
    if (!(mlx->ptr = mlx_init()))
        return (error_minirt(0));
    if (!(mlx->win = mlx_new_window(mlx->ptr, 1979, 1080, "miniRT")))
        return (error_minirt(1));
    return (-1);
}