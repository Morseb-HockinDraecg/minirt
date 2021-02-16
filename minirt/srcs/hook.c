/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:21 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 12:01:11 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			close_win(t_mlx *mlx, int i)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_lstclear(&mlx->sc->c, del_fct);
	ft_lstclear(&mlx->sc->s, del_fct);
	ft_lstclear(&mlx->sc->shape, del_fct);
	printf("Window closed and program quit cleany ;)");
	exit(i);
}

static void	translation(t_mlx *mlx, int k)
{
	if (k == 0)
		list_obj(mlx->sc->shape);
	if (k == 1)
		list_obj(mlx->sc->s);
	if (k == 2)
		list_obj(mlx->sc->c);
	printf("Select an id number then a vector (x,y,z) and a float positif\n");
	printf("You can add an 'r' a the end of the line for a rotation. ");
	printf("No r on sphere, triangle and light. ");
	printf("If not, it will be a translation\n");
	if (k == 0)
		ft_parse_from_term_choice(mlx, mlx->sc->shape, k);
	if (k == 1)
		ft_parse_from_term_choice(mlx, mlx->sc->s, k);
	if (k == 2)
		ft_parse_from_term_choice(mlx, mlx->sc->c, k);
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
	if (mlx->sc->cam_activ->vector.x == 0 && mlx->sc->cam_activ->vector.z == 0)
		mlx->sc->cam_activ->vector.z = 0.00001;
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_win(mlx, 0);
	else if (keycode == 31)
		translation(mlx, 0);
	else if (keycode == 37)
		translation(mlx, 1);
	else if (keycode == 35)
		translation(mlx, 2);
	else if (keycode == 8)
		change_cam(mlx);
	if (keycode != 53)
		display_scene(mlx);
	return (keycode);
}
