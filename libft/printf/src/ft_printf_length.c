/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:10:01 by smorel            #+#    #+#             */
/*   Updated: 2020/12/17 09:34:16 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_modif_h(va_list params_info, char spec)
{
	long long int	param_int;

	if (spec == 'x' || spec == 'X' || spec == 'u')
	{
		param_int = (unsigned int)va_arg(params_info, unsigned int);
		param_int = (unsigned short)param_int;
	}
	else
	{
		param_int = (signed int)va_arg(params_info, signed int);
		param_int = (signed short int)param_int;
	}
	return (param_int);
}

long long int	ft_modif_hh(va_list params_info, char spec)
{
	long long int	param_int;

	if (spec == 'x' || spec == 'X' || spec == 'u')
	{
		param_int = (unsigned int)va_arg(params_info, unsigned int);
		param_int = (unsigned char)param_int;
	}
	else
	{
		param_int = (signed int)va_arg(params_info, signed int);
		param_int = (signed char)param_int;
	}
	return (param_int);
}

long long int	ft_modif_l(va_list params_info, char spec)
{
	long long int	param_int;

	if (spec == 'x' || spec == 'X' || spec == 'u')
		param_int = (unsigned long int)va_arg(params_info, unsigned long int);
	else
		param_int = (long int)va_arg(params_info, long int);
	return (param_int);
}

long long int	ft_modif_ll(va_list params_info, char spec)
{
	long long int	param_int;

	if (spec == 'x' || spec == 'X' || spec == 'u')
		param_int = (unsigned long long int)va_arg(params_info,\
				unsigned long long int);
	else
		param_int = (long long int)va_arg(params_info, long long int);
	return (param_int);
}

long long int	ft_modif_none(va_list params_info, char spec)
{
	long long int	param_int;

	if (spec == 'x' || spec == 'X' || spec == 'u')
		param_int = (unsigned int)va_arg(params_info, unsigned int);
	else
		param_int = (int)va_arg(params_info, int);
	return (param_int);
}
