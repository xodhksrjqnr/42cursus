#include "cub3d.h"

static void	int_to_char_array(char *header, unsigned int target)
{
	header[0] = (unsigned char)target;
	header[1] = (unsigned char)(target >> 8);
	header[2] = (unsigned char)(target >> 16);
	header[3] = (unsigned char)(target >> 24);
}

static char	set_bit_header(char *header, t_parse *data, int fd, int padding)
{
	unsigned int	file_size;
	int				width;
	int				height;

	width = data->resol[0];
	height = data->resol[1];
	file_size = 54 + (width + padding) * height;
	header[0] = 'B';
	header[1] = 'M';
	int_to_char_array(header + 2, file_size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	int_to_char_array(header + 18, width);
	int_to_char_array(header + 22, height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)32;
	return (write(fd, header, 54));
}

static char	set_bit_data(t_cub3d *cub3d, int fd, int padding)
{
	int		i;
	int		j;
	char	*dst;
	char	*dst2;

	i = cub3d->data->resol[1];
	dst = cub3d->adr + (i - 1) * cub3d->leng;
	while (--i >= 0)
	{
		j = 0;
		dst2 = dst;
		while (j++ < cub3d->data->resol[0])
		{
			if (write(fd, dst2, 4) < 0)
				return (0);
			dst2 += cub3d->bpp;
		}
		if (write(fd, "0000", padding) < 0)
			return (0);
		dst -= cub3d->leng;
	}
	return (1);
}

char		*make_bitmap_file(t_cub3d *cub3d)
{
	int		i;
	int		fd;
	int		padding;
	char	*bit_header;
	char	*message;

	bit_header = malloc(55);
	if (!bit_header)
		return ("bit_header malloc failed");
	i = 0;
	while (i < 55)
		bit_header[i++] = 0;
	fd = open("./cub3d.bmp", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		return ("fd open failed");
	message = 0;
	padding = (4 - (cub3d->data->resol[0] % 4)) % 4;
	if (!set_bit_header(bit_header, cub3d->data, fd, padding))
		message = "fd write failed";
	if (!set_bit_data(cub3d, fd, padding))
		message = "fd write failed";
	close(fd);
	free(bit_header);
	return (message);
}
