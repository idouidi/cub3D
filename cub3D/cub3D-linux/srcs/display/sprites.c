/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:16:56 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:16:58 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_spt_color(t_data *d, int stripe)
{
	char	*color;
	double	tex_y;
	double	tex_x;

	tex_y = (d->y * 2 - d->res[1] + d->spriteheight) *
		(d->texture.height[0] / 2) / d->spriteheight;
	tex_x = (int)(256 * (stripe - (-d->spritewidth / 2 + d->spritescreen_x))
	* d->texture.width[0] / d->spritewidth) / 256;
	color = d->texture.addr[0] + (abs((int)tex_y) * d->texture.szl[0] +
	(int)tex_x * (d->texture.bpp[0] / 8));
	return (*(unsigned int*)color);
}

void	set_drawsprites(t_data *d, int i)
{
	d->sprite_x = d->spt[i].x - d->player.pos_x;
	d->sprite_y = d->spt[i].y - d->player.pos_y;
	d->invdet = 1 / (d->ray.plane_x * d->player.dir_y - d->player.dir_x *
	d->ray.plane_y);
	d->transform_x = d->invdet * (d->player.dir_y * d->sprite_x -
	d->player.dir_x * d->sprite_y);
	d->transform_y = d->invdet * (-d->ray.plane_y * d->sprite_x +
	d->ray.plane_x * d->sprite_y);
	d->spritescreen_x = (int)((d->res[0] / 2) * (1 + d->transform_x /
	d->transform_y));
	d->spriteheight = abs((int)(d->res[1] / d->transform_y));
	d->spritewidth = abs((int)(d->res[1] / d->transform_y)) / 2;
	d->drawstart_y = -d->spriteheight / 2 + d->res[1] / 2;
	d->drawend_y = d->spriteheight / 2 + d->res[1] / 2;
	d->drawstart_x = -d->spritewidth / 2 + d->spritescreen_x;
	d->drawend_x = d->spritewidth / 2 + d->spritescreen_x;
}

void	limit_to_draw(t_data *d)
{
	if (d->drawstart_y < 0)
		d->drawstart_y = 0;
	if (d->drawend_y >= d->res[1])
		d->drawend_y = d->res[1] - 1;
	if (d->drawstart_x < 0)
		d->drawstart_x = 0;
	if (d->drawend_x >= d->res[0])
		d->drawend_x = d->res[0] - 1;
}

void	drawsprites(t_data *d, int stripe, int col, int color)
{
	while (stripe < d->drawend_x)
	{
		d->x = stripe;
		d->y = d->drawstart_y;
		if (d->transform_y > 0 && stripe > 0 && stripe < d->res[0] &&
		d->transform_y < d->rays[stripe])
		{
			col = d->drawstart_y;
			while (col < d->drawend_y)
			{
				d->y = col;
				color = get_spt_color(d, stripe);
				if (color)
					my_mlx_pixel_put(d, color);
				col++;
			}
		}
		stripe++;
	}
}

void	do_sprites(t_data *d)
{
	int	i;
	int	color;
	int	col;
	int	stripe;

	adjust_sprites_order(d);
	i = 0;
	col = 0;
	color = 0;
	while (i < d->count_spt)
	{
		set_drawsprites(d, i);
		limit_to_draw(d);
		stripe = d->drawstart_x;
		drawsprites(d, stripe, col, color);
		i++;
	}
}
