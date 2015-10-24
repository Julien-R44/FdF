/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 03:36:40 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 03:08:31 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "img_n_colors.h"
# include "keys_n_error.h"

# define LENGHT_WINDOW 2150
# define HEIGHT_WINDOW 1200

# define MOVE_POW 50
# define ZOOM_POW 1

typedef struct	s_env
{
	void		*mlx;
	void		*wmlx;
}				t_env;

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef	struct	s_map
{
	int			**matrix;
	t_pos		**isomap;
}				t_map;

typedef	struct	s_buf
{
	int			proj;
	int			powz;
	int			posx;
	int			posy;
	int			mult;
	int			noquad;
}				t_buf;

typedef struct	s_para
{
	char		*file;
	char		*path;
	int			refresh;
	int			rotation;
	int			map_width;
	int			map_height;
}				t_para;

typedef	struct	s_mega
{
	t_env		e;
	t_para		p;
	t_map		map;
	t_buf		buf;
	t_img		img;
	t_color		color;
	t_palet		palet;
	t_dlist		*files;
}				t_mega;

/*
** main.c
*/
int				expose_hook(t_mega *all);
int				check_av_palet(int ac, char **av);
void			get_full_matrix_isomap(t_mega *all);

/*
** file2map.c
*/
int				**read_map(t_mega *all);
int				how_many_lign(char *file);
int				**get_matrice_of_map(t_mega *all);
int				check_lign(t_mega *all, char **buf);
void			reader_parser_file(t_mega *all, int fd, int **tab);

/*
** get_isomap.c
*/
t_pos			**get_iso_map(t_mega *all);
t_pos			cal_iso(int x, int y, int z, t_buf *buf);
t_pos			cal_para(int x, int y, int z, t_buf *buf);
t_pos			what_projection(int x, int y, int z, t_mega *all);

/*
** colors.c
*/
int				choose_color_z(t_mega *all, int i, int j);
void			palette_color2(t_mega *all);
void			palette_color(t_mega *all);

/*
** display_and_keyhook.c
*/
int				loop_hook(t_mega *all);
void			put_all_string(t_mega *all);
char			*what_palet_str(t_mega *all);
void			key_hook2(int keycode, t_mega *all);
int				key_hook(int keycode, t_mega *all);

/*
** stock_img.c
*/
void			set_color(t_color *c, int color);
int				bit_op_to_stock(t_color c);
void			put_or_stock_pix(t_mega *all, t_color *c, int x, int y);
void			print_or_stock_iso_map(t_mega *all);

/*
** get_all_files.c
*/
t_dlist			*get_all_files(t_mega *all);
void			change_file(t_mega *all, t_dlist *next, int dir);
void			insert_sort(char *da_file, t_dlist **files, t_mega *all);

/*
** moves.c
*/
void			change_proj(t_mega *all);
void			change_colors(t_mega *all);
void			vary_z(t_mega *all, int powz);
void			move_grid(t_mega *all, int x, int y);
void			zoom_map(t_mega *all, int zoom);

/*
** draw_line.c
*/
void			draw_on_x(t_mega *all, t_pos *p1, t_pos *p2);
void			draw_on_y(t_mega *all, t_pos *p1, t_pos *p2);
int				draw_lign(t_mega *all, t_pos *p1, t_pos *p2);

/*
** iso_rot.c
*/
void			rev_map(t_mega *all);
void			rev_map2(t_mega *all);
void			rev_map2_2(t_mega *all, t_pos **tmp, int **tmp2);
void			rotate_map(t_mega *all, int way);
void			update_map(t_mega *all);

/*
** misc.c
*/
void			error(int er, t_mega *all);
void			reset_camera(t_mega *all, int palet);
void			init_all(t_mega *all, int color, char *filename);
void			free_all(t_mega *all);

#endif
