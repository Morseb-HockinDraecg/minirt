/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:29:27 by smorel            #+#    #+#             */
/*   Updated: 2021/02/02 09:57:10 by smorel           ###   ########lyon.fr   */
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

/*
** i_pixel = intensite pixel
*/

void	get_color(t_mlx *mlx, int i, int j, t_ray *ray)
{
	t_coord	p;
	t_coord	n;
	float	i_pixel;

	v_init(&ray->rgb, 0, 0, 0);
	i_pixel = 0;
	if (scene_intersection(ray, mlx->sc->shape, &p, &n))
	{
		mlx->tmp = (v_minus(v_copy(mlx->sc->s.origin), p));
		shadow(mlx, ray, &p, &n);
		if ((i_pixel = v_dot(v_normaliz(v_minus(v_copy(mlx->sc->s.origin)\
		, p)), n)) < 0)
			i_pixel = 0;
		i_pixel = (mlx->sc->s.r / M_PI) * 10000000.0 * i_pixel\
		/ v_norm2(&mlx->tmp);
		if (i_pixel < 0)
			i_pixel = 0;
		else if (i_pixel > 255)
			i_pixel = 255;
		i_pixel /= 255;
		i_pixel = pow(i_pixel, 1 / 2.2); //correction gamma
	}
	my_mlx_pixel_put(mlx, i, j, create_trgb(00, ray->rgb.x * i_pixel,\
	ray->rgb.y * i_pixel, ray->rgb.z * i_pixel));
}
