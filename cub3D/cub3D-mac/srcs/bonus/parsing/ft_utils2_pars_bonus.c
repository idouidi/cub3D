/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_pars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:16:11 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:16:13 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int			check_empty_line(t_data *d)
{
	int i;

	i = 0;
	if (!d->tmp1)
		return (-1);
	while (d->tmp1[i])
	{
		if (d->tmp1[i] == '\n' && d->tmp1[i + 1] && d->tmp1[i + 1] == '\n')
			return (-2);
		i++;
	}
	return (0);
}

int			check_textures(t_data *d)
{
	if (open(d->sprite, O_RDONLY) < 0 || open(d->north, O_RDONLY) < 0 ||
	open(d->east, O_RDONLY) < 0 || open(d->south, O_RDONLY) < 0 ||
	open(d->west, O_RDONLY) < 0)
		return (-1);
	return (0);
}

void		set_var(t_data *d)
{
	d->map = NULL;
	d->resolution = NULL;
	d->floor = NULL;
	d->ceiling = NULL;
	d->sprite = NULL;
	d->north = NULL;
	d->east = NULL;
	d->south = NULL;
	d->west = NULL;
	d->spt = NULL;
	d->tmp = NULL;
	d->tmp1 = NULL;
	d->rays = 0;
	d->x = 0;
	d->map_x = 0;
	d->map_y = 0;
	d->player.pos_x = 0;
	d->player.pos_y = 0;
	d->player.letter = 0;
	d->count_spt = 0;
	while (d->x < 5)
	{
		d->img.ptr[(int)d->x] = 0;
		d->x++;
	}
}

void		set_position(t_data *d)
{
	int i;

	i = 0;
	while (d->map[d->map_y])
	{
		d->map_x = 0;
		while (d->map[d->map_y][d->map_x])
		{
			if (d->map[d->map_y][d->map_x] == '2')
			{
				d->spt[i].x = d->map_x + 0.5;
				d->spt[i].y = d->map_y + 0.5;
				i++;
			}
			if (ft_isalpha(d->map[d->map_y][d->map_x]) == 1)
			{
				d->player.pos_y = d->map_y + .5;
				d->player.pos_x = d->map_x + .5;
				d->player.letter = d->map[d->map_y][d->map_x];
				d->map[d->map_y][d->map_x] = '0';
			}
			d->map_x++;
		}
		d->map_y++;
	}
}

void		info_map_setup(char *s, int i, int *j, int *k)
{
	*j = i;
	*k = i;
	while (s[*k] && s[*k] != '.')
		*k += 1;
	while (s[*j] && s[*j] != '\n')
		*j += 1;
}
