/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/02/01 16:20:49 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	//FREE ALL !!
	exit(0);
}

void	ft_tab(void)
{
	printf("tab\n");
}

int		key_hook(int keycode, t_mlx *mlx)
{
printf("%d\n", keycode);
	if (keycode == 53)
		close_win(mlx);
	else if (keycode == 37)
		list_obj(mlx);
	else if (keycode == 48)
		ft_tab();
	// else if (keycode == 0)
	// 	printf("coucou\n");
	// else
	// {
	// }
	return (keycode);
}
