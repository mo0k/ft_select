/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:17:03 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 01:43:58 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <move.h>

int			move_up(t_list *files, t_list **pos)
{
	t_list	*prev;

	if (!files || !pos || !*pos)
		return (0);
	if ((*pos)->prev)
		prev = (*pos)->prev;
	else
	{
		t_list *tmp;

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

int			move_down(t_list *files, t_list **pos)
{
	t_list	*next;

	if (!files || !pos || !*pos)
		return (0);
	next = !((*pos)->next) ? files : (*pos)->next;
	((t_file*)((*pos)->content))->current = 0;
	((t_file*)(next->content))->current = 1;
	*pos = next;
	return (1);
}
/*
static int 			lstjump(t_list *lst, t_list **jump, int len)
{
	t_list *cur;

	cur = lst;
	while (cur && len > 0)
	{
		//printf("cur->next:%p\n", cur->next);
		cur = cur->next;
		--len;
	}
	if (!cur || len > 0)
	{
		*jump = NULL;
		return (0);
	}
	*jump = cur;
	return (1);
}
*/
static int 			lstjump_circle(t_list *lst, t_list **jump, int len)
{
	t_list *cur;

	cur = *jump;
	if (len < 0)
	{
		len *= -1;
		while (len > 0)
		{
			if (cur && !cur->prev)
				while (cur->next)
					cur = cur->next;
			else
				cur = cur->prev;
			--len;
		}
	}
	else
	{
		while (len > 0)
		{
			if (!cur)
				cur = lst;
			cur = cur->next;
			--len;
		}
	}
	*jump = ((cur) ? cur : lst);
	return (1);
}

static int	lstpos(t_list *list, t_list *elem)
{
	int		i;

	i = 1;
	if (!list || !elem)
		return (0);
	while (list)
	{
		if (list == elem)
			return (i);
		list = list->next;
		i++;
	}
	return (0);
}

int			move_left(t_list *files, t_list **pos)
{
	t_list	*next;
	t_select	*stock;

	if (!files || !pos || !*pos)
		return (0);
	next = *pos;
	stock = stock_data(NULL);
	if ((stock->display).col == 1)
		move_up(files, pos);
	else
		lstjump_circle(files, pos, get_njump(stock->display, lstpos(files, *pos), ft_lstlen(files), LEFT));
	((t_file*)((*pos)->content))->current = 1;
	if (next != *pos)
		((t_file*)(next->content))->current = 0;
	return (1);
}

int			move_right(t_list *files, t_list **pos)
{
	t_list	*next;
	t_select	*stock;

	if (!files || !pos || !*pos)
		return (0);
	next = *pos;
	stock = stock_data(NULL);
	if ((stock->display).col == 1)
		move_down(files, pos);
	else
		lstjump_circle(files, pos, get_njump(stock->display, lstpos(files, *pos), ft_lstlen(files), RIGHT));
	((t_file*)((*pos)->content))->current = 1;
	if (next != *pos)
		((t_file*)(next->content))->current = 0;
	return (1);
}