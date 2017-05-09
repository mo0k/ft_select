/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:58:30 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:09:12 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int		ft_select(t_select *stock)
{
	char		buff[6];
	t_list		*position;

	if (!stock)
		return (0);
	position = stock->file;
	if (!(stock->new_term = (t_term*)malloc(sizeof(t_term))))
		exit(EXIT_FAILURE);
	if (!(stock->origin_term = (t_term*)malloc(sizeof(t_term))))
		exit(EXIT_FAILURE);
	init_config_term(stock->new_term, stock->origin_term);
	init_winsize(&(stock->winsize), tgetnum("li"), tgetnum("co"));
	stock->lstlen = ft_lstlen(stock->file);
	while (42)
	{
		tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
		display(stock->file, stock->lstlen, ((t_win)(stock->winsize)).col,
		((t_win)(stock->winsize)).row);
		tputs(tgoto(tgetstr("cm", NULL), 0, ((t_win)(stock->winsize)).row),
			AFFCNT, &my_putchar);
		ft_putstr_fd(stock->search, isatty(STDOUT_FILENO));
		ft_memset(buff, 0, 6);
		read(STDIN_FILENO, &buff, 6);
		keyboard_handler(buff, &(stock->file), &position);
	}
}

int				usage(void)
{
	ft_putstr(USAGE_PROG);
	return (0);
}

int				main(int ac, char **av)
{
	t_select	stock;

	init(&stock);
	stock_data(&stock);
	catch_signals();
	if (input(ac, av, &(stock.file)))
		ft_select(&stock);
	return (0);
}
