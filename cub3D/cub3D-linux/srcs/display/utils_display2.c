/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:17:14 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 16:13:43 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	which_dir2(t_data *d, int keycode)
{
	if (keycode == 100)
	{
		d->w_x = (int)(d->player.pos_x - d->player.dir_y * d->player.sp);
		d->w_y = (int)(d->player.pos_y + d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x -= d->player.dir_y * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_x * d->player.sp;
	}
	if (keycode == 97)
	{
		d->w_x = (int)(d->player.pos_x + d->player.dir_y * d->player.sp);
		d->w_y = (int)(d->player.pos_y - d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x += d->player.dir_y * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_x * d->player.sp;
	}
}

void	which_dir(t_data *d, int keycode)
{
	if (keycode == 119)
	{
		d->w_x = (int)(d->player.pos_x + d->player.dir_x * d->player.sp);
		d->w_y = (int)(d->player.pos_y + d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x += d->player.dir_x * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_y * d->player.sp;
	}
	if (keycode == 115)
	{
		d->w_x = (int)(d->player.pos_x - d->player.dir_x * d->player.sp);
		d->w_y = (int)(d->player.pos_y - d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x -= d->player.dir_x * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_y * d->player.sp;
	}
	which_dir2(d, keycode);
}

void	rotation(t_data *d, int keycode)
{
	double	old_dir;
	double	oldplane_x;

	old_dir = d->player.dir_x;
	oldplane_x = d->ray.plane_x;
	if (keycode == 65361)
	{
		d->player.dir_x = d->player.dir_x * cos(-.15) -
		d->player.dir_y * sin(-.15);
		d->player.dir_y = old_dir * sin(-.15) + d->player.dir_y * cos(-.15);
		d->ray.plane_x = d->ray.plane_x * cos(-.15) - d->ray.plane_y *
		sin(-.15);
		d->ray.plane_y = oldplane_x * sin(-.15) + d->ray.plane_y * cos(-.15);
	}
	if (keycode == 65363)
	{
		d->player.dir_x = d->player.dir_x * cos(.15) -
		d->player.dir_y * sin(.15);
		d->player.dir_y = old_dir * sin(.15) + d->player.dir_y * cos(.15);
		d->ray.plane_x = d->ray.plane_x * cos(.15) - d->ray.plane_y * sin(.15);
		d->ray.plane_y = oldplane_x * sin(.15) + d->ray.plane_y * cos(.15);
	}
}

int		cross_window(t_data *d)
{
	write(1, "Exit\n", 5);
	mlx_destroy_window(d->vars.mlx, d->vars.win);
	clean(d);
	close(d->fd);
	exit(0);
}
