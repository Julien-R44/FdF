/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 05:45:56 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/23 01:40:49 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_mega *all)
{
	all->p.refresh = 1;
	return (1);
}

int		check_av_palet(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-help"))
		{
			ft_putendl("usage : ./fdf <path_to_file> <colors_theme>");
			ft_putendl("Themes available :\tJUNGLE,");
			ft_putendl("\t\t\t DESERT,\n\t\t\t WHITE.");
			ft_putendl("By default, Jungle theme is enabled.");
			exit(-1);
		}
		if (ft_strequ(av[i], "JUNGLE"))
			return (JUNGLE);
		if (ft_strequ(av[i], "DESERT"))
			return (DESERT);
		if (ft_strequ(av[i], "WHITE"))
			return (WHITE);
		if (ft_strequ(av[i], "SNOW"))
			return (SNOW);
		i++;
	}
	return (JUNGLE);
}

void	get_full_matrix_isomap(t_mega *all)
{
	reset_camera(all, all->palet.what_palet);
	all->map.matrix = read_map(all);
	all->map.isomap = get_iso_map(all);
}

int		main(int ac, char **av)
{
	t_mega	all;

	init_all(&all, check_av_palet(ac, av), av[1]);
	if (ac < 2)
		error(NOT_ENOUGH_AC, &all);
	get_full_matrix_isomap(&all);
	if ((all.e.mlx = mlx_init()) == NULL)
		error(SYSCALL_FAIL, &all);
	all.e.wmlx = mlx_new_window(all.e.mlx, LENGHT_WINDOW, HEIGHT_WINDOW, "FdF");
	all.img.img = mlx_new_image(all.e.mlx, LENGHT_WINDOW, HEIGHT_WINDOW);
	all.img.data = mlx_get_data_addr(all.img.img, &all.img.bpp,
		&all.img.sizeline, &all.img.endian);
	mlx_loop_hook(all.e.mlx, loop_hook, &all);
	mlx_key_hook(all.e.wmlx, key_hook, &all);
	mlx_expose_hook(all.e.wmlx, expose_hook, &all);
	mlx_loop(all.e.mlx);
	return (0);
}
