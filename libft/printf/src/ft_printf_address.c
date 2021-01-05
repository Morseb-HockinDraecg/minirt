/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:52:41 by smorel            #+#    #+#             */
/*   Updated: 2020/12/15 03:10:38 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_adrs_flag_tiret(t_conversion current_c, char **tmp)
{
	int		preci;

	preci = current_c.precision - ft_strlen(*tmp);
	ft_rea_print(0, "0x", current_c);
	if (preci > 0)
	{
		ft_filler('0', preci, current_c);
		ft_filler(' ', current_c.width - (ft_strlen(*tmp) + 2 - preci),\
		current_c);
	}
	ft_rea_print(0, *tmp, current_c);
	if (preci < 0)
		ft_filler(' ', current_c.width - (ft_strlen(*tmp) + 2),\
		current_c);
}

void		ft_adrs_flag_zero(t_conversion current_c, char **tmp)
{
	int		preci;

	preci = current_c.precision - ft_strlen(*tmp);
	ft_filler(' ', current_c.width - (ft_strlen(*tmp) + 2),\
	current_c);
	ft_rea_print(0, "0x", current_c);
	if (preci > 0)
	{
		ft_filler(' ', current_c.width - ft_strlen(*tmp) -\
		preci, current_c);
		ft_filler('0', preci, current_c);
	}
	ft_rea_print(0, *tmp, current_c);
}

void		ft_adrs_no_flag(t_conversion current_c, char **tmp)
{
	int		preci;

	preci = current_c.precision - ft_strlen(*tmp);
	ft_filler(' ', current_c.width - (ft_strlen(*tmp) + 2),\
	current_c);
	ft_rea_print(0, "0x", current_c);
	if (preci > 0)
	{
		ft_filler(' ', current_c.width - ft_strlen(*tmp) -\
		preci, current_c);
		ft_filler('0', preci, current_c);
	}
	ft_rea_print(0, *tmp, current_c);
}
