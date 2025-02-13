/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/02/15 09:57:07 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 2 || argc == 3)
	{
		check_file_name(argv[1], NULL);
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		ft_parse(argv[1], mlx);
		if (argc == 3 && !(ft_strncmp("--save", argv[2], 6)))
			mlx->save = 1;
		display_scene(mlx);
		loop_minirt(mlx);
	}
	else
		return (error_minirt(-1, NULL));
}
