/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:01:57 by smorel            #+#    #+#             */
/*   Updated: 2020/12/05 09:50:09 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**stat_algo(char **split, char const *s, char c, int i)
{
	int			word_len;
	char const	*word;

	while (ft_countwords(s, c))
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			word_len = 0;
			word = s;
		}
		while (*s != c && *s != '\0')
		{
			word_len++;
			s++;
		}
		if (word_len)
			if (!(split[i] = ft_substr(word, 0, word_len)))
				return (ft_strdel_2d(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}

char			**ft_split(char const *s, char c)
{
	char **split;

	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	stat_algo(split, s, c, 0);
	return (split);
}
