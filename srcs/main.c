#include "mini_rt.h"

int main()
{
    t_mlx mlx;

    if (!(mlx.ptr = mlx_init()))
        return (error_minirt(1));
    if (!(mlx.win = mlx_new_window(mlx.ptr, 1980, 1080, "miniRT")))
        return (error_minirt(2));
    mlx_hook(mlx.win, 2, 1L<<0, key_hook, &mlx);
    mlx_loop(mlx.ptr);
}
