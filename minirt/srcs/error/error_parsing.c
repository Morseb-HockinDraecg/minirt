/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:29:36 by smorel            #+#    #+#             */
/*   Updated: 2021/02/13 11:58:51 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	error_parsing_4(void)
{
	perror("error 24: parsing shape |not excepted, wrong input| ");
}

static void	error_parsing_3(void)
{
	perror("error 23: parsing shape |not in range| ");
}

static void	error_parsing_2(void)
{
	perror("error 22: parsing |not excepted, wrong input| ");
}

static void	error_parsing_1(void)
{
	perror("error 21: parsing |not in range| ");
}

void		error_parsing(int i)
{
	i %= 10;
	if (i == 0)
		error_parsing_0();
	else if (i == 1)
		error_parsing_1();
	else if (i == 2)
		error_parsing_2();
	else if (i == 3)
		error_parsing_3();
	else if (i == 4)
		error_parsing_4();
}
