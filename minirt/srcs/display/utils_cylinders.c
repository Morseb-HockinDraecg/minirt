/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cylinders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:33:33 by smorel            #+#    #+#             */
/*   Updated: 2021/02/12 16:55:20 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	disk_intersection(t_ray *ray, t_shape *dk, t_coord *p, t_coord *n)
{
	float	d2;
	float	t;

	dk->r = dk->height / 2;
	if (!(t = square_intersection(ray, dk, p, n)))
		return (0);
	dk->pt = v_sub(dk->origin, *p);
	d2 = v_n2(&dk->pt);
	dk->r *= dk->r;
	if (d2 <= dk->r)
		return (t);
	return (0);
}

float	in_the_cylinder_or_not(t_shape *cy, t_coord *p, t_coord *n)
{
	t_shape		plane;
	t_ray		tmp;
	t_quadratic	q;

	q.t = 1;
	tmp.direction = cy->vector;
	tmp.origin = *p;
	plane.origin = cy->origin;
	plane.vector = v_mult(&cy->vector, -1);
	q.t1 = plane_intersection(&tmp, &plane, p, &q.u);
	plane.origin = v_plus(cy->origin, v_mult(&cy->vector, cy->height));
	tmp.direction = v_mult(&cy->vector, -1);
	plane.vector = cy->vector;
	q.t2 = plane_intersection(&tmp, &plane, p, &q.v);
	if (q.t1 != 0 || q.t2 != 0)
		q.t = 0;
	*n = v_normaliz(v_sub(*p, cy->origin));
	return (q.t);
}
