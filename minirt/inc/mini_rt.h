/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:23:38 by smorel            #+#    #+#             */
/*   Updated: 2021/01/15 15:20:20 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "shape.h"

typedef struct	s_data 
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		W;
	int		H;
	t_data  *ptr_img;
}				t_mlx;

int				error_minirt(int i);

int				key_hook(int keycode, t_mlx *mlx);
int				mouse_hook(int z, int x, int y);
// int             mouse_hook(int keycode, t_mlx *mlx);

int				init_minrt(t_mlx *mlx);

void			display();
void			ft_parse(char *rt_file, int save);

int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

void			save_bmp(const char* filename, t_data *img, t_mlx *mlx);

#endif
