/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/02/12 15:27:53 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_lstclear(&mlx->sc->c, del_fct);
	ft_lstclear(&mlx->sc->s, del_fct);
	ft_lstclear(&mlx->sc->shape, del_fct);
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

static void	change_cam(t_mlx *mlx)
{
	static int	i = 1;
	int			y;
	t_list		*cams;

	cams = mlx->sc->c;
	y = 0;
	if (i < ft_lstsize(mlx->sc->c))
	{
		y = i;
		i++;
	}
	else
		i = 1;
	while (y--)
		cams = cams->next;
	mlx->sc->cam_activ = cams->content;
}

int			key_hook(int keycode, t_mlx *mlx)
{
// printf("%d\n", keycode);
	if (keycode == 53)
		close_win(mlx);
	else if (keycode == 37)
		ft_spots(mlx);
	else if (keycode == 31)
		ft_obj(mlx);
	else if (keycode == 8)
		change_cam(mlx);
	if (keycode != 53)
		display_scene(mlx);
	return (keycode);
}
