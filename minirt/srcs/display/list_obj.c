/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:09:16 by smorel            #+#    #+#             */
/*   Updated: 2021/02/10 16:03:19 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	fill(int i)
{
	while (i-- > 0)
		printf(" ");
}

static void	headlist(void)
{
	printf("----------------------------------------------------------------");
	printf("----------------------------\n");
	fill(5 - printf("| id"));
	fill(15 - printf("| origin"));
	fill(15 - printf("| rgb"));
	fill(15 - printf("| diametre/2"));
	fill(10 - printf("| hight"));
	fill(15 - printf("| vector"));
	fill(16 - printf("| pt"));
	printf("|\n");
	printf("----------------------------------------------------------------");
	printf("----------------------------\n");
}

void		list_obj(t_list *l)
{
	t_shape	*sh;
	int		i;

	headlist();
	i = 0;
	while (l)
	{
		sh = l->content;
		fill(3 - printf("|%d", i));
		fill(2 - printf(" %c", sh->id));
		fill(15 - printf("| %.f,%.f,%.f", sh->origin.x, sh->origin.y,\
		sh->origin.z));
		fill(15 - printf("| %.f,%.f,%.f", sh->rgb.x, sh->rgb.y, sh->rgb.z));
		fill(15 - printf("| %.2f", sh->r));
		fill(10 - printf("| %.2f", sh->hight));
		fill(15 - printf("| %.1f,%.1f,%.1f", sh->vector.x, sh->vector.y,\
		sh->vector.z));
		fill(15 - printf("| %.1f,%.1f,%.1f", sh->pt.x, sh->pt.y, sh->pt.z));
		printf("|\n");
		l = l->next;
		i++;
	}
	printf("----------------------------------------------------------------");
	printf("----------------------------\n");
}

void		display_obj(t_list *l)
{
	t_shape	*sh;

	sh = l->content;
	fill(2 - printf(" %c", sh->id));
	fill(15 - printf(" %.f,%.f,%.f", sh->origin.x, sh->origin.y, sh->origin.z));
	fill(15 - printf(" %.f,%.f,%.f", sh->rgb.x, sh->rgb.y, sh->rgb.z));
	fill(15 - printf(" %.2f", sh->r));
	fill(10 - printf(" %.2f", sh->hight));
	fill(15 - printf(" %.f,%.f,%.f", sh->vector.x, sh->vector.y, sh->vector.z));
	fill(15 - printf(" %.f,%.f,%.f", sh->pt.x, sh->pt.y, sh->pt.z));
	printf("|\n");
	printf("----------------------------------------------------------------");
	printf("---------------------------\n");
}
