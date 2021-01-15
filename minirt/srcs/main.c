/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/01/15 08:28:06 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char **argv)
{
	int save;

	save = 0;
	if (argc < 4 && argc)
	{
		if (argc == 3)
		{
			if (!(ft_strncmp("--save", argv[2], 6)))
				save = 1;
			else
				printf("Afficher a l'ecran : sauvegarde non prise en charge");
		}
		ft_parse(argv[1], save);
	}
	else
		return (error_minirt(1));
}
