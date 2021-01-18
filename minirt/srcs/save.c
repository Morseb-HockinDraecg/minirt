#include "mini_rt.h"

unsigned char	*create_bitmap_file_header(int file_size)
{
	static unsigned char	file_header[] = {
		0, 0,     /// signature
		0, 0, 0, 0, /// image file size in bytes
		0, 0, 0, 0, /// reserved
		0, 0, 0, 0, /// start of pixel array
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

unsigned char	*create_bitmap_info_header(t_mlx *mlx, int size)
{
	static unsigned char info_header[] = {
		0, 0, 0, 0, /// header size
		0, 0, 0, 0, /// image width
		0, 0, 0, 0, /// image height
		0, 0,     /// number of color planes
		0, 0,     /// bits per pixel
		0, 0, 0, 0, /// compression
		0, 0, 0, 0, /// image size
		0, 0, 0, 0, /// horizontal resolution
		0, 0, 0, 0, /// vertical resolution
		0, 0, 0, 0, /// colors in color table
		0, 0, 0, 0, /// important color count
	};
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(mlx->W >> 0);
	info_header[5] = (unsigned char)(mlx->W >> 8);
	info_header[6] = (unsigned char)(mlx->W >> 16);
	info_header[7] = (unsigned char)(mlx->W >> 24);
	info_header[8] = (unsigned char)(mlx->H >> 0);
	info_header[9] = (unsigned char)(mlx->H >> 8);
	info_header[10] = (unsigned char)(mlx->H >> 16);
	info_header[11] = (unsigned char)(mlx->H >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(mlx->ptr_img->bits_per_pixel);
	// info_header[20] = (size) >> 0;
	// info_header[21] = (size) >> 8;
	// info_header[22] = (size) >> 16;
	// info_header[23] = (size) >> 24;
	(void)size;
	return (info_header);
}

void			write_img(int fd, t_data *img, t_mlx *mlx, int y)
{
	while (y)
		write(fd, img->addr + (y-- * img->line_length / (img->bits_per_pixel / 8)), 4 * mlx->W);
}

void			save_bmp(const char *filename, t_data *img, t_mlx *mlx)
{
	int		fd;
	int		img_size;
	int		file_size;

	img_size = mlx->W * 4 * mlx->H;
	file_size = img_size + (40 + 14);
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, create_bitmap_file_header(file_size), 14);
	write(fd, create_bitmap_info_header(mlx, img_size), 40);
	write_img(fd, img, mlx, mlx->H);
	close(fd);
	ft_putstr_fd("Image generated!!", 1);
}