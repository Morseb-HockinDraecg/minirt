#include "mini_rt.h"

// int             mouse_hook(int keycode, t_mlx *mlx)
// {
//     // mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x00FF0000);
//     // if (keycode == 53)
//     //     close(mlx);
//     (void)mlx;
//     printf("keycode is |=> %d\n", keycode);
//     return (keycode);
// }

typedef struct Point Point;
 
struct Point
{
  int   x;
  int   y;
};

void    lit_coordonnees(int x1, int y1, int x2, int y2)
{
  printf("x1 = %d\n", x1);
  printf("x2 = %d\n", x2);
  printf("y1 = %d\n", y1);
  printf("y2 = %d\n", y2);
}

int     mouse_hook(int z, int x, int y)
{
    (void)z;
  static Point point[2];
  static int i = 0;
  int   color;
 
  point[i].x = x;
  point[i].y = y;
  color = 0xFF0000;
  if (i == 1)
    {
      i = 0;
      lit_coordonnees(point[0].x, point[0].y, point[1].x, point[1].y);
    //   drawline(point[0].x, point[0].y, point[1].x, point[1].y, color);
    }
  else
    {
      i++;
    }
  return (0);
}
 
