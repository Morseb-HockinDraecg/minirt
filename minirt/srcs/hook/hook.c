/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/01/26 16:00:37 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	//FREE ALL !!
	exit(0);
}


void            my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    int    *dst;

    dst = mlx->ptr_img->addr + ((mlx->h - x - 1) * mlx->ptr_img->line_length / (mlx->ptr_img->bits_per_pixel / 8) + y);
    *(unsigned int*)dst = color;
}

int			has_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
{
	t_quadratic q;
	t_coord		r_o;

	r_o = v_minus(v_copy(ray->origin), sp->origin);
	q.a = 1;
	q.b = 2.0 * v_dot(v_copy(ray->direction), r_o);
	q.c = v_norm2(&r_o) - (sp->rayon) * (sp->rayon);
	q.delta = q.b * q.b - 4 * 1 *q.c;
	if (q.delta < 0)
		return (0);
	q.t1 = (- q.b - sqrt(q.delta)) / (2 * 1);
	q.t2 = (- q.b + sqrt(q.delta)) / (2 * 1);
	if (q.t2 < 0)
		return (0);	
	if (q.t1 > 0)
		q.t = q.t1;
	else
		q.t = q.t2;
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
	*n = v_normaliz(v_minus(v_copy(*p), sp->origin));
	return (1);
}

void		print_img(t_mlx *mlx)
{
	int i = -1;
	int	j;
	t_data	img;
	t_ray	ray;
	t_coord p, n;

	img.img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx->ptr_img = &img;
	while (++i < mlx->h)
	{
		j = -1;
		while (++j < mlx->w)
		{
			v_init(&ray.direction, j - mlx->w / 2, i - mlx->h / 2, - mlx->w / (2 * tan(mlx->sc->c.fov / 2)));
			ray.direction = v_normaliz(ray.direction);
			v_init(&ray.origin, 0, 0, 0);
			float	intensite_pixel = 0;
			if (has_intersection(&ray, mlx->sc->shape, &p, &n))
			{
				t_coord tmp;
				tmp = (v_minus(v_copy(mlx->sc->s.origin), p));
				float k;
				k = v_dot(tmp, n);
				if ((k = v_dot(v_normaliz(v_minus(v_copy(mlx->sc->s.origin), p)), n)) < 0)
					k = 0;
				intensite_pixel = mlx->sc->s.r * 10000000.0 *  k / v_norm2(&tmp);
				if (intensite_pixel < 0)
					intensite_pixel = 0;
				else if (intensite_pixel > 255)
					intensite_pixel = 255;
				intensite_pixel /= 255;
			}
			my_mlx_pixel_put(mlx, i, j, create_trgb(00, mlx->sc->shape->rgb.x * intensite_pixel, mlx->sc->shape->rgb.y * intensite_pixel, mlx->sc->shape->rgb.z * intensite_pixel));
		}
	}
	if (mlx->save)
	{
		save_bmp("img.bmp", &img, mlx);
		close_win(mlx);
	}
	else
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.img, 0, 0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_win(mlx);
	else
		print_img(mlx);
	
	printf("keycode is |=> %d\n", keycode);
	return (keycode);
}
