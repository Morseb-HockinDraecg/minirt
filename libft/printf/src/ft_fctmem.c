/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:57 by smorel            #+#    #+#             */
/*   Updated: 2020/12/16 14:31:41 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	char *temp;

	temp = s;
	while (n-- > 0)
		*temp++ = '\0';
}

void			*ft_memalloc(size_t size)
{
	void *mem;
	char *tmp;

	if (!(mem = (void *)malloc(size)))
		return (NULL);
	tmp = mem;
	while (size--)
		*tmp++ = 0;
	return (mem);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	unsigned char	*s;

	d = dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (s < d)
		while (len--)
			d[len] = s[len];
	else
		return (ft_memcpy(d, s, len));
	return (dst);
}

void			ft_strdel(char **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
