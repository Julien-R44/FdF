/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_isomap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 05:42:22 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/21 07:23:40 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos		what_projection(int x, int y, int z, t_mega *all)
{
	t_pos	pos;

	if (all->buf.proj == 0)
		pos = cal_iso(x, y, z, &all->buf);
	else if (all->buf.proj == 1)
		pos = cal_para(x, y, z, &all->buf);
	return (pos);
}

t_pos		cal_para(int x, int y, int z, t_buf *buf)
{
	int		cte1;
	t_pos	pos;

	cte1 = buf->powz;
	pos.x = buf->posx;
	pos.y = buf->posy;
	pos.x += x + (cte1 * -z);
	pos.y += y + (cte1 / 4) * -z;
	pos.x += (x * buf->mult);
	pos.y += (y * buf->mult);
	return (pos);
}

t_pos		cal_iso(int x, int y, int z, t_buf *buf)
{
	t_pos		pos;

	pos.x = -(y * buf->mult / 2) + (x * buf->mult / 2) + buf->posx;
	pos.y = (buf->mult / 2 + (y * buf->mult / 2) + (x * buf->mult / 2))
	/ 2 - (z * buf->powz) + buf->posy;
	return (pos);
}

t_pos		**get_iso_map(t_mega *all)
{
	t_pos	**isomap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	isomap = (t_pos **)ft_memalloc(sizeof(t_pos *) * all->p.map_height + 1);
	if (!isomap)
		error(SYSCALL_FAIL, all);
	while (i < all->p.map_height)
	{
		isomap[i] = (t_pos *)ft_memalloc(sizeof(t_pos) * all->p.map_width);
		if (!isomap[i])
			error(SYSCALL_FAIL, all);
		while (j < all->p.map_width)
		{
			isomap[i][j] = what_projection(j, i, all->map.matrix[i][j], all);
			j++;
		}
		j = 0;
		i++;
	}
	return (isomap);
}
