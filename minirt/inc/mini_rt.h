/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:23:38 by smorel            #+#    #+#             */
/*   Updated: 2021/02/11 09:56:06 by smorel           ###   ########lyon.fr   */
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

typedef struct	s_cam
{
	t_coord	origin;
	t_coord	vector;
	float	fov;
}				t_cam;

typedef struct	s_spot
{
	char	id;
	t_coord	origin;
	float	r;
	t_coord	rgb;
}				t_spot;

typedef struct	s_shape
{
	char	id;
	t_coord	origin;
	t_coord	rgb;
	float	r;
	float	hight;
	t_coord	vector;
	t_coord	pt;

}				t_shape;

typedef struct	s_scene
{
	t_spot	l;
	t_list	*c;
	t_cam	*cam_activ;
	t_list	*s;
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
	t_coord	u;
	t_coord	v;
	t_coord	w;
}				t_quadratic;

/*
**	to sort
*/
void			save_bmp(const char *filename, t_mlx *mlx);
// t_coord	v_multt(t_coord a, t_coord b);
void	display_obj(t_list *l);
void	del_fct(void *x);

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
int				close_win(t_mlx *mlx);

/*
**	Display
*/
float			shadow(t_mlx *mlx, t_coord *p, t_coord *n);
void			display(t_mlx *mlx);
void			display_scene(t_mlx *mlx);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			print_img(t_mlx *mlx);
void			display_or_save_img(t_mlx *mlx);
float			scene_intersection(t_ray *ray, t_list *l, t_coord *p, t_coord *n);
float			sphere_intersection(t_ray *ray, t_shape *sp, t_coord *p, t_coord *n);
float			triangle_intersection(t_ray *ray, t_shape *tr, t_coord *p, t_coord *n);
float			plane_intersection(t_ray *ray, t_shape *tr, t_coord *p, t_coord *n);
float			cylinder_intersection(t_ray *ray, t_shape *cy, t_coord *p, t_coord *n);
float			square_intersection(t_ray *ray, t_shape *pl, t_coord *p, t_coord *n);
void			list_obj(t_list *l);

/*
**	Init
*/
int				init_minrt(t_mlx *mlx);
void			set_value_4_pars(t_mlx *mlx);
t_shape			*init_shape(void);
t_cam			*init_cam(void);
t_spot			*init_spot(void);

/*
**	Parsing
*/
void			ft_parse(char *rt_file, t_mlx *mlx);
void			parse_line(char *line, t_mlx *mlx);
void			ft_parse_from_term(t_mlx *mlx);
void			ft_parse_from_term_choice(t_mlx *mlx, t_list *l);
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
void			get_color(t_mlx *mlx, int i, int j, t_ray *ray);
float			direct_light(t_mlx *mlx, t_list *spots, t_coord *p, t_coord *n);
void			indirect_light(t_mlx *mlx);


/*
**	Vector
*/
t_coord			v_copy(t_coord b);
t_coord			v_normaliz(t_coord a);
float			v_n2(t_coord *a);
float			v_dot(t_coord a, t_coord b);
t_coord			v_mult(t_coord *a, float b);
// t_coord			v_mult_v(t_coord *a, t_coord *b);
t_coord			v_sub(t_coord a, t_coord b);
t_coord			v_plus(t_coord a, t_coord b);
t_coord			v_cross(t_coord a, t_coord b);
void			v_init(t_coord *a, float x, float y, float z);

#endif
