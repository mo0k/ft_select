/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:58:30 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 01:54:31 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int	my_isprint(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	else
		return (0);
}

int			my_putchar(int c)
{
	write(isatty(STDOUT_FILENO), &c, 1);
	return (1);
}

static int		init(t_select *stock)
{
	(stock->winsize).col = 0;
	(stock->winsize).row = 0;
	(stock->display).col = 0;
	(stock->display).row = 0;
	stock->file = NULL;
	stock->id_mode = ID_MOVE;
	stock->search = NULL;
	stock->len_items = 0;
	stock->lstlen = 0;
	stock->selected = 0;
	return (1);
}

void		init_winsize(t_win *winsize, t_uint row, t_uint col)
{
	winsize->col = col;
	winsize->row = row;
}

void		print_stock(t_select stock)
{
	printf("addr new_term:%p\n", &(stock.new_term));
	printf("addr origin_term:%p\n", &(stock.origin_term));
	printf("win col:%d\n", stock.winsize.col);
	printf("win row:%d\n", stock.winsize.row);
	//printf("display col:%d\n", stock.display.col);
	//printf("display row:%d\n", stock.display.row);
	printf("addr stock->file:%p\n", stock.file);
	printf("addr stock->lstlen:%d\n", stock.lstlen);
}

//pointer func ft_lstiter print elem if
void		result(t_list *elem)
{
	static int i;

	if (((t_file*)(elem->content))->selected == 1)
	{
		if (i)
			write(1, " ", 1);
		ft_putstr(((t_file*)(elem->content))->name);
		i = 1;
	}
} 
static void	search(t_list *files, t_list **pos, char *search)
{
	int i;
	t_list *cur;

	i  = 0;
	while (files)
	{
		if (!ft_strncmp(((t_file*)(files->content))->name, search, ft_strlen(search)))
		{
			if (!i)
				cur = files;
			++i;
		}
		files = files->next;
	}
	if (i && *pos != cur)
	{
		((t_file*)(cur->content))->current = 1;
		((t_file*)((*pos)->content))->current = 0;
		*pos = cur;
	}
}

