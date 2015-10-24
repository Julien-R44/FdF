/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 04:12:09 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 02:26:39 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			change_proj(t_mega *all)
{
	all->buf.proj++;
	if (all->buf.proj == 2)
		all->buf.proj = 0;
	if (all->buf.proj == 1)
		all->buf.posx = (LENGHT_WINDOW / 4);
	else
		all->buf.posx = (LENGHT_WINDOW) / 2;
	all->buf.posy = (HEIGHT_WINDOW / 4);
}

void			change_colors(t_mega *all)
{
	all->palet.what_palet++;
	if (all->palet.what_palet == 5)
		all->palet.what_palet = 1;
}

void			vary_z(t_mega *all, int powz)
{
	all->buf.powz += powz;
}

void			move_grid(t_mega *all, int x, int y)
{
	all->buf.posy += y;
	all->buf.posx += x;
}

void			zoom_map(t_mega *all, int zoom)
{
	all->buf.mult += zoom;
}
