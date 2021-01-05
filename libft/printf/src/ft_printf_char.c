/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:08:43 by smorel            #+#    #+#             */
/*   Updated: 2020/12/15 02:49:07 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_char_null(t_conversion current_c)
{
	ft_rea_print(0, NULL, current_c);
}

void		ft_char_flag_tiret(t_conversion current_c, unsigned long int param)
{
	if (!param)
		ft_char_null(current_c);
	else
		ft_rea_print(param, NULL, current_c);
	ft_filler(' ', current_c.width - 1, current_c);
}

void		ft_char_flag_zero(t_conversion current_c, unsigned long int param)
{
	ft_filler('0', current_c.width - 1, current_c);
	if (!param)
		ft_char_null(current_c);
	else
		ft_rea_print(param, NULL, current_c);
}

void		ft_char_no_flag(unsigned long int param_int, t_conversion current_c)
{
	ft_filler(' ', current_c.width - 1, current_c);
	if (!param_int)
		ft_char_null(current_c);
	else
		ft_rea_print(param_int, NULL, current_c);
}
