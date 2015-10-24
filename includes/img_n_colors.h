/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_n_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 06:23:47 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/22 03:09:43 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_N_COLORS_H
# define IMG_N_COLORS_H

# define BLACK 000000

typedef	enum	e_colors
{
	JUNGLE = 1,
	DESERT,
	SNOW,
	WHITE,
}				t_colors;

typedef	struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef	struct	s_palet
{
	int			what_palet;
	int			colors[7];
}				t_palet;

typedef	struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

#endif
