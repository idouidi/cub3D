/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:14:37 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:14:39 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	do_walls(t_data *d)
{
	d->x = 0;
	while (d->x < d->res[0])
	{
		d->camera_x = 2 * d->x / d->res[0] - 1;
		d->ray.dir_x = d->player.dir_x + d->ray.plane_x * d->camera_x;
		d->ray.dir_y = d->player.dir_y + d->ray.plane_y * d->camera_x;
		dda(d);
		d->x++;
	}
}

int		get_color(t_data *d)
{
	char	*color;
	double	tex_y;
	double	tex_x;

	tex_y = d->y * d->texture.height[5] / d->res[1];
	tex_x = d->x * d->texture.width[5] / d->res[0];
	color = d->texture.addr[5] + (abs((int)tex_y) *
	d->texture.szl[5] + (int)tex_x * (d->texture.bpp[5] / 8));
	return (*(unsigned int *)color);
}

void	do_gun(t_data *d)
{
	int color;

	color = 0;
	d->x = 0;
	d->y = 0;
	while (d->x < d->res[0])
	{
		d->y = 0;
		while (d->y < d->res[1])
		{
			color = get_color(d);
			if (color > 0)
				my_mlx_pixel_put(d, color);
			d->y++;
		}
		d->x++;
	}
}

void	raycasting(t_data *d)
{
	do_walls(d);
	do_sprites(d);
	do_gun(d);
	if (d->save == 1)
	{
		create_bitmap(d);
		exit(1);
	}
}
