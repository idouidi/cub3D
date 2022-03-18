/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:15:20 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:15:21 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *d, int color)
{
	char *dst;

	if (d->x >= 0 && d->y >= 0 && d->x < d->img.line_length)
	{
		dst = d->img.addr[0] + ((int)d->y * d->img.line_length + (int)d->x *
		(d->img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	create_img(t_data *d, int i, int width, int height)
{
	d->img.bits_per_pixel = 0;
	d->img.line_length = 0;
	d->img.endian = 0;
	d->img.ptr[i] = mlx_new_image(d->vars.mlx, width, height);
	d->img.addr[i] = mlx_get_data_addr(d->img.ptr[i], &d->img.bits_per_pixel,
				&d->img.line_length, &d->img.endian);
}

void	drawsquare(t_data *d, int color)
{
	d->x = d->square.imgx;
	d->y = d->square.imgy;
	while (d->y < (d->square.height + d->square.imgy - 1))
	{
		while (d->x < (d->square.width + d->square.imgx - 1))
		{
			my_mlx_pixel_put(d, color);
			d->x++;
		}
		d->y++;
		d->x = d->square.imgx;
	}
}

void	drawplayer(t_data *d)
{
	d->square.imgx = (d->player.pos_x * d->square.width) - ((((d->res[0] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.imgy = (d->player.pos_y * d->square.height) - ((((d->res[1] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.width = (((d->res[0] * .75) / ft_strlen(d->map[0])) / 2);
	d->square.height = d->square.width;
	drawsquare(d, 0x0);
}

void	init_player(t_data *d)
{
	d->player.sp = .15;
	if (d->player.letter == 'N' || d->player.letter == 'S')
	{
		d->player.dir_x = 0;
		d->ray.plane_y = 0;
		d->player.dir_y = 1;
		d->ray.plane_x = -.6;
		if (d->player.letter == 'N')
		{
			d->player.dir_y = -1;
			d->ray.plane_x = .6;
		}
	}
	else if (d->player.letter == 'E' || d->player.letter == 'W')
	{
		d->player.dir_y = 0;
		d->ray.plane_x = 0;
		d->player.dir_x = -1;
		d->ray.plane_y = -.6;
		if (d->player.letter == 'E')
		{
			d->player.dir_x = 1;
			d->ray.plane_y = .6;
		}
	}
}
