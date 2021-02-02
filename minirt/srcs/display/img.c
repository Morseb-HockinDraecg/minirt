/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:09:50 by smorel            #+#    #+#             */
/*   Updated: 2021/02/02 11:12:09 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
			intersection = sphere_intersection(ray, sh, &p_local, &n_local);
		else if (sh->id == 'r')
			intersection = triangle_intersection(ray, sh, &p_local, &n_local);
		if (intersection < t_min && intersection)
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
	display_or_save_img(mlx);
}
