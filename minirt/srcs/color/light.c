/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:43:32 by smorel            #+#    #+#             */
/*   Updated: 2021/02/10 14:45:03 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

float	direct_light(t_mlx *mlx, t_list *spots, t_coord *p, t_coord *n)
{
	t_spot	*s;
	float	i;
	float	i_max;

	i = 0;
	i_max = i;
	while (spots)
	{
		s = spots->content;
		mlx->tmp = (v_sub(v_copy(s->origin), *p));
		i = shadow(mlx, p, n);
		if (i)
		{
			if ((i = v_dot(v_normaliz(v_sub(v_copy(s->origin), *p)), *n)) < 0)
				i = 0;
			if ((i = (s->r / M_PI) * 10000000.0 * i / v_n2(&mlx->tmp)) > 255)
				i = 255;
			i = pow(i / 255, 1 / 2.2);
		}
		if (i_max < i)
			i_max = i;
		spots = spots->next;
	}
	return (i_max);
}

void	indirect_light(t_mlx *mlx)
{
	if ((mlx->tmp.x += (mlx->sc->l.rgb.x / 255) * mlx->sc->l.r) > 1)
		mlx->tmp.x = 1;
	if ((mlx->tmp.y += (mlx->sc->l.rgb.y / 255) * mlx->sc->l.r) > 1)
		mlx->tmp.y = 1;
	if ((mlx->tmp.z += (mlx->sc->l.rgb.z / 255) * mlx->sc->l.r) > 1)
		mlx->tmp.z = 1;
}
