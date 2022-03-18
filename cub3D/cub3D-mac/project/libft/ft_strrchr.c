/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:54:42 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 11:54:43 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (n == 0)
		i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == n)
			return ((char *)str + i);
		i--;
	}
	if (i == -1)
		return ((char*)NULL);
	return (0);
}
