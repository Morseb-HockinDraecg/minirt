/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:09:04 by smorel            #+#    #+#             */
/*   Updated: 2020/12/17 09:27:51 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iswidth(int c)
{
	return (ft_isdigit(c) || c == '*');
}

int		ft_islenght(int c)
{
	return (c == 'h' || c == 'l');
}

int		ft_isflag(int c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

int		ft_isspecifier(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%' || c == 'n' || c == 'f');
}

void	ft_filler(int c, long long int len, t_conversion current_c)
{
	char	*tmp;

	if (len <= 0)
		return ;
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return ;
	while (len--)
		tmp[len] = c;
	ft_rea_print(0, tmp, current_c);
	ft_strdel(&tmp);
}
