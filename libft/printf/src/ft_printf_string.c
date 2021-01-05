/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:42:47 by smorel            #+#    #+#             */
/*   Updated: 2020/12/17 10:53:50 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_flag_tiret(t_conversion current_c, char *string)
{
	ft_rea_print(0, (char *)string, current_c);
	ft_filler(' ', current_c.width - ft_strlen(string), current_c);
}

void	ft_str_flag_zero(t_conversion current_c, char *string)
{
	ft_filler('0', current_c.width - ft_strlen(string), current_c);
	ft_rea_print(0, (char *)string, current_c);
}

void	ft_str_no_flag(char *string, t_conversion current_c)
{
	ft_filler(' ', current_c.width - ft_strlen(string), current_c);
	ft_rea_print(0, (char *)string, current_c);
}

void	ft_str_malloc_arg(va_list params_info, t_conversion current_c)
{
	va_list	cpy_str;
	int		len;
	char	*tmp;
	char	*param_str;

	va_copy(cpy_str, params_info);
	tmp = (char *)va_arg(cpy_str, char *);
	va_end(cpy_str);
	param_str = (char *)va_arg(params_info, char *);
	len = ft_strlen(tmp) + 1;
	if (param_str == NULL)
	{
		param_str = (char *)ft_memalloc(7);
		ft_strlcpy(param_str, "(null)", 7);
	}
	else
	{
		param_str = (char *)ft_memalloc(len);
		ft_strlcpy(param_str, tmp, len);
	}
	ft_printf_string(param_str, current_c);
	ft_strdel(&param_str);
}