static void	handler_codekey(char *buff, t_list **files, t_list **position)
{
	static int state;
	printf("%d %d %d %d\n", buff[0], buff[1], buff[2], buff[3]);
	if (!state && !my_isprint(buff[0]))
	{
		
		if (*buff == 27 && buff[1] == 91 && buff[2] == 65)
			move_up(*files, position);
		else if (*buff == 27 && buff[1] == 91 && buff[2] == 66)
			move_down(*files, position);
		else if (*buff == 27 && buff[1] == 91 && buff[2] == 67)
			move_right(*files, position);
		else if (*buff == 27 && buff[1] == 91 && buff[2] == 68)
			move_left(*files, position);
		else if (*buff == 32 && buff[1] == 0 && buff[2] == 0)
			do_select(*files, position);
		else if (*buff == 1 && buff[1] == 0 && buff[2] == 0)
			ft_lstiter(*files, &do_selectall);
		else if (*buff == 24 && buff[1] == 0 && buff[2] == 0)
			ft_lstiter(*files, &do_deselectall);
		else if (*buff == 10 && buff[1] == 0 && buff[2] == 0)
		{
			//close(stock_data(NULL)->tty_fd);
			//write(1, "\n", 1);
			restore_config_term();
			ft_lstiter(*files, &result);
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else if (*buff == 27 && buff[1] == 0 && buff[2] == 0)
			do_esc();
		else if (*buff == 127 && buff[1] == 0 && buff[2] == 0)
			do_delete(files, position);
		else if (*buff == 27 && buff[1] == 91 && buff[2] == 51 && buff[3] == 126)
			do_delete(files, position);
	}
	
	else
	{
		state = 1;
		//tputs(tgetstr("sc", NULL), AFFCNT, &my_putchar);
		//tputs(tgoto(tgetstr("cm", NULL), 1, 1), AFFCNT, &my_putchar);
		//ft_putstr_fd(M_SEARCH, isatty(STDOUT_FILENO));
		stock_data(NULL)->id_mode = ID_SEARCH;
		//tputs(tgetstr("rc", NULL), AFFCNT, &my_putchar);

		if (*buff == 27 && buff[1] == 0 && buff[2] == 0)
		{
			ft_bzero(stock_data(NULL)->search, ft_strlen(stock_data(NULL)->search));
			//tputs(tgoto(tgetstr("cm", NULL), 1, 1), AFFCNT, &my_putchar);
			stock_data(NULL)->id_mode = ID_MOVE;
			//ft_putstr_fd(M_MOVE, isatty(STDOUT_FILENO));
			//free(stock_data(NULL)->search);
			//stock_data(NULL)->search = NULL;
			state = 0;
		}
		else if (*buff == 10 && buff[1] == 0 && buff[2] == 0)
		{
			do_select(*files, position);
			//ft_bzero(stock_data(NULL)->search, ft_strlen(stock_data(NULL)->search));
			//free(stock_data(NULL)->search);
			//stock_data(NULL)->search = NULL;
			//state = 0;
		}
		else if (*buff == 127 && buff[1] == 0 && buff[2] == 0)
		{
			//printf("test\n");
			tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
			printf("....................%d\n", (int)ft_strlen(stock_data(NULL)->search));
			if (ft_strlen(stock_data(NULL)->search) > 0)
				stock_data(NULL)->search[ft_strlen(stock_data(NULL)->search) - 1] = 0;
			search(*files, position, stock_data(NULL)->search);
			//else
			//	state = 0;
			//if (!stock_data(NULL)->search[0])
			//{
			//	free(stock_data(NULL)->search);
				//stock_data(NULL)->search = NULL;
			//}
			//tputs(tgetstr("dm", NULL), AFFCNT, &my_putchar);

			//tputs(tgetstr("dc", NULL), AFFCNT, &my_putchar);
			//tputs(tgetstr("ed", NULL), AFFCNT, &my_putchar);

		}
		else if (ft_isprint(buff[0]))
		{
			//printf("%d\n", buff[0]);
			ft_addchar(&(stock_data(NULL)->search), buff[0]);
			search(*files, position, stock_data(NULL)->search);
		}
			
		//Pour rechercher dynamique
		//printf("test.............................\n");
		
		//printf("TEST.............................\n");

		//printf(".............................%s\n", stock->search);
		//write(isatty(STDOUT_FILENO), &buff[0], 1);
		//printf("test\n");
		//printf("%d %d %d\n", buff[0], buff[1], buff[2]);
	}
}

static int	ft_select(t_select	*stock)
{
	char	buff[4];
	t_list	*position;

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
	print_stock(*stock);
	while (42)
	{
		tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
		display(stock->file, stock->lstlen, ((t_win)(stock->winsize)).col,
		 		((t_win)(stock->winsize)).row);
		tputs(tgoto(tgetstr("cm", NULL), 0, ((t_win)(stock->winsize)).row), AFFCNT, &my_putchar);
		ft_putstr_fd(stock->search, isatty(STDOUT_FILENO));
		ft_memset(buff, 0, 4);
		read(STDIN_FILENO, &buff, 4);
		handler_codekey(buff, &(stock->file), &position);
	}
}

t_select *stock_data(t_select *elem)
{
	static t_select *tmp;

	if (elem)
		tmp = elem;
	else
		return (tmp);
	return (elem);
}

int		usage(void)
{
	ft_putstr(USAGE_PROG);
	return (0);
}

int		main(int ac, char **av)
{
	t_select stock;

	init(&stock);
	//print_stock(stock);
	stock_data(&stock);
	catch_signals();
	if (input(ac, av, &(stock.file)))
	{
		ft_select(&stock);
	}
	return(0);
}
