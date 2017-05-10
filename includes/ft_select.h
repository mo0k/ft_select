/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:59:33 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 08:07:33 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <my_types.h>
# include <keyboard.h>
# include <input.h>
# include <terms.h>
# include <signals.h>
# include <action.h>
# include <move.h>
# include <search.h>
# include <print.h>
# include <display.h>

# define USAGE_PROG C_RED "Usage:" C_DFL " ./ft_select file1 file2 ...\n"

# define ERR_GETENV "Environnement TERM no define"
# define ERR_TGETENT_NOFOUND "The terminfo database could not be found"
# define ERR_TGETENT_NOENTRY "There is no such entry for TERM value"
# define ERR_TCGETATTR "Impossible to copy the terminal referenced's parameters"
# define ERR_WINSIZE "Terminal width is too small"

# define C_MODE	C_YELLOW
# define M_MOVE C_MODE "MODE MOVE" C_DFL
# define M_SEARCH C_MODE "MODE SEARCH" C_DFL
# define ID_MOVE 1
# define ID_SEARCH 2

int			usage(void);
t_select	*stock_data(t_select *elem);
int			init(t_select *stock);
void		init_winsize(t_win *winsize, t_uint row, t_uint col);
int			my_putchar(int c);
int			my_isprint(int c);
void		fatal(char *error);

#endif
