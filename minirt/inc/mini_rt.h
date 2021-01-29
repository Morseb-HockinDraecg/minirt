/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:23:38 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 16:01:44 by smorel           ###   ########lyon.fr   */
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
# include <math.h>
# include <limits.h>

/*
**	Shapes
*/

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef struct	s_ray
{
	t_coord	origin;
	t_coord	direction;
	t_coord	rgb;
}				t_ray;

typedef struct	s_light
{
	float	r;
	// t_coord	ratio;
	t_coord	rgb;
}				t_light;

typedef struct	s_cam
{
	t_coord	origin;
	t_coord	vector;
	float	fov;
}				t_cam;

typedef struct	s_spot
{
	t_coord	origin;
	float	r;
	// t_coord	ratio;
	t_coord	rgb;
}				t_spot;

typedef struct	s_shape
{
	char	id;
	t_coord	origin;
	t_coord	rgb;
	float	rayon;
	float	hight;
	t_coord	vector;
	t_coord	pt;

}				t_shape;

typedef struct	s_scene
{
	t_light	l;
	t_cam	c;
	t_spot	s;
	t_list	*shape;
}				t_scene;

/*
**	MLX + img
*/

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
	int		w;
	int		h;
	int		save;
	t_data	*ptr_img;
	t_scene	*sc;
	t_coord	tmp;
}				t_mlx;

typedef struct	s_quadratic
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t1;
	float	t2;
	float	t;
}				t_quadratic;

void			save_bmp(const char *filename, t_mlx *mlx);
/*
**	Error
*/
int				error_minirt(int i);
void			error_format(int i);
void			error_parsing(int i);

/*
**	Hook
*/
int				key_hook(int keycode, t_mlx *mlx);
int				mouse_hook(int z, int x, int y);
// int             mouse_hook(int keycode, t_mlx *mlx);

int				init_minrt(t_mlx *mlx);
void			set_value_4_pars(t_mlx *mlx);
t_shape			*init_shape(void);

void			display(t_mlx *mlx);
int				close_win(t_mlx *mlx);

/*
**	Parsing
*/
void			ft_parse(char *rt_file, t_mlx *mlx);
void			trim_ws(char **line);
int				trim_int(char **line);
float			trim_float(char **line);
void			trim_coord(char **line, t_coord *coord);
int				check_rgb(t_coord *coord);
int				check_orientation_3d(t_coord *coord);
void			check_mandatories_values(t_mlx *mlx);
int				check_r(t_mlx *mlx);
int				check_a(t_mlx *mlx);
void			parse_resolution(char *line, t_mlx *mlx);
void			parse_light(char *line, t_mlx *mlx);
void			parse_cam(char *line, t_mlx *mlx);
void			parse_spot(char *line, t_mlx *mlx);
void			parse_cylindre(char *line, t_mlx *mlx);
void			parse_sphere(char *line, t_mlx *mlx);
void			parse_square(char *line, t_mlx *mlx);
void			parse_plane(char *line, t_mlx *mlx);
void			parse_triangle(char *line, t_mlx *mlx);

/*
**	Color
*/
int				create_trgb(int t, int r, int g, int b);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

/*
**	Vector
*/
t_coord			v_copy(t_coord b);
t_coord			v_normaliz(t_coord a);
float			v_norm2(t_coord *a);
float			v_dot(t_coord a, t_coord b);
void			v_div(t_coord *a, t_coord *b);
t_coord			v_mult(t_coord *a, float b);
t_coord			v_minus(t_coord a, t_coord b);
t_coord			v_plus(t_coord a, t_coord b);
// t_coord			v_add(t_coord a, float b);
void			v_init(t_coord *a, int x, int y, int z);

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void		ft_print_img(t_mlx *mlx);
void		print_img(t_mlx *mlx);

#endif
