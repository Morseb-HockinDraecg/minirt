/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:02:34 by smorel            #+#    #+#             */
/*   Updated: 2021/02/10 17:43:18 by smorel           ###   ########lyon.fr   */
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
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
	q.delta = sq->hight / 2;
	v_init(&side, q.delta, q.delta, 0);
	q.u = v_plus(sq->origin, side);
	v_init(&side, q.delta, -q.delta, 0);
	q.v = v_plus(sq->origin, side);
	v_init(&side, -q.delta, q.delta, 0);
	q.w = v_plus(sq->origin, side);
	q.a = v_dot(v_sub(*p, q.u), v_sub(q.v, q.u)) / sq->hight;
	q.b = v_dot(v_sub(*p, q.u), v_sub(q.w, q.u)) / sq->hight;
	if ((q.a < sq->hight && q.a > 0) && (q.b < sq->hight && q.b > 0))
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
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
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
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
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
	t_coord		r_o;
	// float		k, l;

	r_o = v_sub(v_copy(ray->origin), cy->origin);
	q.u = v_sub(v_copy(ray->direction), v_mult(&cy->vector, v_dot(ray->direction, cy->vector)));
	q.v = v_sub(v_copy(r_o), v_mult(&cy->vector, v_dot(r_o, cy->vector)));
	q.a = v_n2(&q.u);
	q.b = 2.0 * v_dot(q.v, q.u);
	q.c = v_n2(&q.v) - (cy->r * cy->r);
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
	*n = v_cross(v_copy(*p), v_sub(cy->vector, cy->origin));
	// *n = v_normaliz(v_sub(v_copy(*p), cy->origin));
	return (q.t);
}

float		sphere_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n)
{
	t_quadratic q;
	t_coord		r_o;

	r_o = v_sub(v_copy(ray->origin), sp->origin);
	q.a = 1;
	q.b = 2.0 * v_dot(v_copy(ray->direction), r_o);
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
	*p = v_plus(v_copy(ray->origin), v_mult(&ray->direction, q.t));
	*n = v_normaliz(v_sub(v_copy(*p), sp->origin));
	return (q.t);
}
