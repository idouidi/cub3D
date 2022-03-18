/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:17:45 by idouidi           #+#    #+#             */
/*   Updated: 2021/02/10 18:19:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		info_map(t_data *d, char *s, int i)
{
	int	j;
	int	k;

	info_map_setup(s, i, &j, &k);
	if (s[i] == 'R' && !d->resolution)
		d->resolution = fill_str(s, d->resolution, i, j);
	if (s[i] == 'F' && !d->floor)
		d->floor = fill_str(s, d->floor, i, j);
	if (s[i] == 'C' && !d->ceiling)
		d->ceiling = fill_str(s, d->ceiling, i, j);
	if (s[i] == 'N' && !d->north)
		d->north = fill_str(s, d->north, k, j);
	if (s[i] == 'W' && !d->west)
		d->west = fill_str(s, d->west, k, j);
	if (s[i] == 'E' && !d->east)
		d->east = fill_str(s, d->east, k, j);
	if (s[i] == 'S')
	{
		if (s[i + 1] == 'O' && !d->south)
			d->south = fill_str(s, d->south, k, j);
		else if (!d->sprite && (s[i + 1] == ' ' || s[i + 1] == '\t'))
			d->sprite = fill_str(s, d->sprite, k, j);
	}
}

static int	config_map(t_data *d)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (d->tmp[i])
	{
		if (d->tmp[i + 1] && d->tmp[i + 2] && is_flags(d->tmp, i) == 0)
		{
			info_map(d, d->tmp, i);
			check++;
			while (d->tmp[i] && d->tmp[i] != '\n')
				i++;
		}
		else if (d->tmp[i] != '\n')
			return (-1);
		if (check == 8)
		{
			d->tmp1 = ft_substr(d->tmp, i + 1, ft_strlen(d->tmp));
			return (0);
		}
		i++;
	}
	return (-1);
}

char		*my_read(int fd)
{
	char	*antileak;
	char	*save;
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ret = 0;
	save = NULL;
	antileak = NULL;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(antileak = ft_strjoin(save, buf)))
		{
			free(save);
			free(antileak);
			return (NULL);
		}
		save = antileak;
		antileak = NULL;
	}
	return (save);
}

int			map(t_data *data)
{
	data->tmp = my_read(data->fd);
	if (config_map(data) == -1)
		return (-1);
	if ((ft_strlen(data->tmp1) == 0) || check_empty_line(data) == -2)
		return (-2);
	data->map = ft_split((char *)data->tmp1, "\n");
	adjust_map(data);
	return (0);
}

int			pars_file(t_data *data)
{
	int		len;
	int		check;

	len = 0;
	check = map(data);
	if (check != 0)
		return (check);
	while (data->map[len])
		len++;
	if (pars_info_map(data) == -1 || check_textures(data) == -1 ||
		set_rfc(data) == -1)
		return (-1);
	if (pars_map(data, len - 1) == -1)
		return (-2);
	data->map = noblank_2(data->map, '1', "*");
	if (!(data->spt = malloc(sizeof(t_sprite) * (data->count_spt))))
		return (-1);
	set_position(data);
	data->map_y--;
	return (0);
}
