/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 05:44:49 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/21 07:15:49 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_lign(t_mega *all, char **buf)
{
	int i;

	i = 0;
	while (buf[i])
		i++;
	if (all->p.map_width == 0)
		all->p.map_width = i;
	else
	{
		if (i != all->p.map_width)
			error(FILE_NOT_VALID, all);
	}
	return (i);
}

int		how_many_lign(char *file)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		error(NO_SUCH_FILE, NULL);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (i);
}

void	reader_parser_file(t_mega *all, int fd, int **tab)
{
	char	*line;
	char	**buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buf = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_strsplit(line, ' ');
		ft_strdel(&line);
		check_lign(all, buf);
		tab[j] = (int *)ft_memalloc(sizeof(int) * all->p.map_width);
		if (!tab[j])
			error(SYSCALL_FAIL, all);
		while (buf[i])
		{
			tab[j][i] = ft_atoi(buf[i]);
			i++;
		}
		i = 0;
		j++;
		all->p.map_height++;
	}
}

int		**get_matrice_of_map(t_mega *all)
{
	int		**tab;
	int		fd;
	int		len;

	if ((fd = open(all->p.file, O_RDONLY)) == -1)
		error(NO_SUCH_FILE, all);
	len = how_many_lign(all->p.file);
	tab = (int **)ft_memalloc(sizeof(int *) * len + 1);
	if (!tab)
		error(SYSCALL_FAIL, all);
	reader_parser_file(all, fd, tab);
	if (close(fd) == -1)
		error(SYSCALL_FAIL, all);
	return (tab);
}

int		**read_map(t_mega *all)
{
	all->p.map_width = 0;
	all->p.map_height = 0;
	return (get_matrice_of_map(all));
}
