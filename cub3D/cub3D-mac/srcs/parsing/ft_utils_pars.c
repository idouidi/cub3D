/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:17:56 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:17:57 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char		*fill_str(char *s1, char *s2, int i, int j)
{
	int	k;

	k = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	s2[k] = '\0';
	return (s2);
}

void		leak(void *str)
{
	if (str)
	{
		free(str);
		str = 0;
	}
}

int			flags(char c)
{
	if (c == 'R' || c == 'F' || c == 'S' || c == 'C' || c == 'N' || c == 'W'
			|| c == 'E')
		return (0);
	return (-1);
}

int			is_flags(char *s, int i)
{
	if (flags(s[i]) == 0)
	{
		if (((s[i + 1] == 'O' && (s[i] == 'N' || s[i] == 'S'))
		|| (s[i + 1] == 'E' && s[i] == 'W') || (s[i + 1] == 'A' && s[i] == 'E'))
		&& (s[i + 2] == ' ' || s[i + 2] == '	'))
			return (0);
		else if ((s[i] != 'N' && s[i] != 'W' && s[i] != 'E') &&
			(s[i + 1] == ' ' || s[i + 1] == '\t'))
			return (0);
	}
	return (-1);
}

int			border(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s[i] == '1' && s[j] == '1')
		return (0);
	if (s[i] == '*' || s[j] == '*')
	{
		while (s[i] && s[i] == '*')
			i++;
		while (j > 0 && s[j] == '*')
			j--;
		if ((s[i] == '1' && s[j] == '1') || j == 0)
			return (0);
	}
	return (-1);
}
