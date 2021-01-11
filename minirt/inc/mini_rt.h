#ifndef MINI_RT_H
# define MINI_RT_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h> // lib 4 exit
#include "libft.h"

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct  s_mlx
{
    void    *ptr;
    void    *win;
    // t_data  *img;
}               t_mlx;

//srcs/error folder
int             error_minirt(int i);
//srcs/hook folder
int             key_hook(int keycode, t_mlx *mlx);
int             mouse_hook(int z, int x, int y);
// int             mouse_hook(int keycode, t_mlx *mlx);
//srcs folder
int             init_minrt(t_mlx *mlx);


void     display();
char    *ft_parse(char **);

#endif