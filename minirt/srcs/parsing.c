/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:30:12 by smorel            #+#    #+#             */
/*   Updated: 2021/01/15 08:29:14 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void parse_line(char *line)
{
	printf("%s\n", line);
}

void	ft_parse(char *rt_file, int save)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(rt_file, O_RDONLY)) < 0)
		error_minirt(8);
	ret = 1;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) < 0)
			error_minirt(7);
		parse_line(line);
		free(line);
	}
	display(save);
}
