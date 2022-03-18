/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:18:07 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/14 13:59:39 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		iscub(char *s1, char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (-1);
		i--;
		j++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_data	d;

	d.fd = 0;
	if (av[1])
		d.fd = open(av[1], O_RDONLY);
	if ((ac == 3 && (ft_strlen(av[2]) != ft_strlen("--save") ||
	ft_strncmp(av[2], "--save", ft_strlen("--save") != 0))) || ac > 3 || ac < 2
	|| iscub(av[1], "buc.") == -1 || d.fd < 0)
	{
		ft_putstr("Error\nCheck that there are no errors, you have may be:\
		\n-too much or not enough argument\
		\n-made a bad option call\n-a file extension which is not \".cub\"\
		\n-a file which does not exist\n");
		return (-1);
	}
	d.save = (ac == 3) ? 1 : 0;
	return (cub3d(&d));
}
