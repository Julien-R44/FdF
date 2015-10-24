/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 05:42:54 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/21 06:46:39 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			choose_color_z(t_mega *all, int i, int j)
{
	int color;
	int cz;
	int cz2;

	cz = all->map.matrix[i][j];
	cz2 = all->map.matrix[i][j + 1];
	if (cz <= -1 || cz2 <= -1)
		color = all->palet.colors[0];
	if (cz <= -35 || cz2 <= -5)
		color = all->palet.colors[1];
	if (cz == 0 && cz2 == 0)
	{
		if (all->buf.noquad)
			return (BLACK);
		color = all->palet.colors[2];
	}
	if (cz >= 1 || cz2 >= 1)
		color = all->palet.colors[3];
	if (cz >= 7 || cz2 >= 7)
		color = all->palet.colors[4];
	if (cz >= 12 || cz2 >= 12)
		color = all->palet.colors[5];
	if (cz >= 18 || cz2 >= 18)
		color = all->palet.colors[6];
	return (color);
}

void		palette_color2(t_mega *all)
{
	int i;

	i = 0;
	if (all->palet.what_palet == SNOW)
	{
		all->palet.colors[0] = 0xB0DBFE;
		all->palet.colors[1] = 0x7696BF;
		all->palet.colors[2] = 0xE1F3F5;
		all->palet.colors[3] = 0xCFF3F3;
		all->palet.colors[4] = 0xF1F2EC;
		all->palet.colors[5] = 0xFFFFFF;
		all->palet.colors[6] = 0xEFDEC2;
	}
	else if (all->palet.what_palet == WHITE)
	{
		while (i <= 6)
			all->palet.colors[i++] = 0xFFFFFF;
	}
}

void		palette_color(t_mega *all)
{
	if (all->palet.what_palet == JUNGLE)
	{
		all->palet.colors[0] = 0x00AFF3;
		all->palet.colors[1] = 0x73688C;
		all->palet.colors[2] = 0xFFD46B;
		all->palet.colors[3] = 0x59811C;
		all->palet.colors[4] = 0x8C6954;
		all->palet.colors[5] = 0x59331D;
		all->palet.colors[6] = 0xcecece;
	}
	else if (all->palet.what_palet == DESERT)
	{
		all->palet.colors[0] = 0xEFDEC2;
		all->palet.colors[1] = 0xD7AF72;
		all->palet.colors[2] = 0xDAC27C;
		all->palet.colors[3] = 0xCEAC41;
		all->palet.colors[4] = 0xDAC27C;
		all->palet.colors[5] = 0xA8651E;
		all->palet.colors[6] = 0xEFDEC2;
	}
	else
		palette_color2(all);
}
