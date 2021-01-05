/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:10:16 by smorel            #+#    #+#             */
/*   Updated: 2020/12/17 09:09:03 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_rea_print(char c, char *str, t_conversion current_c)
{
	if (!str)
	{
		ft_putchar_fd(c, 1);
		(*current_c.len_p)++;
	}
	else
	{
		ft_putstr_fd(str, 1);
		*current_c.len_p = *current_c.len_p + ft_strlen(str);
	}
}

static int	ft_read_format(const char *format, va_list params_info)
{
	char			*tmp;
	t_conversion	current_c;
	int				len_printed;

	len_printed = 0;
	current_c.len_p = &len_printed;
	tmp = (char *)format;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			ft_conversion(&tmp, params_info, current_c);
		}
		else
			ft_rea_print(*tmp++, NULL, current_c);
	}
	return (len_printed);
}

int			ft_printf(const char *format, ...)
{
	va_list params_info;
	int		return_value;

	if (!format)
		return (0);
	va_start(params_info, format);
	return_value = ft_read_format(format, params_info);
	va_end(params_info);
	return (return_value);
}
