/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:59:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 01:57:18 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdlib.h>
# include <sys/ioctl.h>	//iotcl
# include <unistd.h>	//read
# include <stdio.h>	//print
# include <fcntl.h> //open
# include <signal.h>
# include <my_types.h>
# include <input.h>
# include <manage_termios.h>
# include <manage_signals.h>
# include <action.h>
# include <move.h>
# include <print.h>
# include <display.h>

# define AFFCNT 1

# define USAGE_PROG C_RED "Usage:" C_DFL " ./ft_select file1 file2 ...\n"

# define ERR_GETENV "Environnement TERM no define"
# define ERR_TGETENT_NOFOUND "The terminfo database could not be found"
# define ERR_TGETENT_NOENTRY "There is no such entry for TERM value"
# define ERR_TCGETATTR "Impossible to copy the parameters associated with the terminal referenced"
# define ERR_WINSIZE "Terminal width is too small"

# define C_MODE	C_YELLOW
# define M_MOVE C_MODE "MODE MOVE" C_DFL
# define M_SEARCH C_MODE "MODE SEARCH" C_DFL
# define ID_MOVE 1
# define ID_SEARCH 2

int		usage(void);
t_select	*stock_data(t_select *elem);
void		init_winsize(t_win *winsize, t_uint row, t_uint col);
void		print_stock(t_select stock);
int		my_putchar(int c);
void		result(t_list *elem);
void 		fatal(char *error);

#endif
