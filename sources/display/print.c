/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 01:16:35 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 01:36:18 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <print.h>

static void		padding(int strlen, int maxlen, int fd)
{
	char		*spaces;
	int			nspace;

	if (maxlen < strlen)
		return ;
	if ((nspace = maxlen - strlen) == 1)
		write(fd, " ", 1);
	else
	{
		spaces = ft_strnew(nspace);
		ft_memset(spaces, ' ', nspace);
		write(fd, spaces, nspace);
		free(spaces);
	}
}

static void		set_style_cursor(int state)
{
	if (!state)
	{
		ft_putstr_fd(">", isatty(STDOUT_FILENO));
		tputs(tgetstr("us", NULL), AFFCNT, &my_putchar);
	}
	else
	{
		tputs(tgetstr("ue", NULL), AFFCNT, &my_putchar);
		ft_putstr_fd("<", isatty(STDOUT_FILENO));
	}
}

static void		set_style_selected(int state)
{
	if (!state)
	{
		tputs(tgetstr("mr", NULL), AFFCNT, &my_putchar);
		ft_putstr_fd(C_CYAN, isatty(STDOUT_FILENO));
	}
	else
	{
		ft_putstr_fd(C_DFL, isatty(STDOUT_FILENO));
		tputs(tgetstr("me", NULL), AFFCNT, &my_putchar);
	}
}

void			printlist(t_list *elem)
{
	if (!elem)
		return ;
	ft_putstrcolor_fd("|", isatty(STDOUT_FILENO), C_CYAN);
	if (((t_file*)(elem->content))->current == 1)
		set_style_cursor(0);
	else
		ft_putstr_fd(" ", isatty(STDOUT_FILENO));
	if (((t_file*)(elem->content))->selected == 1)
		set_style_selected(0);
	ft_putstr_fd(((t_file*)(elem->content))->name, isatty(STDOUT_FILENO));
	padding(ft_strlen(((t_file*)(elem->content))->name),
			stock_data(NULL)->len_items, isatty(STDOUT_FILENO));
	if (((t_file*)(elem->content))->selected == 1)
		set_style_selected(1);
	if (((t_file*)(elem->content))->current == 1)
		set_style_cursor(1);
	else
		ft_putstr_fd(" ", isatty(STDOUT_FILENO));
	ft_putstrcolor_fd("|", isatty(STDOUT_FILENO), C_CYAN);
}

void			print_header(t_select *stock)
{
	int x;

	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, &my_putchar);
	if (stock->id_mode == ID_MOVE)
		ft_putstr_fd(M_MOVE, isatty(STDOUT_FILENO));
	else if (stock_data(NULL)->id_mode == ID_SEARCH)
		ft_putstr_fd(M_SEARCH, isatty(STDOUT_FILENO));
	x = ((t_win)(stock->winsize)).col - ft_strlen("selected") - 1
			- (int)ft_nbrlen(stock->selected);
	tputs(tgoto(tgetstr("cm", NULL), x, 0), 1, &my_putchar);
	ft_putstr_fd("Selected:", isatty(STDOUT_FILENO));
	ft_putnbr_fd(stock->selected, isatty(STDOUT_FILENO));
}
