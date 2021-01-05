/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:10:21 by smorel            #+#    #+#             */
/*   Updated: 2020/12/12 17:41:25 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, int size)
{
	char	*nptr;
	int		i;

	if (!(nptr = (char *)ft_memalloc(sizeof(char) * size)))
	{
		ft_strdel(&ptr);
		return (NULL);
	}
	i = 0;
	while (size-- > 1)
	{
		nptr[i] = ptr[i];
		i++;
	}
	nptr[i] = '\0';
	ft_strdel(&ptr);
	return (nptr);
}
