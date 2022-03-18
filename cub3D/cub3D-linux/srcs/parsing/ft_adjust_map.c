/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:17:27 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:17:28 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**noblank_2(char **s, int c, char *set)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		i = 0;
		while (s[k][i])
		{
			j = 0;
			while (set[j])
			{
				if (s[k][i] == set[j])
					s[k][i] = c;
				j++;
			}
			i++;
		}
		k++;
	}
	return (s);
}

char	*noblank(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			s[i] = c;
		i++;
	}
	return (s);
}

char	*adjust_str(char *tmp, char *m, int stock)
{
	int	k;

	k = 0;
	if (!(tmp = malloc(sizeof(char) * stock + 1)))
		return (NULL);
	while (m[k])
	{
		tmp[k] = m[k];
		k++;
		stock--;
	}
	while (stock)
	{
		tmp[k] = '*';
		k++;
		stock--;
	}
	tmp[k] = '\0';
	return (tmp);
}

void	leak_2(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		map[i] = NULL;
		free(map);
	}
}

void	adjust_map(t_data *d)
{
	int				i;
	unsigned int	stock;
	char			**tmp;
	int				j;

	i = 0;
	j = 0;
	stock = 0;
	while (d->map[i])
	{
		stock = (stock > ft_strlen(d->map[i])) ? stock : ft_strlen(d->map[i]);
		i++;
	}
	if (!(tmp = calloc(i + 1, sizeof(char*))))
		return ;
	while (j < i)
	{
		tmp[j] = adjust_str(tmp[j], d->map[j], stock);
		tmp[j] = noblank(tmp[j], '*');
		j++;
	}
	tmp[i] = NULL;
	leak_2(d->map);
	d->map = tmp;
}
