/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 05:46:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 21:53:31 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(int er, t_mega *all)
{
	if (er == NO_SUCH_FILE)
	{
		ft_putstr(all->p.file);
		ft_putstr(" : File dont exist\n");
	}
	if (er == SYSCALL_FAIL)
		ft_putstr("A sys or mlx function failed...\n");
	if (er == NOT_ENOUGH_AC)
		ft_putstr("usage : ./fdf <file_name> <colors_theme> -help\n");
	if (er == FILE_NOT_VALID)
	{
		ft_putstr(all->p.file);
		ft_putstr(" : File isn't valid!\n");
	}
	free_all(all);
	exit(-1);
}

void		reset_camera(t_mega *all, int palet)
{
	all->buf.proj = 0;
	all->buf.powz = 1;
	all->buf.posx = (LENGHT_WINDOW) / 2;
	all->buf.posy = (HEIGHT_WINDOW / 4);
	all->buf.mult = 50;
	all->buf.noquad = 0;
	all->map.matrix = NULL;
	all->map.isomap = NULL;
	all->palet.what_palet = palet;
	all->p.refresh = 1;
	all->p.rotation = 0;
}

void		init_all(t_mega *all, int palet, char *filename)
{
	int len;

	all->p.file = NULL;
	all->files = NULL;
	reset_camera(all, palet);
	if (filename)
	{
		len = ft_strlen(filename);
		if (ft_strcmp(&filename[len - 4], ".fdf") != 0 &&
			filename[len - 1] != '/')
			all->p.file = ft_strjoin(filename, "/");
		else
			all->p.file = ft_strdup(filename);
		all->files = get_all_files(all);
	}
}

void		free_all(t_mega *all)
{
	int i;

	i = 0;
	if (all->map.matrix)
	{
		while (i < all->p.map_height)
		{
			free(all->map.matrix[i]);
			i++;
		}
		free(all->map.matrix);
		all->map.matrix = NULL;
	}
	i = 0;
	if (all->map.isomap)
	{
		while (i < all->p.map_height)
		{
			free(all->map.isomap[i]);
			i++;
		}
		free(all->map.isomap);
	}
	if (all->p.file)
		free(all->p.file);
}
