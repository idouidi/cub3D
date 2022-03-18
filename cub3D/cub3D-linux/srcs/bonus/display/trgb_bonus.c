/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:15:14 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/13 13:15:15 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	add_shade(t_data *d, int trgb, float dist)
{
	int		r;
	int		g;
	int		b;
	float	shade;

	if (d->map_y > d->map_x)
		shade = 1 - dist / d->map_y;
	else
		shade = 1 - dist / d->map_x;
	shade = pow(shade, 7);
	r = (get_r(trgb) >> 16) * shade;
	g = (get_g(trgb) >> 8) * shade;
	b = get_b(trgb) * shade;
	return (create_trgb(1, r, g, b));
}
