/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:17:20 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:17:21 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sort_sprites(t_data *d)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < d->count_spt - 1)
	{
		j = i + 1;
		if (d->spt[i].dist < d->spt[j].dist)
		{
			tmp = d->spt[i];
			d->spt[i] = d->spt[j];
			d->spt[j] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	adjust_sprites_order(t_data *d)
{
	int z;

	z = 0;
	while (z < d->count_spt)
	{
		d->spt[z].dist = (pow((d->player.pos_x - d->spt[z].x), 2) +
						pow((d->player.pos_y - d->spt[z].y), 2));
		z++;
	}
	sort_sprites(d);
}
