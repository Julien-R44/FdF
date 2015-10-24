/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 04:17:36 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/21 07:07:07 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_on_x(t_mega *all, t_pos *p1, t_pos *p2)
{
	int	x;
	int	y;

	if (p1->x < p2->x)
	{
		x = p1->x;
		while (x <= p2->x)
		{
			y = p1->y + ((p2->y - p1->y) * (x - p1->x)) / (p2->x - p1->x);
			put_or_stock_pix(all, &all->color, x, y);
			x++;
		}
	}
	else
	{
		x = p2->x;
		while (x <= p1->x)
		{
			y = p2->y + ((p1->y - p2->y) * (x - p2->x)) / (p1->x - p2->x);
			put_or_stock_pix(all, &all->color, x, y);
			x++;
		}
	}
}

void		draw_on_y(t_mega *all, t_pos *p1, t_pos *p2)
{
	int	x;
	int	y;

	if (p1->y < p2->y)
	{
		y = p1->y;
		while (y <= p2->y)
		{
			x = p1->x + ((p2->x - p1->x) * (y - p1->y)) / (p2->y - p1->y);
			put_or_stock_pix(all, &all->color, x, y);
			y++;
		}
	}
	else
	{
		y = p2->y;
		while (y <= p1->y)
		{
			x = p2->x + ((p1->x - p2->x) * (y - p2->y)) / (p1->y - p2->y);
			put_or_stock_pix(all, &all->color, x, y);
			y++;
		}
	}
}

int			draw_lign(t_mega *all, t_pos *p1, t_pos *p2)
{
	if (p1->x == p2->x && p1->y == p2->y)
		return (0);
	if (abs(p2->y - p1->y) >= abs(p2->x - p1->x))
		draw_on_y(all, p1, p2);
	else
		draw_on_x(all, p1, p2);
	return (0);
}
