/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:12:01 by smorel            #+#    #+#             */
/*   Updated: 2021/02/10 14:28:42 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	del_fct(void *x)
{
	free(x);
	x = NULL;
}

void	loop_minirt(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, close_win, mlx);
	mlx_loop(mlx->ptr);
}

void	check_file_name(char *argv, t_mlx *mlx)
{
	int len;

	len = ft_strlen(argv);
	len -= 3;
	if (argv[len] != '.' || argv[len + 1] != 'r' || argv[len + 2] != 't')
		error_minirt(1, mlx);
}
