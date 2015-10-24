/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_and_keyhook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 04:07:45 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 01:21:58 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook2(int keycode, t_mega *all)
{
	if (keycode == N)
		all->buf.noquad = all->buf.noquad == 1 ? 0 : 1;
	else if (keycode == UP)
		zoom_map(all, ZOOM_POW);
	else if (keycode == DOWN)
		zoom_map(all, -ZOOM_POW);
	else if (keycode == SPACE)
		change_proj(all);
	else if (keycode == TAB)
		change_colors(all);
	else if (keycode == RIGHT && all->files)
		change_file(all, all->files->next, RIGHT);
	else if (keycode == LEFT && all->files)
		change_file(all, all->files->before, LEFT);
	else if (keycode == Q)
		rotate_map(all, -1);
	else if (keycode == E)
		rotate_map(all, 1);
}

int		key_hook(int keycode, t_mega *all)
{
	if (keycode)
	{
		ft_bzero(all->img.data, LENGHT_WINDOW * HEIGHT_WINDOW * 4);
		if (keycode == ECHAP)
			error(NO_ERROR, all);
		else if (keycode == W)
			vary_z(all, 1);
		else if (keycode == S)
			vary_z(all, -1);
		else if (keycode == K_8)
			move_grid(all, 0, -MOVE_POW);
		else if (keycode == K_2)
			move_grid(all, 0, MOVE_POW);
		else if (keycode == K_4)
			move_grid(all, -MOVE_POW, 0);
		else if (keycode == K_6)
			move_grid(all, MOVE_POW, 0);
		else if (keycode == N || keycode == SPACE || keycode == TAB
			|| keycode == RIGHT || keycode == LEFT || keycode == Q ||
			keycode == E || keycode == UP || keycode == DOWN)
			key_hook2(keycode, all);
		all->p.refresh = 1;
	}
	return (0);
}

char	*what_palet_str(t_mega *all)
{
	if (all->palet.what_palet == JUNGLE)
		return ("JUNGLE");
	if (all->palet.what_palet == DESERT)
		return ("DESERT");
	if (all->palet.what_palet == SNOW)
		return ("SNOW");
	if (all->palet.what_palet == WHITE)
		return ("WHITE");
	return (NULL);
}

void	put_all_string(t_mega *all)
{
	mlx_string_put(all->e.mlx, all->e.wmlx, (LENGHT_WINDOW / 2 - 70), 30,
		0xFFFFFF, "[ ===== Fil De Fer ===== ]");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 20, 0xFFFFFF, "Map :");
	mlx_string_put(all->e.mlx, all->e.wmlx, 60, 20, 0xFFFFFF, all->p.file);
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 40, 0xFFFFFF, "Colors :");
	mlx_string_put(all->e.mlx, all->e.wmlx, 73, 40,
		0xFFFFFF, what_palet_str(all));
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 60, 0xFFFFFF, "ESC : Exit");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 80,
		0xFFFFFF, "Q / E : Rotate");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 100,
		0xFFFFFF, "TAB : Change colors");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 120,
		0xFFFFFF, "KeypadNum : Move");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 140,
		0xFFFFFF, "Left/Right : Change map");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 160,
		0xFFFFFF, "W / S : Increase Z");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 180,
		0xFFFFFF, "N : Enable/disable grid");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 200,
		0xFFFFFF, "UP / DOWN : Zoom");
	mlx_string_put(all->e.mlx, all->e.wmlx, 20, 220,
		0xFFFFFF, "SpaceBar : Change projection");
}

int		loop_hook(t_mega *all)
{
	if (all->p.refresh == 1)
	{
		update_map(all);
		print_or_stock_iso_map(all);
		mlx_put_image_to_window(all->e.mlx, all->e.wmlx, all->img.img, 0, 0);
		put_all_string(all);
		all->p.refresh = 0;
	}
	return (0);
}
