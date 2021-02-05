/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:31:26 by smorel            #+#    #+#             */
/*   Updated: 2021/02/05 07:26:42 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_coord	v_copy(t_coord b)
{
	t_coord a;

	a.x = b.x;
	a.y = b.y;
	a.z = b.z;
	return (a);
}

t_coord	v_normaliz(t_coord a)
{
	float	norm;
	t_coord b;

	norm = sqrt(v_n2(&a));
	b.x = a.x / norm;
	b.y = a.y / norm;
	b.z = a.z / norm;
	return (b);
}

float	v_n2(t_coord *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

float	v_dot(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_coord	v_cross(t_coord a, t_coord b)
{
	t_coord c;
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}
