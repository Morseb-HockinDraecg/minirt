/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:42:12 by smorel            #+#    #+#             */
/*   Updated: 2021/01/20 09:09:23 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t'\
	|| c == '\v' || c == ' ');
}
