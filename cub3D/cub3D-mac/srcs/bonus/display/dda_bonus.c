/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:15:04 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:15:05 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int		get_tex_color(t_data *d, int i)
{
	char	*color;
	double	tex_y;
	double	tex_x;
	double	wall_x;

	tex_y = (d->y * 2 - d->res[1] + d->ray.line_height) *
		(d->texture.height[i] / 2) / d->ray.line_height;
	if (d->ray.hit_side == 0)
		wall_x = d->player.pos_y + d->ray.perpwalldist * d->ray.dir_y;
	else
		wall_x = d->player.pos_x + d->ray.perpwalldist * d->ray.dir_x;
	wall_x -= (int)wall_x;
	tex_x = (int)(wall_x * d->texture.width[i]);
	if ((d->ray.hit_side == 0 && d->ray.dir_x > 0) || (d->ray.hit_side == 1 &&
	d->ray.dir_y < 0))
		tex_x = d->texture.width[i] - tex_x - 1;
	color = d->texture.addr[i] + (abs((int)tex_y) * d->texture.szl[i] +
	(int)tex_x * (d->texture.bpp[i] / 8));
	return (*(unsigned int*)color);
}

void	draw_wall(t_data *d)
{
	int	drawstart;
	int drawend;
	int side;

	d->ray.line_height = (int)(d->res[1] / d->ray.perpwalldist);
	drawstart = -d->ray.line_height / 2 + d->res[1] / 2;
	drawend = d->ray.line_height / 2 + d->res[1] / 2;
	drawstart = (drawstart < 0) ? 0 : drawstart;
	drawend = (drawend >= d->res[1]) ? d->res[1] : drawend;
	side = (d->ray.hit_side == 0) ? d->player.map_x - d->player.pos_x :
									d->player.map_y - d->player.pos_y;
	while (drawstart < drawend)
	{
		d->y = drawstart;
		if (d->ray.hit_side)
			side < 0 ? my_mlx_pixel_put(d, add_shade(d, get_tex_color(d, 1),
			d->rays[(int)d->x])) : my_mlx_pixel_put(d,
			add_shade(d, get_tex_color(d, 2), d->rays[(int)d->x]));
		else
			side < 0 ? my_mlx_pixel_put(d, add_shade(d, get_tex_color(d, 3),
			d->rays[(int)d->x])) : my_mlx_pixel_put(d,
			add_shade(d, get_tex_color(d, 4), d->rays[(int)d->x]));
		drawstart++;
	}
}

void	initdist(t_data *d)
{
	if (d->ray.dir_x < 0)
	{
		d->ray.step_x = -1;
		d->ray.sidedist_x = (d->player.pos_x - d->player.map_x) *
		d->ray.deltadist_x;
	}
	else
	{
		d->ray.step_x = 1;
		d->ray.sidedist_x = (d->player.map_x + 1.0 - d->player.pos_x) *
		d->ray.deltadist_x;
	}
	if (d->ray.dir_y < 0)
	{
		d->ray.step_y = -1;
		d->ray.sidedist_y = (d->player.pos_y - d->player.map_y) *
		d->ray.deltadist_y;
	}
	else
	{
		d->ray.step_y = 1;
		d->ray.sidedist_y = (d->player.map_y + 1.0 - d->player.pos_y) *
		d->ray.deltadist_y;
	}
}

void	dda_loop(t_data *d)
{
	while (d->ray.hit == 0)
	{
		if (d->ray.sidedist_x < d->ray.sidedist_y)
		{
			d->ray.sidedist_x += d->ray.deltadist_x;
			d->player.map_x += d->ray.step_x;
			d->ray.hit_side = 0;
		}
		else
		{
			d->ray.sidedist_y += d->ray.deltadist_y;
			d->player.map_y += d->ray.step_y;
			d->ray.hit_side = 1;
		}
		if (d->map[d->player.map_y][d->player.map_x] == '1')
			d->ray.hit = 1;
	}
}

void	dda(t_data *d)
{
	d->ray.hit = 0;
	d->player.map_x = (int)(d->player.pos_x);
	d->player.map_y = (int)(d->player.pos_y);
	if (d->ray.dir_y != 0)
		d->ray.deltadist_x = (d->ray.dir_x == 0) ? 1 : fabs(1 / d->ray.dir_x);
	else
		d->ray.deltadist_x = 0;
	if (d->ray.dir_x != 0)
		d->ray.deltadist_y = (d->ray.dir_y == 0) ? 1 : fabs(1 / d->ray.dir_y);
	else
		d->ray.deltadist_y = 0;
	initdist(d);
	dda_loop(d);
	if (d->ray.hit_side == 0)
		d->ray.perpwalldist = (d->player.map_x - d->player.pos_x +
		(1 - d->ray.step_x) / 2) / d->ray.dir_x;
	else
		d->ray.perpwalldist = (d->player.map_y - d->player.pos_y +
		(1 - d->ray.step_y) / 2) / d->ray.dir_y;
	d->rays[(int)d->x] = d->ray.perpwalldist;
	draw_wall(d);
}
