/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:35 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 11:59:13 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		error_parsing_0(void)
{
	perror("error 20: parsing |R or A already set or no cam| ");
}

int			error_minirt(int i, t_mlx *mlx)
{
	int error_code;

	printf("Error\n");
	if (i < 0)
	{
		printf("expected : exec + rt file name [--save]\n");
		exit(i);
	}
	if (i == 1)
	{
		printf("error : extension file name must be '.rt'\n");
		exit(-1);
	}
	error_code = i / 10;
	if (error_code == 1)
		error_format(i);
	else if (error_code == 2)
		error_parsing(i);
	close_win(mlx, -i);
	return (-i);
}
