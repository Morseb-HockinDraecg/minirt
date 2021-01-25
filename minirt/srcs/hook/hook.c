/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/01/25 16:41:10 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	//FREE ALL !!
	exit(0);
}


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    int    *dst;

    dst = data->addr + (y * data->line_length / (data->bits_per_pixel / 8) + x);
    *(unsigned int*)dst = color;
}

int			has_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
{
	t_quadratic q;

	v_minus(&ray->origin, &sp->origin);
	q.a = 1;
	q.b = 2.0 * v_dot(&ray->direction, &ray->origin);
	q.c = v_norm2(&ray->origin) - (sp->rayon) * (sp->rayon);
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
	v_copy(p, &ray->origin);
	v_mult(&ray->direction, q.t);
	v_plus(p, &ray->direction);
	v_minus(p, &sp->origin);
	v_copy(n, p);
	// v_minus(n, &sp->origin);
	v_normaliz(n);
	return (1);
}

void		print_img(t_mlx *mlx)
{
	int i = 0, j = 0;
	t_data	img;
	t_ray	ray;
	t_coord p, n;

	mlx->ptr_img = &img;
	img.img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i++ < mlx->w)
	{
		v_copy(&mlx->tmp, &mlx->sc->s.origin);
		j = 0;
		while (j++ < mlx->h - 1)
		{
			v_init(&ray.direction, i - mlx->w /2, j - mlx->h /2, - mlx->w / 2 * tan(mlx->sc->c.fov / 2));
			v_normaliz(&ray.direction);
			v_init(&ray.origin, 0, 0, 0);
			// v_init(&p, 0, 0, 0);
			// v_init(&n, 0, 0, 0);
			float	intensite_pixel = 0;
			t_coord tmp;
			if (has_intersection(&ray, mlx->sc->shape, &p, &n))
			{
				v_minus(&mlx->tmp, &p);
				v_copy(&tmp, &mlx->tmp);
				v_normaliz(&tmp);
				// v_minus(&mlx->sc->s.origin, &p);
				// v_copy(&tmp, &mlx->sc->s.origin);
				// v_normaliz(&tmp);
				float k;
				k = v_dot(&tmp, &n);
				// if ((k = v_dot(&tmp, &n)) < 0)
					k = -k;
			// printf("%f\n", k);
				intensite_pixel = mlx->sc->s.r * 10000000000.0 *  k / v_norm2(&mlx->tmp);
				// intensite_pixel = mlx->sc->s.r * 10000000000.0 *  v_dot(&tmp, &n) / v_norm2(&mlx->tmp);
				// intensite_pixel *= -1;
			// printf("%f\n", intensite_pixel);
				if (intensite_pixel < 0)
					intensite_pixel = 0;
				else if (intensite_pixel > 255)
					intensite_pixel = 255;
			}
			my_mlx_pixel_put(&img, i, j, create_trgb(00, intensite_pixel, intensite_pixel, intensite_pixel));
		}
	}
	if (mlx->save)
		save_bmp("img.bmp", &img, mlx);
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
