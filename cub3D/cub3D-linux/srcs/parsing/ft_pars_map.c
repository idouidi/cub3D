/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:17:40 by idouidi           #+#    #+#             */
/*   Updated: 2021/02/10 19:36:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		p(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '*')
			return (-1);
		i++;
	}
	return (0);
}

static int		check_m_content(t_data *d, int i, int j)
{
	if (d->map[i][j] != '1' && d->map[i][j] != '2' && d->map[i][j]
	!= '0' && d->map[i][j] != 'N' && d->map[i][j] != 'S' && d->map[i][j] != 'E'
	&& d->map[i][j] != 'W' && d->map[i][j] != '*')
		return (-1);
	if (d->map[i][j] == '2')
		d->count_spt++;
	return (0);
}

static int		m_content(t_data *d, int len, int check)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (d->map[++i])
	{
		while (d->map[i][++j])
		{
			if (check_m_content(d, i, j) != 0)
				return (-1);
			if (d->map[i][j] == 'N' || d->map[i][j] == 'S'
				|| d->map[i][j] == 'E' || d->map[i][j] == 'W')
			{
				if (i == 0 || i == len)
					return (-1);
				check++;
			}
		}
		j = 0;
	}
	if (check != 1)
		return (-1);
	return (0);
}

static int		check_pars_map(char **m, int i, int j, int len)
{
	if (m[i][j] == '*')
	{
		if (i > 0 && i < len)
			if (m[i - 1][j] && m[i + 1][j] && m[i][j - 1] && m[i][j + 1] &&
				((m[i][j - 1] == '2' || m[i][j - 1] == '0' ||
				ft_isalpha(m[i][j - 1])) || (m[i][j + 1] == '2' ||
				m[i][j + 1] == '0' || ft_isalpha(m[i][j + 1])) ||
				(m[i - 1][j] == '2' || m[i - 1][j] == '0' ||
				ft_isalpha(m[i - 1][j])) || (m[i + 1][j] == '2' ||
				m[i + 1][j] == '0' || ft_isalpha(m[i + 1][j]))))
				return (-1);
		if (i == 0 && (m[i + 1][j] == '2' || m[i + 1][j] == '0' ||
		ft_isalpha(m[i + 1][j])))
			return (-1);
		if (i == len && (m[i - 1][j] == '2' || m[i - 1][j] == '0' ||
		ft_isalpha(m[i - 1][j])))
			return (-1);
	}
	return (0);
}

int				pars_map(t_data *d, int len)
{
	int				i;
	unsigned int	j;
	int				check;

	i = 0;
	j = 1;
	check = 0;
	if (p(d->map[0]) != 0 || p(d->map[len]) != 0
	|| m_content(d, len, check) != 0)
		return (-1);
	while (d->map[i])
	{
		if (border(d->map[i]) != 0)
			return (-1);
		while (d->map[i][j])
		{
			if (check_pars_map(d->map, i, j, len) != 0)
				return (-1);
			j++;
		}
		i++;
		j = 1;
	}
	return (0);
}
