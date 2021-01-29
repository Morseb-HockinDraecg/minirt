/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 16:11:53 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 4 && argc)
	{
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		ft_parse(argv[1], mlx);
t_list *l;
t_shape *sp;
l = mlx->sc->shape;
while (l)
	{
		sp = l->content;
		dprintf(1, "%c\t", sp->id);
		dprintf(1, "%.2f\t", sp->origin.x);
		dprintf(1, "%.2f\t", sp->origin.y);
		dprintf(1, "%.2f\t", sp->origin.z);
		dprintf(1, "%.2f\t", sp->rgb.x);
		dprintf(1, "%.2f\t", sp->rgb.y);
		dprintf(1, "%.2f\t", sp->rgb.z);
		dprintf(1, "%.2f\t", sp->rayon);
		dprintf(1, "%.2f\t", sp->hight);
		dprintf(1, "%.2f\t", sp->vector.x);
		dprintf(1, "%.2f\t", sp->vector.y);
		dprintf(1, "%.2f\t", sp->vector.z);
		dprintf(1, "%.2f\t", sp->pt.x);
		dprintf(1, "%.2f\t", sp->pt.y);
		dprintf(1, "%.2f\n", sp->pt.z);

		l = l->next;
	}

		if (argc == 3 && !(ft_strncmp("--save", argv[2], 6)))
			mlx->save = 1;
		mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
		mlx_hook(mlx->win, 17, 0, close_win, mlx);
		mlx_loop(mlx->ptr);
	}
	else
		return (error_minirt(1));
}
