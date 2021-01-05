/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:57 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 13:45:39 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s && *s++)
		i++;
	return (i);
}

unsigned long long int	ft_intlen(long long int i)
{
	static unsigned long long len;

	len = 0;
	if (i < 0)
	{
		len += 1;
		ft_intlen(-i);
	}
	if (i >= 10)
		ft_intlen(i / 10);
	len += 1;
	return (len);
}
