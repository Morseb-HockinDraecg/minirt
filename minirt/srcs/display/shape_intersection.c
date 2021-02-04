/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:02:34 by smorel            #+#    #+#             */
/*   Updated: 2021/02/04 17:03:28 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float		square_intersection(t_ray *ray, t_shape *sq, t_coord *p, t_coord *n)
{
	t_quadratic	q;

	*n = sq->vector;
	q.t = v_dot(v_minus(sq->origin, ray->origin), *n) / v_dot(ray->direction, *n);
	if (q.t < 0)
		return (0);
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));

	t_coord	x, y, side;
	float demih = sq->hight / 2;
	v_init(&side, demih, demih, 0);
	q.u = v_plus(sq->origin, side);
	v_init(&side, demih, -demih, 0);
	q.v = v_plus(sq->origin, side);
	v_init(&side, -demih, demih, 0);
	q.w = v_plus(sq->origin, side);
	// float proj1, proj2, w, h;
	float proj1, proj2;
	x = v_minus(q.v, q.u);
	// w =	v_norm2(&x);
	y = v_minus(q.w, q.u);
	// h =	v_norm2(&y);
Le 3 correspond a la taille du side !!
	proj1 = v_dot(v_minus(*p, q.u), x) / 3;
	proj2 = v_dot(v_minus(*p, q.u), y) / 3;
	if ((proj1 < 3 && proj1 > 0) && (proj2 < 3 && proj2 > 0))
	// proj1 = v_dot(v_minus(*p, q.u), x) / w;
	// proj2 = v_dot(v_minus(*p, q.u), y) / h;
	// if ((proj1 < w && proj1 > 0) && (proj2 < h && proj2 > 0))
		return (q.t);
	return (0);
}

float		plane_intersection(t_ray *ray, t_shape *pl, t_coord *p, t_coord *n)
{
	t_quadratic	q;

	*n = pl->vector;
	q.t = v_dot(v_minus(pl->origin, ray->origin), *n) / v_dot(ray->direction, *n);
	if (q.t < 0)
		return (0);
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
	return (q.t);
}

float		triangle_intersection(t_ray *ray, t_shape *tr, t_coord *p, t_coord *n)
{
	t_quadratic	q;
	float		detm;

	*n = v_normaliz(v_cross(v_minus(tr->vector, tr->origin), v_minus(tr->pt, tr->origin)));
	q.t = v_dot(v_minus(tr->pt, ray->origin), *n) / v_dot(ray->direction, *n);
	if (q.t < 0)
		return (0);
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
	q.u = v_minus(tr->vector, tr->origin);
	q.v = v_minus(tr->pt, tr->origin);
	q.w = v_minus(*p, tr->origin);
	detm = (v_norm2(&q.u) * v_norm2(&q.v)) - (v_dot(q.u, q.v) * v_dot(q.u, q.v));
	q.b = (v_dot(q.w, q.u) * v_norm2(&q.v)) - (v_dot(q.w, q.v) * v_dot(q.u, q.v));
	q.b /= detm;
	q.c = (v_norm2(&q.u) * v_dot(q.w, q.v)) - (v_dot(q.u, q.v) * v_dot(q.w, q.u));
	q.c /= detm;
	q.a = 1 - q.b - q.c;
	if (q.a < 0 || q.a > 1 || q.b < 0 || q.b > 1 || q.c < 0 || q.c > 1)
		return (0);
	return (q.t);
}


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
