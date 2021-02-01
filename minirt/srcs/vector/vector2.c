/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:31:26 by smorel            #+#    #+#             */
/*   Updated: 2021/02/01 07:31:57 by smorel           ###   ########lyon.fr   */
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

	norm = sqrt(v_norm2(&a));
	b.x = a.x / norm;
	b.y = a.y / norm;
	b.z = a.z / norm;
	return (b);
}

float	v_norm2(t_coord *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

float	v_dot(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void	v_div(t_coord *a, t_coord *b)
{
	// a->x /= b;
	// a->y /= b;
	// a->z /= b;
	(void)a;
	(void)b;
}
