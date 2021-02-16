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

// void		ft_parse_from_term(t_mlx *mlx)
// {
// 	char	*line;

// 	if (get_next_line(0, &line) < 0)
// 		error_minirt(22, mlx);
// 	parse_line(line, mlx);
// 	free(line);
// 	printf("working...\n");
// }

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
	del_one_elem_list(1, l);
	del_one_elem_list(1, l);
	add_disk_cylinder(mlx, sh);
}

// void		ft_parse_from_term_choice(t_mlx *mlx, t_list *l)
// {
// 	char	*line;
// 	char	*li;
// 	int		i;

// 	if (!l)
// 		return ;
// 	if (get_next_line(0, &line) < 0)
// 		error_minirt(22, mlx);
// 	if (!ft_isdigit(*line))
// 	{
// 		printf("Not a number !\n");
// 		return ;
// 	}
// 	li = line;
// 	i = trim_int(&line);
// 	free(li);
// 	printf("%d\n", ft_lstsize(l));
// 	if (ft_lstsize(l) < i)
// 	{
// 		printf("Elem not in the list\n");
// 		return ;
// 	}
// 	else
// 		del_one_elem_list(i, l);
// }
