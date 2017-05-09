/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:17:03 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:06:45 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <move.h>

int				move_up(t_list *files, t_list **pos)
{
	t_list		*prev;
	t_list		*tmp;

	if (!files || !pos || !*pos)
		return (0);
	if ((*pos)->prev)
		prev = (*pos)->prev;
	else
	{
		tmp = files;
		while (tmp->next)
			tmp = tmp->next;
		prev = tmp;
	}
	((t_file*)((*pos)->content))->current = 0;
	((t_file*)(prev->content))->current = 1;
	*pos = prev;
	return (1);
}

int				move_down(t_list *files, t_list **pos)
{
	t_list		*next;

	if (!files || !pos || !*pos)
		return (0);
	next = !((*pos)->next) ? files : (*pos)->next;
	((t_file*)((*pos)->content))->current = 0;
	((t_file*)(next->content))->current = 1;
	*pos = next;
	return (1);
}

int				move_left(t_list *files, t_list **pos)
{
	t_list		*next;
	t_select	*stock;

	if (!files || !pos || !*pos)
		return (0);
	next = *pos;
	stock = stock_data(NULL);
	if ((stock->display).col == 1)
		move_up(files, pos);
	else
		ft_lstjump_circle(files, pos,
			get_njump(stock->display,
				ft_lstpos(files, *pos), ft_lstlen(files), LEFT));
	((t_file*)((*pos)->content))->current = 1;
	if (next != *pos)
		((t_file*)(next->content))->current = 0;
	return (1);
}

int				move_right(t_list *files, t_list **pos)
{
	t_list		*next;
	t_select	*stock;

	if (!files || !pos || !*pos)
		return (0);
	next = *pos;
	stock = stock_data(NULL);
	if ((stock->display).col == 1)
		move_down(files, pos);
	else
		ft_lstjump_circle(files, pos,
			get_njump(stock->display,
				ft_lstpos(files, *pos), ft_lstlen(files), RIGHT));
	((t_file*)((*pos)->content))->current = 1;
	if (next != *pos)
		((t_file*)(next->content))->current = 0;
	return (1);
}
