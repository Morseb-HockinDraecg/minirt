/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:36:44 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 13:52:10 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_to_hex(int hex, int cap)
{
	char	hexa[6];

	hexa[0] = 'a';
	hexa[1] = 'b';
	hexa[2] = 'c';
	hexa[3] = 'd';
	hexa[4] = 'e';
	hexa[5] = 'f';
	if (cap)
		return (ft_toupper(hexa[hex - 10]));
	return (hexa[hex - 10]);
}

static void		ft_dec_to_hex_algo(unsigned long int dec,\
										char **tmp, int cap)
{
	if (dec >= 16)
		ft_dec_to_hex_algo((dec / 16), tmp, cap);
	if ((dec % 16) > 9)
		*(*tmp)++ = ft_to_hex(dec % 16, cap);
	else
		*(*tmp)++ = (dec % 16 + '0');
}

char			*ft_dec_to_hex(unsigned long int dec, char cap_lower_zero,\
				t_conversion current_c)
{
	char	*hex;
	char	*tmp;

	if (cap_lower_zero == 'X')
		cap_lower_zero = 1;
	else
		cap_lower_zero = 0;
	if (!(hex = (char *)ft_memalloc(20)))
		return (NULL);
	tmp = hex;
	if (current_c.flag[4] == '#' && dec)
	{
		*tmp++ = '0';
		if (!cap_lower_zero)
			*tmp++ = 'x';
		else
			*tmp++ = 'X';
	}
	ft_dec_to_hex_algo(dec, &tmp, cap_lower_zero);
	return ((char *)hex);
}
