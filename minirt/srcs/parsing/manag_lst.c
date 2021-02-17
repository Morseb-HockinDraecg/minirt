/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:11:05 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 10:21:13 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	elem_cy(t_mlx *mlx, t_translarota *p, t_list *l)
{
	t_shape	*sh;

	sh = l->content;
	sh->origin = v_plus(sh->origin, p->vec);
	if (sh->id == 'r')
	{
		sh->vector = v_plus(sh->vector, p->vec);
		sh->pt = v_plus(sh->pt, p->vec);
	}
	if (sh->id == 'y')
		new_cy(mlx, l, sh);
}

static void	modif_elem_list(t_mlx *mlx, t_translarota *p, int k)
{
	t_list	*l;
	t_spot	*s;
	t_cam	*c;

	if (k == 0)
		l = mlx->sc->shape;
	else if (k == 1)
		l = mlx->sc->s;
	else if (k == 2)
		l = mlx->sc->c;
	while ((p->i)--)
		l = l->next;
	if (k == 0)
		elem_cy(mlx, p, l);
	else if (k == 1)
	{
		s = l->content;
		s->origin = v_plus(s->origin, p->vec);
	}
	else if (k == 2)
	{
		c = l->content;
		c->origin = v_plus(c->origin, p->vec);
	}
}

static void	modif_elem_list_rota(t_mlx *mlx, t_translarota *p,\
float co, float s)
{
	t_list	*l;
	t_shape	*sh;
	float	c;
	float	mat[3][3];

	c = 1 - co;
	l = mlx->sc->shape;
	while ((p->i)--)
		l = l->next;
	sh = l->content;
	if (sh->id != 'y')
		return ;
	mat[0][0] = (co + p->vec.x * p->vec.x * c) * sh->vector.x;
	mat[0][1] = (p->vec.x * p->vec.y * c - p->vec.z * s) * sh->vector.y;
	mat[0][2] = (p->vec.x * p->vec.z * c + p->vec.y * s) * sh->vector.z;
	mat[1][0] = (p->vec.y * p->vec.x * c + p->vec.z * s) * sh->vector.x;
	mat[1][1] = (co + p->vec.y * p->vec.y * c) * sh->vector.y;
	mat[1][2] = (p->vec.y * p->vec.z * c - p->vec.x * s) * sh->vector.z;
	mat[2][0] = (p->vec.z * p->vec.x * c - p->vec.y * s) * sh->vector.x;
	mat[2][1] = (p->vec.z * p->vec.y * c + p->vec.x * s) * sh->vector.y;
	mat[2][2] = (co + p->vec.z * p->vec.z * c) * sh->vector.z;
	sh->vector.x = mat[0][0] + mat[0][1] + mat[0][2];
	sh->vector.y = mat[1][0] + mat[1][1] + mat[1][2];
	sh->vector.z = mat[2][0] + mat[2][1] + mat[2][2];
	new_cy(mlx, l, sh);
}

static int	parse_transrota(t_mlx *mlx, t_translarota *p)
{
	char			*line;
	char			*li;

	if (get_next_line(0, &line) < 0)
		error_minirt(22, mlx);
	if (!ft_isdigit(*line))
	{
		printf("Not a number !\n");
		free(line);
		return (0);
	}
	li = line;
	p->i = trim_int(&line);
	trim_ws(&line);
	trim_coord(&line, &p->vec, mlx);
	trim_ws(&line);
	p->mult = trim_float(&line, mlx);
	trim_ws(&line);
	p->op = 0;
	p->op = *line;
	free(li);
	return (1);
}

void		ft_parse_from_term_choice(t_mlx *mlx, t_list *l, int k)
{
	t_translarota	p;

	if (!l)
		return ;
	if (!parse_transrota(mlx, &p))
		return ;
	if (ft_lstsize(l) < p.i)
	{
		printf("Elem not in the list\n");
		return ;
	}
	else if (p.op == 'r')
	{
		p.mult *= M_PI / 180;
		modif_elem_list_rota(mlx, &p, cos(p.mult), sin(p.mult));
	}
	else
	{
		p.vec = v_mult(&p.vec, p.mult);
		modif_elem_list(mlx, &p, k);
	}
}
