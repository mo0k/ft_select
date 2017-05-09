/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:35:00 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <action.h>

int		do_select(t_list *files, t_list **pos, int *selected)
{
	if (((t_file*)((*pos)->content))->selected == 1)
	{
		(*selected)--;
		((t_file*)((*pos)->content))->selected = 0;
	}
	else
	{
		(*selected)++;
		((t_file*)((*pos)->content))->selected = 1;
	}
	move_down(files, pos);
	return (1);
}

void	do_selectall(t_list *elem)
{
	int	*i;

	i = &stock_data(NULL)->selected;
	((t_file*)(elem->content))->selected = 1;
	if (*i < (int)stock_data(NULL)->lstlen)
		(*i)++;
}

void	do_deselectall(t_list *elem)
{
	int	*i;

	i = &stock_data(NULL)->selected;
	((t_file*)(elem->content))->selected = 0;
	if (*i > 0)
		(*i)--;
}
