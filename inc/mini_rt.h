#ifndef MINI_RT_H
# define MINI_RT_H

#include <mlx.h>
#include <stdio.h>

typedef struct  s_mlx
{
    void    *ptr;
    void    *win;
}               t_mlx;

int             key_hook(int keycode, t_mlx *mlx);
int             error_minirt(int i);

#endif