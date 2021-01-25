/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/01/25 16:20:16 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 4 && argc)
	{
		ft_parse(argv[1], &mlx);
		if (argc == 3 && !(ft_strncmp("--save", argv[2], 6)))
			mlx.save = 1;
		display(&mlx);
	}
	else
		return (error_minirt(1));
}
