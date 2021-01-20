/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/01/20 10:23:23 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	if (argc < 4 && argc)
	{
		ft_parse(argv[1], &mlx);
		init_minrt(&mlx);
		if (argc == 3)
		{
			if (!(ft_strncmp("--save", argv[2], 6)))
				printf("SAUVEGARDE A FAIRE !!");
			else
				printf("Afficher a l'ecran : sauvegarde non prise en charge");
		}
		else
			display(&mlx);
	}
	else
		return (error_minirt(1));
}
