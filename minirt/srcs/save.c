/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:21:33 by smorel            #+#    #+#             */
/*   Updated: 2021/01/29 09:23:40 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

unsigned char	*create_bitmap_file_header(int file_size)
{
	static unsigned char	file_header[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	return (file_header);
}

unsigned char	*create_bitmap_info_header(t_mlx *mlx)
{
	static unsigned char info_header[] = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0,
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(mlx->w >> 0);
	info_header[5] = (unsigned char)(mlx->w >> 8);
	info_header[6] = (unsigned char)(mlx->w >> 16);
	info_header[7] = (unsigned char)(mlx->w >> 24);
	info_header[8] = (unsigned char)(mlx->h >> 0);
	info_header[9] = (unsigned char)(mlx->h >> 8);
	info_header[10] = (unsigned char)(mlx->h >> 16);
	info_header[11] = (unsigned char)(mlx->h >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(mlx->ptr_img->bits_per_pixel);
	return (info_header);
}

void			write_img(int fd, t_mlx *mlx)
{
	int		x;
	int		y;

	x = -1;
	while (++x < mlx->h)
	{
		y = -1;
		while (++y < mlx->w)
			write(fd, mlx->ptr_img->addr + ((mlx->h - x - 1) *\
			mlx->ptr_img->line_length / (mlx->ptr_img->bits_per_pixel / 8) + y)\
			, mlx->ptr_img->bits_per_pixel / 8);
	}
}

void			save_bmp(const char *filename, t_mlx *mlx)
{
	int		fd;
	int		img_size;
	int		file_size;

	img_size = mlx->w * 4 * mlx->h;
	file_size = img_size + (40 + 14);
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, create_bitmap_file_header(file_size), 14);
	write(fd, create_bitmap_info_header(mlx), 40);
	write_img(fd, mlx);
	close(fd);
	ft_putstr_fd("Image generated!!", 1);
}
