/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:23:36 by smorel            #+#    #+#             */
/*   Updated: 2021/02/16 15:23:40 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	del_one_elem_list(int rang, t_list *l)
{
	t_list	*tmp;
	t_list	*to_del;

	tmp = NULL;
	if (rang > 0)
	{
		while (--rang)
			l = l->next;
		to_del = l->next;
		if (to_del->next)
			tmp = to_del->next;
		ft_lstdelone(to_del, del_fct);
		l->next = tmp;
	}
	else
	{
		to_del = l;
		tmp = to_del->next;
		ft_lstdelone(to_del, del_fct);
		l = tmp;
	}
}

void	new_cy(t_mlx *mlx, t_list *l, t_shape *sh)
{
	sh->vector = v_normaliz(sh->vector);
	del_one_elem_list(1, l);
	del_one_elem_list(1, l);
	add_disk_cylinder(mlx, sh);
}
