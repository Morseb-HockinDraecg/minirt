/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:33:48 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 10:29:42 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_float(double param_int, t_conversion current_c)
{
	double	decimal;
	int		loop_dec;
	long	decimal_to_print;
	long	tmp;

	ft_printf_int(param_int, current_c, 'f');
	decimal = param_int - (int)param_int;
	if (!current_c.precision)
		current_c.precision = 4;
	loop_dec = current_c.precision + 2;
	while (loop_dec--)
		decimal = 10 * decimal;
	decimal_to_print = (long)decimal;
	tmp = decimal_to_print * 10 + 4;
	if (tmp < ((int)(decimal * 10)))
		decimal_to_print++;
	ft_rea_print('.', NULL, current_c);
	ft_printf_int(decimal_to_print, current_c, 'f');
}

void			ft_bonus_testing(char spec, va_list params_info,\
			t_conversion current_c)
{
	if (spec == 'f')
		ft_printf_float((double)va_arg(params_info, double), current_c);
}

long long int	ft_choosen_length(va_list params_info, char spec,\
		t_conversion current_c)
{
	long long int i;

	if (current_c.length[0] == 'l')
	{
		if (current_c.length[1] == 'l')
			i = ft_modif_ll(params_info, spec);
		else
			i = ft_modif_l(params_info, spec);
	}
	else if (current_c.length[0] == 'h')
	{
		if (current_c.length[1] == 'h')
			i = ft_modif_hh(params_info, spec);
		else
			i = ft_modif_h(params_info, spec);
	}
	else
		i = ft_modif_none(params_info, spec);
	return (i);
}

void			ft_printf_diez(t_conversion current_c, int spec)
{
	if (current_c.flag[4] == '#' && !spec)
		ft_rea_print(0, "0x", current_c);
	else if (current_c.flag[4] == '#' && spec)
		ft_rea_print(0, "0X", current_c);
}
