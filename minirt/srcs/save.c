#include "mini_rt.h"

unsigned char	*create_bitmap_file_header(int height, int stride)
{
	int						file_size;
	static unsigned char	file_header[] = {
		0, 0,     /// signature
		0, 0, 0, 0, /// image file size in bytes
		0, 0, 0, 0, /// reserved
		0, 0, 0, 0, /// start of pixel array
	};

	file_size = 14 + 40 + (stride * height);
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
	static unsigned char info_header[40] = {
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
	info_header[4] = (unsigned char)(mlx->W);
	info_header[5] = (unsigned char)(mlx->W >> 8);
	info_header[6] = (unsigned char)(mlx->W >> 16);
	info_header[7] = (unsigned char)(mlx->W >> 24);
	info_header[8] = (unsigned char)(mlx->H);
	info_header[9] = (unsigned char)(mlx->H >> 8);
	info_header[10] = (unsigned char)(mlx->H >> 16);
	info_header[11] = (unsigned char)(mlx->H >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(4 * 8);
	info_header[20] = (mlx->W * mlx->H * 3 + (40 + 14)) >> 0;
	info_header[21] = (mlx->W * mlx->H * 3 + (40 + 14)) >> 8;
	info_header[22] = (mlx->W * mlx->H * 3 + (40 + 14)) >> 16;
	info_header[23] = (mlx->W * mlx->H * 3 + (40 + 14)) >> 0;
	return (info_header);
}

void			write_img(int fd, t_data *data, t_mlx *mlx, int y)
{
// 	int		x;
// 	int		x_line;
// 	char	*img_line;

    while (y != 0)
        write(fd, data->addr + (y-- *  mlx->W), mlx->W * 4);

	// while (--y >= 0)
	// {
	// 	if (!(img_line = malloc(mlx->W * 3 + mlx->H % 4)))
	// 		error_minirt(31);
	// 	x = -1;
	// 	x_line = 0;
	// 	while (++x < mlx->W)
	// 	{
	// 		img_line[x_line + 0] = data->addr[x + mlx->H * mlx->W] % (int)pow(16, 2);
	// 		img_line[x_line + 1] = ((data->addr[x + mlx->H * mlx->W] % (int)pow(16, 4)) - img_line[x_line]) >> 8;
	// 		img_line[x_line + 2] = ((data->addr[x + mlx->H * mlx->W] % (int)pow(16, 6)) - img_line[x_line + 1]) >> 16;
	// 		x_line += 3;
		// }
		// write(fd, img_line, mlx->W * 3 + mlx->W % 4);
		// free(img_line);
		// img_line = NULL;
	// }
}

void			save_bmp(const char *filename, t_data *img, t_mlx *mlx)
{
	int		fd;
	int		size;
	int		stride;

	// const int BYTES_PER_PIXEL = 3; /// red, green, & blue
	// const int FILE_HEADER_SIZE = 14;
	// const int INFO_HEADER_SIZE = 40
	size = mlx->W * mlx->H * 3 + (40 + 14);
	stride = (mlx->W * 3) + ((4 - (mlx->W * 3) % 4) % 4);
	if (mlx->W % 4 != 0)
		size += mlx->W % 4 * mlx->H;
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, create_bitmap_file_header(mlx->H, stride), 14);
	write(fd, create_bitmap_info_header(mlx), 40);
	write_img(fd, img, mlx, mlx->H);
	(void)img;
	close(fd);
	ft_putstr_fd("Image generated!!", 1);
}
