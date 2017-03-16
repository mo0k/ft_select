/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:59:51 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 02:05:09 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPES_H
# define MY_TYPES_H

# include <ft_select.h>

typedef struct	termios t_term;

typedef unsigned int t_uint;

typedef struct	s_file
{
	char	*name;
	int		selected;
	int		current;
}				t_file;

typedef struct s_win
{
	t_uint	col;
	t_uint	row;
}				t_win;

typedef struct s_display
{
	t_uint	col;
	t_uint	row;
}				t_display;

typedef struct	s_select
{
	t_term		*new_term;
	t_term		*origin_term;
	t_win		winsize;
	t_list		*file;
	t_display	display;
	int			id_mode;
	char 		*search;
	int			len_items;
	int			lstlen;
	int			selected;
}				t_select;

#endif