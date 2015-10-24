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

#ifndef KEYS_N_ERROR_H
# define KEYS_N_ERROR_H

typedef enum	e_error
{
	NOT_ENOUGH_AC,
	FILE_NOT_VALID,
	NO_SUCH_FILE,
	SYSCALL_FAIL,
	NO_ERROR
}				t_error;

# ifdef __linux__

typedef enum	e_key2
{
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	ECHAP = 65307,
	SPACE = 32,
	TAB = 65289,
	K_8 = 65431,
	K_2 = 65433,
	K_4 = 65430,
	K_6 = 65432,
	W = 119,
	S = 115,
	N = 110,
	Q = 113,
	E = 101
}				t_key2;

# elif __APPLE__

typedef enum	e_key
{
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	ECHAP = 65307,
	SPACE = 32,
	TAB = 65289,
	K_8 = 65464,
	K_2 = 65458,
	K_4 = 65460,
	K_6 = 65462,
	W = 119,
	S = 115,
	N = 110,
	Q = 113,
	E = 101
}				t_key;

# endif

#endif
