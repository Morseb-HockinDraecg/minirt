/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:29:27 by smorel            #+#    #+#             */
/*   Updated: 2021/02/10 14:44:15 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	get_color(t_mlx *mlx, int i, int j, t_ray *ray)
{
	t_coord	p;
	t_coord	n;
	float	i_pixel;
	t_list	*spots;

	spots = mlx->sc->s;
	v_init(&ray->rgb, 0, 0, 0);
	i_pixel = 0;
	if (scene_intersection(ray, mlx->sc->shape, &p, &n))
	{
		if (spots)
			i_pixel = direct_light(mlx, spots, &p, &n);
		mlx->tmp.x = i_pixel;
		mlx->tmp.y = i_pixel;
		mlx->tmp.z = i_pixel;
		indirect_light(mlx);
	}
	my_mlx_pixel_put(mlx, i, j, create_trgb(00, ray->rgb.x * mlx->tmp.x,\
	ray->rgb.y * mlx->tmp.y, ray->rgb.z * mlx->tmp.z));
}
