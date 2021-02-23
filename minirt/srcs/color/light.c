/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:43:32 by smorel            #+#    #+#             */
/*   Updated: 2021/02/12 09:35:12 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_coord	direct_light(t_mlx *mlx, t_list *spots, t_coord *p, t_coord *n)
{
	t_spot	*s;
	float	i;
	t_coord	rgb;

	i = 0;
	v_init(&rgb, 0, 0, 0);
	while (spots)
	{
		s = spots->content;
		mlx->tmp = (v_sub(s->origin, *p));
		i = shadow(mlx, p, n);
		if (i)
		{
			if ((i = v_dot(v_normaliz(v_sub(s->origin, *p)), *n)) < 0)
				i = 0;
			if ((i = (s->r / M_PI) * 1000000.0 * i / v_n2(&mlx->tmp)) > 255)
				i = 255;
			rgb = v_plus(rgb, v_mult(&s->rgb, i));
		}
		spots = spots->next;
	}
	return (rgb);
}

void	indirect_light(t_mlx *mlx)
{
	if ((mlx->tmp.x += (mlx->sc->l.rgb.x / 255) * mlx->sc->l.r) > 1)
		mlx->tmp.x = 1;
	if ((mlx->tmp.y += (mlx->sc->l.rgb.y / 255) * mlx->sc->l.r) > 1)
		mlx->tmp.y = 1;
	if ((mlx->tmp.z += (mlx->sc->l.rgb.z / 255) * mlx->sc->l.r) > 1)
		mlx->tmp.z = 1;
	mlx->tmp.x = pow(mlx->tmp.x, 1 /2.2);
	mlx->tmp.y = pow(mlx->tmp.y, 1 /2.2);
	mlx->tmp.z = pow(mlx->tmp.z, 1 /2.2);
}
