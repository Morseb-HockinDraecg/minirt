// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   img.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/01/27 12:09:50 by smorel            #+#    #+#             */
// /*   Updated: 2021/01/27 12:17:28 by smorel           ###   ########lyon.fr   */
// /*                                                                            */
// /* ************************************************************************** */

// #include "mini_rt.h"

// int			has_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
// {
// 	t_quadratic q;
// 	t_coord		r_o;

// 	r_o = v_minus(v_copy(ray->origin), sp->origin);
// 	q.a = 1;
// 	q.b = 2.0 * v_dot(v_copy(ray->direction), r_o);
// 	q.c = v_norm2(&r_o) - (sp->rayon) * (sp->rayon);
// 	q.delta = q.b * q.b - 4 * 1 * q.c;
// 	if (q.delta < 0)
// 		return (0);
// 	q.t1 = (-q.b - sqrt(q.delta)) / (2 * 1);
// 	q.t2 = (-q.b + sqrt(q.delta)) / (2 * 1);
// 	if (q.t2 < 0)
// 		return (0);
// 	if (q.t1 > 0)
// 		q.t = q.t1;
// 	else
// 		q.t = q.t2;
// 	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
// 	*n = v_normaliz(v_minus(v_copy(*p), sp->origin));
// 	return (1);
// }

// int			scene_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
// {
// 	if (has_intersection(ray, sp, p, n))
// 		return (1);
// 	return (0);
// }

// void		algo_img(t_mlx *mlx, int i, int j, t_ray *ray)
// {
// 	t_coord	p;
// 	t_coord	n;
// 	t_shape	*s;
// 	t_list	*l;
// 	float	intensite_pixel;

// 	l = mlx->sc->shape;
// 	s = l->content;
// 	intensite_pixel = 0;
// 	if (scene_intersection(ray, s, &p, &n))
// 	{
// 		mlx->tmp = (v_minus(v_copy(mlx->sc->s.origin), p));
// 		if ((intensite_pixel = v_dot(v_normaliz(v_minus(\
// 		v_copy(mlx->sc->s.origin), p)), n)) < 0)
// 			intensite_pixel = 0;
// 		intensite_pixel = mlx->sc->s.r * 10000000.0 * intensite_pixel /\
// 		v_norm2(&mlx->tmp);
// 		if (intensite_pixel < 0)
// 			intensite_pixel = 0;
// 		else if (intensite_pixel > 255)
// 			intensite_pixel = 255;
// 		intensite_pixel /= 255;
// 	}
// 	my_mlx_pixel_put(mlx, i, j, create_trgb(00, s->rgb.x * intensite_pixel,\
// 	s->rgb.y * intensite_pixel, s->rgb.z * intensite_pixel));
// }

// void		print_img(t_mlx *mlx)
// {
// 	int		i;
// 	int		j;
// 	t_ray	ray;

// 	i = -1;
// 	while (++i < mlx->h)
// 	{
// 		j = -1;
// 		while (++j < mlx->w)
// 		{
// 			v_init(&ray.direction, j - mlx->w / 2, i - mlx->h / 2,\
// 			-mlx->w / (2 * tan(mlx->sc->c.fov / 2)));
// 			ray.direction = v_normaliz(ray.direction);
// 			v_init(&ray.origin, 0, 0, 0);
// 			algo_img(mlx, i, j, &ray);
// 		}
// 	}
// 	ft_print_img(mlx);
// }
