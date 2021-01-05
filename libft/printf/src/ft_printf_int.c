/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:55:03 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 13:45:09 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ox(int *preci, char **p_tmp, t_conversion *current_c)
{
	if ((*p_tmp)[1] == 'x')
		ft_rea_print(0, "0x", *current_c);
	else if ((*p_tmp)[1] == 'X')
		ft_rea_print(0, "0X", *current_c);
	(void)p_tmp;
	(void)preci;
	(*p_tmp)++;
	(*p_tmp)++;
	if (!*preci)
		current_c->precision = current_c->precision + 2;
	(*preci)++;
	(*preci)++;
}

static void	ft_int_sign(int *preci, char **p_tmp, t_conversion *current_c)
{
	if (ft_isflag(*p_tmp[0]) && (*p_tmp)[0] != '0')
	{
		if (*p_tmp[0] == '-')
			ft_rea_print('-', NULL, *current_c);
		else if (*p_tmp[0] == '+')
			ft_rea_print('+', NULL, *current_c);
		else if (*p_tmp[0] == ' ')
			ft_rea_print(' ', NULL, *current_c);
		(*p_tmp)++;
		if (!*preci)
			current_c->precision = current_c->precision - 1;
		(*preci)++;
	}
	else if ((*p_tmp)[0] == '0' && ((*p_tmp)[1] == 'x' || (*p_tmp)[1] == 'X'))
		ft_ox(preci, p_tmp, current_c);
}

void		ft_int_no_flag(t_conversion current_c, char **tmp)
{
	int		preci;
	char	*p_tmp;

	p_tmp = *tmp;
	preci = current_c.precision - ft_strlen(*tmp);
	if (preci < 0 && (*tmp[0] == '-' || *tmp[0] == '+' || *tmp[0] == ' '))
		preci = -1;
	else if (preci < 0)
		preci = 0;
	if (*tmp[0] == '-' || *tmp[0] == '+' || *tmp[0] == ' ')
		preci++;
	if (current_c.flag[4] && current_c.precision && (ft_strlen(p_tmp) > 2))
	{
		current_c.width -= 2;
		current_c.precision -= 2;
	}
	ft_filler(' ', current_c.width - preci - ft_strlen(p_tmp), current_c);
	ft_int_sign(&preci, &p_tmp, &current_c);
	if (current_c.precision - ft_strlen(p_tmp))
		ft_filler('0', current_c.precision - ft_strlen(p_tmp), current_c);
	ft_rea_print(0, p_tmp, current_c);
}

void		ft_int_flag_tiret(t_conversion current_c, char **tmp)
{
	int		preci;
	int		tmp_preci;
	char	*p_tmp;

	p_tmp = *tmp;
	if ((preci = current_c.precision - ft_strlen(*tmp)) < 0)
		preci = -1;
	if (*tmp[0] == '-' || *tmp[0] == '+')
		preci++;
	if (preci)
	{
		tmp_preci = 0;
		ft_int_sign(&tmp_preci, &p_tmp, &current_c);
		ft_filler('0', preci, current_c);
	}
	ft_rea_print(0, p_tmp, current_c);
	if (preci < 0)
		ft_filler(' ', current_c.width - ft_strlen(*tmp), current_c);
	else
		ft_filler(' ', current_c.width - ft_strlen(*tmp) - preci, current_c);
}

void		ft_int_flag_zero(t_conversion current_c, char **tmp)
{
	int		preci;
	char	*p_tmp;

	p_tmp = *tmp;
	preci = current_c.precision - ft_strlen(*tmp);
	if (preci < 0 && (*tmp[0] == '-' || *tmp[0] == '+'))
		preci = -1;
	else if (preci < 0)
		preci = 0;
	if (*tmp[0] == '-' || *tmp[0] == '+')
		preci++;
	if (current_c.width < current_c.precision)
		current_c.width = current_c.precision;
	if (current_c.preci_nul == 0 || current_c.preci_nul == 5)
	{
		ft_int_sign(&preci, &p_tmp, &current_c);
		ft_filler('0', current_c.width - preci - ft_strlen(p_tmp), current_c);
	}
	else
	{
		ft_filler(' ', current_c.width - preci - ft_strlen(p_tmp), current_c);
		ft_int_sign(&preci, &p_tmp, &current_c);
		ft_filler('0', current_c.precision - ft_strlen(p_tmp), current_c);
	}
	ft_rea_print(0, p_tmp, current_c);
}
