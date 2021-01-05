/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:10:01 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 09:37:58 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_specifier(char spec, va_list params_info,\
			t_conversion current_c)
{
	int	*tmp;

	if (spec == 'c')
		ft_printf_char((int)va_arg(params_info, int), current_c);
	else if (spec == '%')
		ft_printf_char('%', current_c);
	else if (spec == 's')
		ft_str_malloc_arg(params_info, current_c);
	else if (spec == 'd' || spec == 'i' || spec == 'u'\
		|| spec == 'x' || spec == 'X')
		ft_printf_int(ft_choosen_length(params_info, spec, current_c),\
				current_c, spec);
	else if (spec == 'p')
		ft_printf_address((unsigned long int)va_arg(params_info,\
		unsigned long int), current_c);
	else if (spec == 'n')
	{
		if ((tmp = (int *)va_arg(params_info, int *)))
			*tmp = *current_c.len_p;
	}
	else
		ft_bonus_testing(spec, params_info, current_c);
}

static void	ft_process_flag(t_conversion *current_c, char tmp)
{
	if (tmp == '-')
		current_c->flag[0] = tmp;
	if (tmp == '0')
		current_c->flag[1] = tmp;
	if (tmp == '+')
		current_c->flag[2] = tmp;
	if (tmp == ' ')
		current_c->flag[3] = tmp;
	if (tmp == '#')
		current_c->flag[4] = tmp;
}

static void	ft_process_convert(t_conversion current_c, va_list params_info)
{
	if (current_c.width == ('*' - '0'))
		if ((current_c.width = (int)va_arg(params_info, int)) < 0)
		{
			current_c.flag[0] = '-';
			current_c.width = -current_c.width;
		}
	if (current_c.precision == ('*' - '0'))
	{
		current_c.precision = (int)va_arg(params_info, int);
		if (!current_c.precision)
			current_c.preci_nul = 3;
	}
	if (current_c.precision < 0)
	{
		current_c.precision = 0;
		current_c.preci_nul = 5;
	}
	ft_printf_specifier(current_c.specifier, params_info, current_c);
}

static void	ft_conversion_algo(char **tmp, va_list params_info,\
			t_conversion current_c)
{
	int				i;

	i = 0;
	while (ft_isflag(**tmp))
		ft_process_flag(&current_c, *(*tmp)++);
	while (ft_iswidth(**tmp))
		current_c.width = current_c.width * 10 + (*(*tmp)++ - '0');
	if (**tmp == '.')
	{
		(*tmp)++;
		while (ft_iswidth(**tmp) && i < 4)
			current_c.precision = 10 * current_c.precision + (*(*tmp)++ - '0');
		current_c.preci_nul = 2;
		if (!current_c.precision)
			current_c.preci_nul = 1;
	}
	i = 0;
	while (ft_islenght(**tmp) && i < 2)
		current_c.length[i++] = *(*tmp)++;
	if (!(ft_isspecifier(**tmp)))
		return ;
	current_c.specifier = *(*tmp)++;
	ft_process_convert(current_c, params_info);
}

void		ft_conversion(char **tmp, va_list params_info,\
			t_conversion current_c)
{
	int		i;

	i = 0;
	while (i < 5)
		current_c.flag[i++] = 0;
	current_c.width = 0;
	current_c.precision = 0;
	current_c.preci_nul = 0;
	current_c.length[0] = 0;
	current_c.length[1] = 0;
	current_c.specifier = 0;
	ft_conversion_algo(tmp, params_info, current_c);
}
