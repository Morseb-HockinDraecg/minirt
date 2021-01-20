/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:35 by smorel            #+#    #+#             */
/*   Updated: 2021/01/20 15:33:31 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			error_minirt(int i)
{
	int error_code;
	
	error_code = i / 10;
	if (error_code == 1)
		error_format(i);
	else if (error_code == 2)
		error_parsing(i);
	return (i);
}
