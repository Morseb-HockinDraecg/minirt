/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:02:34 by smorel            #+#    #+#             */
/*   Updated: 2021/02/12 16:54:37 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float		square_intersection(t_ray *ray, t_shape *sq, t_coord *p, t_coord *n)
{
	t_quadratic	q;
	t_coord		side;

	*n = sq->vector;
	q.t = v_dot(v_sub(sq->origin, ray->origin), *n) / v_dot(ray->direction, *n);
	if (q.t < 0)
		return (0);
	*p = v_plus(ray->origin, v_mult(&ray->direction, q.t));
	q.delta = sq->height / 2;
	v_init(&side, q.delta, q.delta, 0);
	q.u = v_plus(sq->origin, side);
	v_init(&side, q.delta, -q.delta, 0);
	q.v = v_plus(sq->origin, side);
	v_init(&side, -q.delta, q.delta, 0);
	q.w = v_plus(sq->origin, side);
	q.a = v_dot(v_sub(*p, q.u), v_sub(q.v, q.u)) / sq->height;
	q.b = v_dot(v_sub(*p, q.u), v_sub(q.w, q.u)) / sq->height;
	if ((q.a < sq->height && q.a > 0) && (q.b < sq->height && q.b > 0))
		return (q.t);
	return (0);
}

float		plane_intersection(t_ray *ray, t_shape *pl, t_coord *p, t_coord *n)
{
	t_quadratic	q;

	*n = pl->vector;
	q.t = v_dot(v_sub(pl->origin, ray->origin), *n) / v_dot(ray->direction, *n);
	if (q.t < 0)
		return (0);
	*p = v_plus(ray->origin, v_mult(&ray->direction, q.t));
	return (q.t);
}

float		triangle_intersection(t_ray *ray,\
t_shape *tr, t_coord *p, t_coord *n)
{
	t_quadratic	q;
	float		detm;

	*n = v_cross(v_sub(tr->vector, tr->origin), v_sub(tr->pt, tr->origin));
	if (n->z < 0)
		*n = v_mult(n, -1);
	q.t = v_dot(v_sub(tr->origin, ray->origin), *n) / v_dot(ray->direction, *n);
	if (q.t < 0)
		return (0);
	*p = v_plus(ray->origin, v_mult(&ray->direction, q.t));
	q.u = v_sub(tr->vector, tr->origin);
	q.v = v_sub(tr->pt, tr->origin);
	q.w = v_sub(*p, tr->origin);
	detm = (v_n2(&q.u) * v_n2(&q.v)) - (v_dot(q.u, q.v) * v_dot(q.v, q.u));
	q.b = (v_dot(q.w, q.u) * v_n2(&q.v)) - (v_dot(q.w, q.v) * v_dot(q.u, q.v));
	q.b /= detm;
	q.c = (v_n2(&q.u) * v_dot(q.w, q.v)) - (v_dot(q.u, q.v) * v_dot(q.w, q.u));
	q.c /= detm;
	q.a = 1 - q.b - q.c;
	if (q.a < 0 || q.a > 1 || q.b < 0 || q.b > 1 || q.c < 0 || q.c > 1)
		return (0);
	*n = v_normaliz(*n);
	return (q.t);
}

float		cylinder_intersection(t_ray *ray, t_shape *cy,\
t_coord *p, t_coord *n)
{
	t_quadratic q;

	q.u = v_cross(ray->direction, cy->vector);
	q.v = v_sub(ray->origin, cy->origin);
	q.w = v_cross(q.v, cy->vector);
	q.a = v_n2(&q.u);
	q.b = 2.0 * v_dot(q.u, q.w);
	q.c = v_n2(&q.w) - (cy->r * cy->r * v_n2(&cy->vector));
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
	*p = v_plus(ray->origin, v_mult(&ray->direction, q.t));
	if (in_the_cylinder_or_not(cy, p, n))
		return (q.t);
	return (0);
}

float		sphere_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
{
	t_quadratic q;
	t_coord		r_o;

	r_o = v_sub(ray->origin, sp->origin);
	q.a = 1;
	q.b = 2.0 * v_dot(ray->direction, r_o);
	q.c = v_n2(&r_o) - (sp->r) * (sp->r);
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
	*p = v_plus(ray->origin, v_mult(&ray->direction, q.t));
	*n = v_normaliz(v_sub(*p, sp->origin));
	return (q.t);
}
