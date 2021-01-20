/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/01/20 15:04:38 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    int    *dst;

    dst = data->addr + (y * data->line_length / (data->bits_per_pixel / 8) + x);
    *(unsigned int*)dst = color;
}

int			has_intersection(t_ray *ray, t_sphere *sp, t_coord *p, t_coord *n)
{
	float a;
	float b;
	float c;
	float delta;
	float t1;
	float t2;
	v_minus(&ray->origin, &sp->origin);
	a = 1;
	b = 2.0 * v_dot(&ray->direction, &ray->origin);
	c = v_norm2(&ray->origin) - (sp->diametre / 2) * (sp->diametre / 2);
	delta = b * b - 4 * 1 *c;
	if (delta < 0)
		return (0);
	t1 = (- b - sqrt(delta)) / (2 * 1);
	t2 = (- b + sqrt(delta)) / (2 * 1);
	if (t2 < 0)
		return (0);	
	float	t;
	if (t1 > 0)
		t = t1;
	else
		t = t2;
	v_copy(p, &ray->origin);
	v_mult(&ray->direction, t);
	v_plus(p, &ray->direction);
	v_minus(p, &sp->origin);
	v_copy(n, p);
	v_normaliz(n);
	
	return (1);
}

void		print_img(t_mlx *mlx)
{
	int i = 0, j = 0;
	t_data	img;
	t_ray	ray;
	float fov;
	t_sphere sp;
	t_spot l;
	t_coord p, n;

	v_init(&l.origin, 15, 60, -40);
	// l.ratio = 100000000000;

	mlx->ptr_img = &img;
	img.img = mlx_new_image(mlx->ptr, mlx->w, mlx->h);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	v_init(&sp.origin, 0, 0, -55);
	sp.diametre = 20 * 2;
	// sp.rgb.x = 155.0;
	// sp.rgb.y = 210.0;
	// sp.rgb.z = 2.0;
	fov = 60 * M_PI / 180;
	while (i++ < mlx->w)
	{
		j = 0;
		while (j++ < mlx->h - 1)
		{
			v_init(&ray.direction, i - mlx->w /2, j - mlx->h /2, - mlx->w / 2 * tan(fov / 2));
			v_normaliz(&ray.direction);
			v_init(&ray.origin, 0, 0, 0);
			v_init(&p, 0, 0, 0);
			v_init(&n, 0, 0, 0);
			float	intensite_pixel = 0;
			// t_coord tmp;
			if (has_intersection(&ray, &sp, &p, &n))
			{
			// 	v_minus(&l.origin, &p);
			// 	v_copy(&tmp, &l.origin);
			// 	v_normaliz(&tmp);
			// 	intensite_pixel = l.ratio * v_dot(&tmp, &n) / v_norm2(&l.origin);
			// 	intensite_pixel *= -255;
			// // printf("%f\t", intensite_pixel);
			// 	if (intensite_pixel < 0)
			// 		intensite_pixel = 0;
			// 	else if (intensite_pixel > 255)
			// 		intensite_pixel = 255;
				// if (intensite_pixel == 0)
					intensite_pixel = 125;
			}
			my_mlx_pixel_put(&img, i, j, create_trgb(00, intensite_pixel, intensite_pixel, intensite_pixel));
				// my_mlx_pixel_put(&img, i, j, create_trgb(00, sp.rgb.x, sp.rgb.y, sp.rgb.z));
			// else
			// 	my_mlx_pixel_put(&img, i, j, create_trgb(00, 0, 0, 0));
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img.img, 0, 0);

	save_bmp("img_test.bmp", &img, mlx);
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
