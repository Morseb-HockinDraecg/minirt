/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:29:27 by smorel            #+#    #+#             */
/*   Updated: 2021/02/09 17:08:12 by smorel           ###   ########lyon.fr   */
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

float	intensite_pixel(t_mlx *mlx, t_list *spots, t_coord *p, t_coord *n)
{
	t_spot	*s;
	float	i_pixel[3];


	s = spots->content;
	i_pixel[1] = 1;
	while (spots)
	{
		mlx->tmp = (v_sub(v_copy(s->origin), *p));
		i_pixel[1] *= shadow(mlx, p, n);
		if ((i_pixel[0] = v_dot(v_normaliz(v_sub(v_copy(s->origin)\
		, *p)), *n)) < 0)
			i_pixel[0] = 0;
		spots = spots->next;
	}
	i_pixel[0] = (s->r / M_PI) * 10000000.0 * i_pixel[0]\
	/ v_n2(&mlx->tmp);
	if (i_pixel[0] < 0)
		i_pixel[0] = 0;
	else if (i_pixel[0] > 255)
		i_pixel[0] = 255;
	i_pixel[0] /= 255;
	i_pixel[0] = pow(i_pixel[0], 1 / 2.2); //correction gamma
	i_pixel[0] *= i_pixel[1];
	return (i_pixel[0]);	
}

void	get_color(t_mlx *mlx, int i, int j, t_ray *ray)
{
	t_coord	p;
	t_coord	n;
	float	i_pixel[3];
	t_spot	*s;
	t_list	*spots;

spots = mlx->sc->s;
	v_init(&ray->rgb, 0, 0, 0);
	i_pixel[0] = 0;
	i_pixel[1] = 1;
	if (scene_intersection(ray, mlx->sc->shape, &p, &n))
	{
		s = spots->content;
// 		// while (spots)
// 		// {
// 			mlx->tmp = (v_sub(v_copy(s->origin), p));
// 			i_pixel[1] *= shadow(mlx, &p, &n);
// printf("%.2f\n", i_pixel[1]);
// 			if ((i_pixel[0] = v_dot(v_normaliz(v_sub(v_copy(s->origin)\
// 			, p)), n)) < 0)
// 				i_pixel[0] = 0;
// 		// 	spots = spots->next;
// 		// }
// 		i_pixel[0] = (s->r / M_PI) * 10000000.0 * i_pixel[0]\
// 		/ v_n2(&mlx->tmp);
// 		if (i_pixel[0] < 0)
// 			i_pixel[0] = 0;
// 		else if (i_pixel[0] > 255)
// 			i_pixel[0] = 255;
// 		i_pixel[0] /= 255;
// 		i_pixel[0] = pow(i_pixel[0], 1 / 2.2); //correction gamma
// 		i_pixel[0] *= i_pixel[1];
		
		i_pixel[0] = intensite_pixel(mlx, spots, &p, &n);
// printf("%.2f\n", i_pixel[0]);
	}
	// float k = mlx->sc->l.r * create_trgb(00, mlx->sc->l.rgb.x, mlx->sc->l.rgb.y, mlx->sc->l.rgb.z);
	// k /= create_trgb(00, 255, 255, 255);
	// i_pixel[0] *= k;
	my_mlx_pixel_put(mlx, i, j, create_trgb(00, ray->rgb.x * i_pixel[0],\
	ray->rgb.y * i_pixel[0], ray->rgb.z * i_pixel[0]));
}
