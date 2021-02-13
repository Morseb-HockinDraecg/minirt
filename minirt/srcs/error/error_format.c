/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:27:56 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 11:55:51 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	error_format_2(void)
{
	perror("error 12: gnl ");
}

static void	error_format_1(void)
{
	perror("error 11: mlx ... ");
}

static void	error_format_0(void)
{
	perror("error 10: mlx ... ");
}

void		error_format(int i)
{
	i %= 10;
	if (i == 0)
		error_format_0();
	else if (i == 1)
		error_format_1();
	else if (i == 2)
		error_format_2();
}
