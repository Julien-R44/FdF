/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 04:25:53 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 02:28:09 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_color(t_color *c, int color)
{
	color = (color & 0x00FFFFFF);
	c->b = (color & 0xFF);
	color = color >> 8;
	c->g = (color & 0xFF);
	color = color >> 8;
	c->r = color;
}

int			bit_op_to_stock(t_color c)
{
	int			i;

	i = c.r;
	i = i << 8;
	i += c.g;
	i = i << 8;
	i += c.b;
	return (i);
}

void		put_or_stock_pix(t_mega *all, t_color *c, int x, int y)
{
	unsigned int color;

	color = bit_op_to_stock(*c);
	if ((x >= 0 && x <= LENGHT_WINDOW - 1) && (y >= 0 && y <= HEIGHT_WINDOW))
		ft_memcpy(&all->img.data[x * 4 + y * all->img.sizeline],
			&color, (sizeof(int)));
}

void		print_or_stock_iso_map(t_mega *all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	palette_color(all);
	while (i < all->p.map_height)
	{
		while (j + 1 < all->p.map_width)
		{
			set_color(&all->color, choose_color_z(all, i, j));
			draw_lign(all, &all->map.isomap[i][j], &all->map.isomap[i][j + 1]);
			if (i + 1 < all->p.map_height)
				draw_lign(all, &all->map.isomap[i][j],
					&all->map.isomap[i + 1][j]);
			j++;
		}
		if (i + 1 < all->p.map_height)
			draw_lign(all, &all->map.isomap[i][j], &all->map.isomap[i + 1][j]);
		j = 0;
		i++;
	}
}
