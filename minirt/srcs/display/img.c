/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:09:50 by smorel            #+#    #+#             */
/*   Updated: 2021/02/15 08:18:53 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static float	shape_choice(t_ray *ray, t_shape *sh, t_coord *p, t_coord *n)
{
	float	intersection;

	if (sh->id == 'p')
		intersection = sphere_intersection(ray, sh, p, n);
	else if (sh->id == 'r')
		intersection = triangle_intersection(ray, sh, p, n);
	else if (sh->id == 'l')
		intersection = plane_intersection(ray, sh, p, n);
	else if (sh->id == 'q')
		intersection = square_intersection(ray, sh, p, n);
	else if (sh->id == 'y')
		intersection = cylinder_intersection(ray, sh, p, n);
	else if (sh->id == 'k')
		intersection = disk_intersection(ray, sh, p, n);
	else
		intersection = INT_MAX;
	return (intersection);
}

float			scene_intersection(t_ray *ray, t_list *l, t_coord *p,\
t_coord *n)
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
		intersection = shape_choice(ray, sh, &p_local, &n_local);
		if (intersection < t_min && intersection)
		{
			t_min = intersection;
			*p = p_local;
			*n = n_local;
			ray->rgb = sh->rgb;
		}
		l = l->next;
	}
	if (t_min == INT_MAX)
		return (0);
	return (t_min);
}

float			shadow(t_mlx *mlx, t_coord *p, t_coord *n)
{
	t_ray	shadow;
	t_coord p_shade;
	t_coord n_shade;
	float	shade;
	float	d_light2;

	shadow.origin = v_plus(*p, v_mult(n, 0.01));
	shadow.direction = v_normaliz(mlx->tmp);
	shade = scene_intersection(&shadow, mlx->sc->shape, &p_shade, &n_shade);
	d_light2 = v_n2(&mlx->tmp);
	if (shade && ((shade * shade) < d_light2))
		return (0);
	return (1);
}

void			print_img(t_mlx *mlx)
{
	int		i[2];
	t_ray	ray;
	t_ray_c	c;

	i[0] = -1;
	while (++i[0] < mlx->h)
	{
		i[1] = -1;
		while (++i[1] < mlx->w)
		{
			v_init(&ray.direction, i[1] - mlx->w / 2 + 0.5, i[0] - mlx->h / 2\
			+ 0.5, mlx->w / (2 * tan(mlx->sc->cam_activ->fov / 2)));
			ray.direction = v_normaliz(ray.direction);
			ray.origin = mlx->sc->cam_activ->origin;
			v_init(&c.up, 0, 1, 0);
			c.view = v_normaliz(mlx->sc->cam_activ->vector);
			c.right = v_normaliz(v_cross(c.view, c.up));
			c.up = v_normaliz(v_cross(c.right, c.view));
			ray.direction = v_normaliz(v_plus(v_plus(v_mult(&c.right,\
			ray.direction.x), v_mult(&c.up, ray.direction.y)),\
			v_mult(&c.view, ray.direction.z)));
			get_color(mlx, i[0], i[1], &ray);
		}
	}
	display_or_save_img(mlx);
}
