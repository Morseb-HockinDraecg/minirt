/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:09:50 by smorel            #+#    #+#             */
/*   Updated: 2021/02/01 16:16:26 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float		sphere_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
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

float		scene_intersection(t_ray *ray, t_list *l, t_coord *p, t_coord *n)
{
	t_shape *sh;
	t_coord	p_local;
	t_coord	n_local;
	float	t_min;
	float	intersection;

	t_min = INT_MAX;
	while (l)
	{
		sh = l->content;
		if (sh->id == 'p')
			if ((intersection = sphere_intersection(ray, sh, &p_local, &n_local)))
				if (intersection < t_min)
				{
					t_min = intersection;
					*p = p_local;
					*n = n_local;
					ray->rgb = v_copy(sh->rgb);
				}
		l = l->next;
	}
	if (t_min == INT_MAX)
		return (0);
	return (t_min);
}

void		shadow(t_mlx *mlx, t_ray *ray, t_coord *p, t_coord *n)
{
	t_ray	shadow;
	t_coord p_shade;
	t_coord n_shade;
	float	shade;
	float	d_light2;

	shadow.origin = v_plus(v_copy(*p), v_mult(n, 0.1));
	shadow.direction = v_normaliz(v_copy(mlx->tmp));
	shade = scene_intersection(&shadow, mlx->sc->shape, &p_shade, &n_shade);
	d_light2 = v_norm2(&mlx->tmp);
	if (shade && shade * shade < d_light2)
		v_init(&ray->rgb, 0, 0, 0);
}

void		print_img(t_mlx *mlx)
{
	int		i;
	int		j;
	t_ray	ray;
	t_list	*cams;
	t_cam	*cam;

	cams = mlx->sc->c;
	cam = cams->content;
	i = -1;
	while (++i < mlx->h)
	{
		j = -1;
		while (++j < mlx->w)
		{
			// float r1, r2;
			// r1 = 0.9;
			// r2 = 0.1;
			// float r = sqrt(-2 * log(r1));
			// // dprintf(1, "%f|\t", r);
			// float dx = r * cos(2 * M_PI * r2);
			// float dy = r * sin(2 * M_PI * r2);
			// // dprintf(1, "|%f||%f|\n", dx, dy);
			// dx = 0.1;
			// dy = 0.1;
			// v_init(&ray.direction, j - mlx->w / 2 + 0.5 + dx, i - mlx->h / 2 + 0.5 + dy,\
			// -mlx->w / (2 * tan(mlx->sc->c.fov / 2)));
			v_init(&ray.direction, j - mlx->w / 2 + 0.5, i - mlx->h / 2 + 0.5,\
			-mlx->w / (2 * tan(cam->fov / 2)));
			ray.direction = v_normaliz(ray.direction);
			v_init(&ray.origin, 0, 0, 0);
			get_color(mlx, i, j, &ray);
		}
	}
	ft_print_img(mlx);
}
