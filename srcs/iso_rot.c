/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 03:20:42 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 02:35:42 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rev_map(t_mega *all)
{
	int		i;
	int		j;
	t_pos	*tmp;
	int		*tmp2;

	i = 0;
	j = all->p.map_height - 1;
	while (i < (all->p.map_height - 1) / 2)
	{
		tmp = all->map.isomap[i];
		all->map.isomap[i] = all->map.isomap[j];
		all->map.isomap[j] = tmp;
		tmp2 = all->map.matrix[i];
		all->map.matrix[i] = all->map.matrix[j];
		all->map.matrix[j] = tmp2;
		i++;
		j--;
	}
}

void		rev_map2_2(t_mega *all, t_pos **tmp, int **tmp2)
{
	int		i;
	int		j;
	int		tmp3;

	i = 0;
	j = 0;
	while (i < all->p.map_height)
		free(all->map.isomap[i++]);
	free(all->map.isomap);
	all->map.isomap = tmp;
	all->map.matrix = tmp2;
	tmp3 = all->p.map_height;
	all->p.map_height = all->p.map_width;
	all->p.map_width = tmp3;
}

void		rev_map2(t_mega *all)
{
	int		i;
	int		j;
	t_pos	**tmp;
	int		**tmp2;

	i = 0;
	j = 0;
	if ((tmp = (t_pos **)malloc(sizeof(t_pos *) * all->p.map_width)) == NULL)
		error(SYSCALL_FAIL, all);
	if ((tmp2 = (int **)ft_memalloc(sizeof(int *) * all->p.map_width)) == NULL)
		error(SYSCALL_FAIL, all);
	while (i < all->p.map_width)
	{
		tmp[i] = (t_pos *)malloc(sizeof(t_pos) * all->p.map_height);
		tmp2[i] = (int *)ft_memalloc(sizeof(t_pos) * all->p.map_height);
		while (j < all->p.map_height)
		{
			tmp[i][j] = all->map.isomap[j][i];
			tmp2[i][j] = all->map.matrix[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	rev_map2_2(all, tmp, tmp2);
}

void		rotate_map(t_mega *all, int way)
{
	if (way == 1)
	{
		rev_map(all);
		rev_map2(all);
	}
	else
	{
		rev_map2(all);
		rev_map(all);
	}
}

void		update_map(t_mega *all)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < all->p.map_height)
	{
		while (j < all->p.map_width)
		{
			all->map.isomap[i][j] = what_projection(j, i,
				all->map.matrix[i][j], all);
			j++;
		}
		j = 0;
		i++;
	}
}
