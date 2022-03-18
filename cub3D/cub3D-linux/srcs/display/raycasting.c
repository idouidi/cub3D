/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:16:51 by idouidi           #+#    #+#             */
/*   Updated: 2021/02/10 18:56:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	raycasting(t_data *d)
{
	do_walls(d);
	do_sprites(d);
	if (d->save == 1)
	{
		create_bitmap(d);
		clean(d);
		close(d->fd);
		exit(0);
	}
}
