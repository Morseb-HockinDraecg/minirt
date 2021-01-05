#include "mlx.h"
#include <unistd.h>

// int    rt_error(int i)
// {
//     write(1, &i, 1);
//     return (i);
// }

// int main()
// {
//     void    *mlx_ptr;
//     void    *win_ptr;

//     if (!(mlx_ptr = mlx_init()))
//         return (rt_error(1));
//     if(!(win_ptr = mlx_new_window(mlx_ptr, 1200, 1080, "1st window")))
//         return (rt_error(2));
    
//     mlx_destroy_window(mlx_ptr, win_ptr);
// }

int     main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
} 