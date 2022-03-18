/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:13:45 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:13:47 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	file_header(t_data *d, int fd)
{
	int	file_size;
	int	pixel_data_offset;

	pixel_data_offset = 54;
	file_size = pixel_data_offset + d->res[0] * d->res[1] * 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data_offset, 4);
}

static void	image_header(t_data *d, int fd)
{
	int	header_size;
	int	plane;
	int	image_size;

	header_size = 40;
	plane = 1;
	image_size = d->res[0] * d->res[1];
	write(fd, &header_size, 4);
	write(fd, &d->res[0], 4);
	write(fd, &d->res[1], 4);
	write(fd, &plane, 2);
	write(fd, &d->img.bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

static void	fill_bitmap2(int fd, int r, int g, int b)
{
	write(fd, &r, 1);
	write(fd, &g, 1);
	write(fd, &b, 1);
	write(fd, "\0", 1);
}

static void	fill_bitmap(t_data *d, int fd)
{
	int	x;
	int y;
	int	r;
	int	g;
	int	b;

	y = d->res[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < d->res[0])
		{
			r = (int)d->img.addr[0][y * d->img.line_length + x
			* d->img.bits_per_pixel / 8];
			g = (int)d->img.addr[0][y * d->img.line_length + x
			* d->img.bits_per_pixel / 8 + 1];
			b = (int)d->img.addr[0][y * d->img.line_length + x
			* d->img.bits_per_pixel / 8 + 2];
			fill_bitmap2(fd, r, g, b);
			x++;
		}
		y--;
	}
}

void		create_bitmap(t_data *d)
{
	int	fd;

	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT, 0777 |
	O_TRUNC | O_APPEND)) < 0)
	{
		ft_putstr("imposible to create a bitmap file\n");
		exit(1);
	}
	file_header(d, fd);
	image_header(d, fd);
	fill_bitmap(d, fd);
	close(fd);
}
