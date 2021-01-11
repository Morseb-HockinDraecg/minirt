#include "mini_rt.h"

void     display()
{
    t_mlx mlx;
    t_data img;
    int x, y;

    init_minrt(&mlx);
    // img.img = mlx_new_image (mlx.ptr, 1980, 1080);
    img.img = mlx_xpm_file_to_image ( mlx.ptr, "/Users/smorel/Desktop/img1.xpm", &x, &y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0 );
    mlx_mouse_hook(mlx.win, key_hook, &mlx);
    mlx_hook(mlx.win, 2, 1L<<4, key_hook, &mlx);
    mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
    mlx_loop(mlx.ptr);
}