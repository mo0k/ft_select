/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:57:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/04/25 19:55:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <display.h>

static int			get_nbr_col(int lenlst, int row)
{
	int ret;

	ret = lenlst / (row);
	if (lenlst % (row) != 0)
		ret++;
	return ((int)ret);
}

static void			do_display(t_list *f, int col, int line, int len_max)
{
	int				count_col;
	int				count_line;

	count_line = 0 + MARGIN_TOP;
	count_col = 0;
	tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
	print_header(stock_data(NULL));
	tputs(tgoto(tgetstr("cm", NULL), count_col, count_line), AFFCNT, &my_putchar);
	while (count_col < col)
	{
		while (count_line < line)
		{
			printlist(f);
			//printf("%p\n", f);
			++count_line;
			tputs(tgoto(tgetstr("cm", NULL), count_col, count_line), AFFCNT, &my_putchar);
			if (f && f->next)
				f = f->next;
			else
				return ;
		}
		count_line = 0 + MARGIN_TOP;
		count_col += len_max;
		tputs(tgoto(tgetstr("cm", NULL), count_col, count_line), AFFCNT, &my_putchar);
	}
}

static int			name_strlen_max(t_list *lst)
{
	int			len_max;
	int			len_tmp;

	len_max = 0;
	while (lst)
	{
		if (len_max < (len_tmp = ft_strlen(((t_file*)(lst->content))->name)))
			len_max = len_tmp;
		lst = lst->next;
	}
	return (len_max);
}

static int			chk_winsize(int col, int row, int nbr_col, int nbr_row)
{
	return ((col < nbr_col || row < nbr_row - MARGIN_TOP) ? 0 : 1);
}

void				display(t_list *f, int lstlen, t_uint col, t_uint row)
{
	printf("IN DISPLAY \n");
	int				len_max;
	t_select		*stock;

	if (!f)
		return ;
	stock = stock_data(NULL);
	stock->len_items = name_strlen_max(f);
	len_max = stock->len_items + MARGIN_RIGHT + 4;
	if (lstlen + MARGIN_BOTTON + MARGIN_TOP <= (int)row)
	{
		(stock->display).row = lstlen + MARGIN_TOP;
		(stock->display).col = 1;
	}
	else
	{
		(stock->display).row = row - MARGIN_BOTTON;
		(stock->display).col = get_nbr_col(lstlen, row - MARGIN_BOTTON - MARGIN_TOP);
	}
	if (!chk_winsize(col, row, (stock->display).col * len_max, (stock->display).row)
		|| lstlen > (int)((stock->display).col * ((stock->display).row - MARGIN_TOP)))
		return (ft_putendl_fd(ERR_WINSIZE, STDERR_FILENO));
	printf("IN DISPLAY - BEFORE DO_DISPLAY\n");
	do_display(f, col, (stock->display).row, len_max);
	printf("IN DISPLAY - AFTER DO_DISPLAY\n");
	return ;
}