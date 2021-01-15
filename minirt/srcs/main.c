/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:02 by smorel            #+#    #+#             */
/*   Updated: 2021/01/13 14:26:17 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int argc, char **argv)
{
	if (argc < 3 && argc)
	{
		ft_parse(argv[1]);
		if (argc == 3)
		{
			if (!(ft_strncmp("-save", argv[2], 6)))
				printf("Module sauvegarde a faire !");
			else
				printf("Afficher a l'ecran : sauvegarde non prise en charge");
		}
	}
	else
		return (error_minirt(1));
}
