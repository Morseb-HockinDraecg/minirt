/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:09:50 by smorel            #+#    #+#             */
/*   Updated: 2021/01/28 15:59:01 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			has_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
{
	t_quadratic q;
	t_coord		r_o;

	r_o = v_minus(v_copy(ray->origin), sp->origin);
	q.a = 1;
	q.b = 2.0 * v_dot(v_copy(ray->direction), r_o);
	q.c = v_norm2(&r_o) - (sp->rayon) * (sp->rayon);
	q.delta = q.b * q.b - 4 * q.a * q.c;
	if (q.delta < 0)
		return (0);
	q.t1 = (-q.b - sqrt(q.delta)) / (2 * q.a);
	q.t2 = (-q.b + sqrt(q.delta)) / (2 * q.a);
	if (q.t2 < 0)
		return (0);
	if (q.t1 > 0)
		q.t = q.t1;
	else
		q.t = q.t2;
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
	*n = v_normaliz(v_minus(v_copy(*p), sp->origin));
	return (q.t);
}

int			scene_intersection(t_ray *ray, t_list *l, t_coord *p, t_coord *n)
{
	t_shape *sp;
	t_coord	p_tmp;
	t_coord	n_tmp;
	float	t_min;
	float	intersection;

	t_min = INT_MAX;
	while (l)
	{
		sp = l->content;
		if ((intersection = has_intersection(ray, sp, &p_tmp, &n_tmp)))
			if (intersection < t_min)
			{
				t_min = intersection;
				*p = p_tmp;
				*n = n_tmp;
				ray->rgb = v_copy(sp->rgb);
			}
		l = l->next;
	}
	if (t_min == INT_MAX)
		return (0);
	return (t_min);
}

void		shadow(t_mlx *mlx, t_coord *p, t_ray *ray)
{
	t_ray shadow;
	t_coord p_shade;
	t_coord n_shade;
	int		shade;

	shadow.origin = v_copy(*p);
	shadow.direction = v_normaliz(v_copy(mlx->tmp));
	shade = scene_intersection(&shadow, mlx->sc->shape, &p_shade, &n_shade);
	float d_light2 = v_norm2(&mlx->tmp); 
	if (shade && shade * shade < d_light2)
		v_init(&ray->rgb, 0, 0, 0);
}

/*
** i_pixel = intensite pixel
*/

void		algo_img(t_mlx *mlx, int i, int j, t_ray *ray)
{
	t_coord	p;
	t_coord	n;
	float	i_pixel;

	v_init(&ray->rgb, 0, 0, 0);
	i_pixel = 0;
	if (scene_intersection(ray, mlx->sc->shape, &p, &n))
	{
		mlx->tmp = (v_minus(v_copy(mlx->sc->s.origin), p));
		shadow(mlx, &p, ray);
		if ((i_pixel = v_dot(v_normaliz(v_minus(v_copy(mlx->sc->s.origin), p)), n)) < 0)
			i_pixel = 0;
		i_pixel = (mlx->sc->s.r / M_PI) * 10000000.0 * i_pixel /v_norm2(&mlx->tmp);
		if (i_pixel < 0)
			i_pixel = 0;
		else if (i_pixel > 255)
			i_pixel = 255;
		i_pixel /= 255;
	}
	my_mlx_pixel_put(mlx, i, j, create_trgb(00, ray->rgb.x * i_pixel,\
	ray->rgb.y * i_pixel, ray->rgb.z * i_pixel));
}

void		print_img(t_mlx *mlx)
{
	int		i;
	int		j;
	t_ray	ray;

	i = -1;
	while (++i < mlx->h)
	{
		j = -1;
		while (++j < mlx->w)
		{
			v_init(&ray.direction, j - mlx->w / 2, i - mlx->h / 2,\
			-mlx->w / (2 * tan(mlx->sc->c.fov / 2)));
			ray.direction = v_normaliz(ray.direction);
			v_init(&ray.origin, 0, 0, 0);
			algo_img(mlx, i, j, &ray);
		}
	}
	ft_print_img(mlx);
}
