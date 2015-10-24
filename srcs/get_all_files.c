/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:24:23 by jripoute          #+#    #+#             */
/*   Updated: 2015/01/21 07:20:00 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct dirent	t_dirent;

void		change_file(t_mega *all, t_dlist *next, int dir)
{
	free_all(all);
	if (next == NULL && dir == LEFT)
		all->files = ft_dlstlast(all->files);
	else if (next == NULL && dir == RIGHT)
		all->files = ft_dlstfirst(all->files);
	else
		all->files = next;
	all->p.file = ft_strdup(all->files->content);
	get_full_matrix_isomap(all);
}

void		insert_sort(char *da_file, t_dlist **files, t_mega *all)
{
	int			len;
	t_dlist		*nav;
	struct stat	sb;

	len = ft_dlstlen(*files);
	nav = ft_dlstlast(*files);
	da_file = ft_strjoin(all->p.file, da_file);
	if (stat(da_file, &sb) != -1
		&& !(S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode)))
	{
		return ;
	}
	while (len > 0)
	{
		if (ft_strcmp(nav->content, da_file) < 0)
			break ;
		nav = nav->before;
		len--;
	}
	ft_dlstadd_i(files, ft_dlstnew(da_file, (ft_strlen(da_file) + 1)), len);
}

t_dlist		*get_all_files(t_mega *all)
{
	struct stat		sb;
	t_dirent		*dirent;
	t_dlist			*files;
	DIR				*dir;
	int				len;

	files = NULL;
	all->p.path = NULL;
	len = ft_strlen(all->p.file);
	if (stat(all->p.file, &sb) != -1 && S_ISDIR(sb.st_mode))
	{
		all->p.path = all->p.file[len] == '/' ? ft_strdup(all->p.file)
		: ft_strjoin(all->p.file, "/");
		if ((dir = opendir(all->p.file)) == NULL)
			error(NO_SUCH_FILE, all);
		while ((dirent = readdir(dir)) != NULL)
			if (ft_strncmp(dirent->d_name, ".", 1) != 0)
				insert_sort(dirent->d_name, &files, all);
		if (closedir(dir) == -1)
			error(SYSCALL_FAIL, NULL);
		return (files);
	}
	return (NULL);
}
