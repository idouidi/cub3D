/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:52:07 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 11:52:08 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t n)
{
	void *mem;

	if (!(mem = malloc(sizeof(n))))
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
