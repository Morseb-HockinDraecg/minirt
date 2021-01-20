/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:12 by smorel            #+#    #+#             */
/*   Updated: 2021/01/20 16:25:56 by smorel           ###   ########lyon.fr   */
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

void		trim_coord(char **line, t_coord *coord)
{
	int sign;

	sign = sign_coord(line);
	coord->x = sign * trim_float(line);
	if (*(*line)++ == ',')
		;
	else
		error_parsing(24);
	sign = sign_coord(line);
	coord->y = sign * trim_float(line);
	if (*(*line)++ == ',')
		;
	else
		error_parsing(24);
	sign = sign_coord(line);
	coord->z = sign * trim_float(line);
}

float		trim_float(char **line)
{
	float f;
	float tmp;

	tmp = 0;
	f = trim_int(line);
	if (**line == '.')
	{
		(*line)++;
		if ((tmp = trim_int(line) / pow(10, ft_intlen(trim_int(line)))) < 0)
			error_minirt(23);
	}
	f += tmp;
	return (f);
}

int			trim_int(char **line)
{
	int r;

	r = 0;
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
