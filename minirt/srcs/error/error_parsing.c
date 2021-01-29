/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:29:36 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 17:22:26 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void error_parsing_1(void)
{
	perror( "error 21" );
}

static void error_parsing_0(void)
{
	perror( "error 20" );
}

void	error_parsing(int i)
{
	i %= 10;
	if (i == 0)
		error_parsing_0();
	else if (i == 0)
		error_parsing_1();
	// printf("%d\n", i);
	exit(-i);
}