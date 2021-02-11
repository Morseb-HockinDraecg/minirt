/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:31:13 by smorel            #+#    #+#             */
/*   Updated: 2021/02/11 09:55:48 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_coord	v_mult(t_coord *a, float b)
{
	t_coord	c;

	c.x = a->x * b;
	c.y = a->y * b;
	c.z = a->z * b;
	return (c);
}

// t_coord	v_mult_v(t_coord *a, t_coord *b)
// {
// 	t_coord	c;

// 	c.x = a->x * b->x;
// 	c.y = a->y * b->y;
// 	c.z = a->z * b->z;
// 	return (c);
// }

t_coord	v_sub(t_coord a, t_coord b)
{
	t_coord	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_coord	v_plus(t_coord a, t_coord b)
{
	t_coord	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

void	v_init(t_coord *a, float x, float y, float z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}
