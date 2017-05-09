/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:57:23 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 01:07:05 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		init(t_select *stock)
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

void	init_winsize(t_win *winsize, t_uint row, t_uint col)
{
	winsize->col = col;
	winsize->row = row;
}
