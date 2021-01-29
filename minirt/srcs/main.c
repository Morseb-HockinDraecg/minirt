/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 16:57:32 by smorel           ###   ########lyon.fr   */
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
		if (argc == 3 && !(ft_strncmp("--save", argv[2], 6)))
			mlx->save = 1;
		mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
		mlx_hook(mlx->win, 17, 0, close_win, mlx);
		mlx_loop(mlx->ptr);
	}
	else
		return (error_minirt(1));
}
