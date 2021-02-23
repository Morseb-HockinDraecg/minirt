/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:12 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 10:30:40 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	sign_coord(char **line)
{
	if (**line == '-')
	{
		(*line)++;
		return (-1);
	}
	return (1);
}

void		trim_coord(char **line, t_coord *coord, t_mlx *mlx)
{
	int sign;

	sign = sign_coord(line);
	if (!ft_isdigit(**line))
		error_minirt(13, mlx);
	coord->x = sign * trim_float(line, mlx);
	if (*(*line)++ == ',')
		;
	else
		error_minirt(22, mlx);
	sign = sign_coord(line);
	if (!ft_isdigit(**line))
		error_minirt(13, mlx);
	coord->y = sign * trim_float(line, mlx);
	if (*(*line)++ == ',')
		;
	else
		error_minirt(22, mlx);
	sign = sign_coord(line);
	if (!ft_isdigit(**line))
		error_minirt(13, mlx);
	coord->z = sign * trim_float(line, mlx);
}

float		trim_float(char **line, t_mlx *mlx)
{
	float	f;
	float	tmp;
	int		k;

	tmp = 0;
	f = trim_int(line);
	if (**line == '.')
	{
		(*line)++;
		k = trim_int(line);
		if ((tmp = k / pow(10, ft_intlen(k))) < 0)
			error_minirt(21, mlx);
	}
	f += tmp;
	return (f);
}

int			trim_int(char **line)
{
	int r;

	r = 0;
	if (!ft_isdigit(**line))
		return (-81);
	while (ft_isdigit(**line))
	{
		r = 10 * r + **line - '0';
		(*line)++;
	}
	return (r);
}

void		trim_ws(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
}
