/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:00:48 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 15:02:38 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

static void			winsize_changed(void)
{
	t_select		*tmp;
	struct winsize	ws;

	tmp = stock_data(NULL);
	ioctl(isatty(STDOUT_FILENO), TIOCGWINSZ, &ws);
	init_winsize(&(tmp->winsize), ws.ws_row, ws.ws_col);
	if (ws.ws_row <= 2)
		return (ft_putendl_fd(ERR_WINSIZE, STDERR_FILENO));
	display(tmp->file, ft_lstlen(tmp->file), ((t_win)(tmp->winsize)).col,
	((t_win)(tmp->winsize)).row);
}

void				handler_signals(int sig)
{
	tputs(tgetstr("cl", NULL), 1, &my_putchar);
	if (sig == SIGWINCH)
		winsize_changed();
	else if (sig == SIGTSTP)
	{
		restore_config_term();
		signal(SIGTSTP, SIG_DFL);
		ioctl(isatty(STDOUT_FILENO), TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
	{
		catch_signals();
		init_config_term(stock_data(NULL)->new_term,
			stock_data(NULL)->origin_term);
		winsize_changed();
	}
	else
	{
		restore_config_term();
		exit(1);
	}
}
