/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:57:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:15:24 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <display.h>

static int			get_nbr_col(int lenlst, int row)
{
	int				ret;

	ret = lenlst / (row);
	if (lenlst % (row) != 0)
		ret++;
	return ((int)ret);
}

static void			do_display(t_list *f, int col, int line, int len_max)
{
	int				c_col;
	int				c_line;

	c_line = 0 + MARGIN_TOP;
	c_col = 0;
	tputs(tgetstr("cl", NULL), AFFCNT, &my_putchar);
	print_header(stock_data(NULL));
	tputs(tgoto(tgetstr("cm", NULL), c_col, c_line), AFFCNT, &my_putchar);
	while (c_col < col)
	{
		while (c_line < line)
		{
			printlist(f);
			++c_line;
			tputs(tgoto(tgetstr("cm", NULL), c_col, c_line),
				AFFCNT, &my_putchar);
			if (f && f->next)
				f = f->next;
			else
				return ;
		}
		c_line = 0 + MARGIN_TOP;
		c_col += len_max;
		tputs(tgoto(tgetstr("cm", NULL), c_col, c_line), AFFCNT, &my_putchar);
	}
}

static int			name_strlen_max(t_list *lst)
{
	int				len_max;
	int				len_tmp;

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
		(stock->display).col = get_nbr_col(lstlen,
								row - MARGIN_BOTTON - MARGIN_TOP);
	}
	if (!chk_winsize(col, row, (stock->display).col * len_max,
		(stock->display).row) || lstlen > (int)((stock->display).col *
		((stock->display).row - MARGIN_TOP)))
		return (ft_putendl_fd(ERR_WINSIZE, STDERR_FILENO));
	do_display(f, col, (stock->display).row, len_max);
	return ;
}
