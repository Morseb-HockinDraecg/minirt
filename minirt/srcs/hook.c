/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/02/05 09:07:11 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	//FREE ALL !!
	exit(0);
}

static void	ft_spots(t_mlx *mlx)
{
	list_obj(mlx->sc->s);
	printf("select an id number to delete it or change it\n");
	ft_parse_from_term_choice(mlx, mlx->sc->s);
	printf("enter a valid parsing :\n");
	ft_parse_from_term(mlx);
	list_obj(mlx->sc->s);
}

static void	ft_obj(t_mlx *mlx)
{
	list_obj(mlx->sc->shape);
	printf("select an id number to delete it or change it\n");
	ft_parse_from_term_choice(mlx, mlx->sc->shape);
	printf("enter a valid parsing :\n");
	ft_parse_from_term(mlx);
	list_obj(mlx->sc->shape);
}

int			key_hook(int keycode, t_mlx *mlx)
{
printf("%d\n", keycode);
	if (keycode == 53)
		close_win(mlx);
	else if (keycode == 37)
		ft_spots(mlx);
	else if (keycode == 31)
		ft_obj(mlx);
	// else if (keycode == 0)
	// 	printf("coucou\n");
	// else
	// {
	// }
	return (keycode);
}
