/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:57 by smorel            #+#    #+#             */
/*   Updated: 2020/12/16 16:59:50 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		stat_convert(long long int n, char *str, int rang)
{
	if (n >= 10)
		stat_convert(n / 10, str, rang - 1);
	str[rang] = (n % 10) + '0';
}

char			*ft_itoa(long long int n)
{
	char	*str;
	int		rang;
	size_t	ilen;

	ilen = ft_intlen(n);
	rang = 0;
	if (!(str = (char *)ft_memalloc(ilen + 1)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		*str = '-';
		rang++;
	}
	stat_convert(n, str, ilen - 1);
	return (str);
}
