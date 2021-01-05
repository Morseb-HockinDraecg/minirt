/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:09:42 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 13:52:37 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_str_add_front(char **init, t_conversion current_c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!init || !(tmp = (char *)ft_memalloc(ft_strlen(*init) + 2)))
	{
		ft_strdel(init);
		return (NULL);
	}
	if (*init[0] != '-')
	{
		if (current_c.flag[2] == '+')
			tmp[i++] = '+';
		else if (current_c.flag[3] == ' ')
			tmp[i++] = ' ';
	}
	while ((*init)[j])
		tmp[i++] = (*init)[j++];
	ft_strdel(init);
	return (tmp);
}

void		ft_printf_string(char *string, t_conversion current_c)
{
	if (current_c.preci_nul == 1 || current_c.preci_nul == 3)
		string[0] = '\0';
	else if (current_c.precision)
		string[current_c.precision] = '\0';
	if (current_c.flag[0] == '-')
		ft_str_flag_tiret(current_c, string);
	else if (current_c.flag[1] == '0')
		ft_str_flag_zero(current_c, string);
	else
		ft_str_no_flag(string, current_c);
}

void		ft_printf_char(unsigned long int param_int, t_conversion current_c)
{
	if (current_c.flag[0] == '-')
		ft_char_flag_tiret(current_c, param_int);
	else if (current_c.flag[1] == '0')
		ft_char_flag_zero(current_c, param_int);
	else
		ft_char_no_flag(param_int, current_c);
}

void		ft_printf_int(unsigned long int param_int, t_conversion current_c,\
		char spec)
{
	char	*tmp;
	char	*init;

	if (spec == 'x' || spec == 'X')
		init = ft_dec_to_hex(param_int, spec, current_c);
	else
		init = ft_itoa(param_int);
	tmp = ft_str_add_front(&init, current_c);
	if ((current_c.preci_nul == 1 || current_c.preci_nul == 3) && !param_int)
	{
		if (*tmp == '+')
			ft_rea_print('+', NULL, current_c);
		else if (*tmp == ' ')
			ft_rea_print(' ', NULL, current_c);
		ft_filler(' ', current_c.width, current_c);
		return ;
	}
	if (current_c.flag[0] == '-')
		ft_int_flag_tiret(current_c, &tmp);
	else if (current_c.flag[1] == '0')
		ft_int_flag_zero(current_c, &tmp);
	else
		ft_int_no_flag(current_c, &tmp);
	ft_strdel(&tmp);
}

void		ft_printf_address(unsigned long int param_int,\
	t_conversion current_c)
{
	char	*tmp;

	tmp = ft_dec_to_hex(param_int, 0, current_c);
	if (current_c.flag[0] == '-')
		ft_adrs_flag_tiret(current_c, &tmp);
	else if (current_c.flag[1] == '0')
		ft_adrs_flag_zero(current_c, &tmp);
	else
		ft_adrs_no_flag(current_c, &tmp);
	if (tmp)
		ft_strdel(&tmp);
}
