/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 02:06:51 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <action.h>

int		do_select(t_list *files, t_list **pos)
{
	if (((t_file*)((*pos)->content))->selected == 1)
	{
		stock_data(NULL)->selected--;
		((t_file*)((*pos)->content))->selected = 0;
	}
	else
	{
		stock_data(NULL)->selected++;
		((t_file*)((*pos)->content))->selected = 1;
	}
	move_down(files, pos);
	return (1);
}

int		do_esc(void)
{
	restore_config_term();
	exit(EXIT_FAILURE);
}

void	del(void *files, size_t size)
{
	(void)files;
	(void)size;
}

int		do_delete(t_list **files, t_list **pos)
{
	if (!files || !*files || !pos || !*pos)
		do_esc();

	if (((t_file*)((*pos)->content))->selected)
	{
			stock_data(NULL)->selected--;
			//;
	}
	if (*files == *pos)
	{
		ft_lstdelfirst(files, &del);
	}
	else
		ft_lstdelnext(&(*pos)->prev, &del);
	stock_data(NULL)->lstlen--;
	if (*files == NULL)
		do_esc();
	move_down(*files, pos);
	return (1);
}

void	do_selectall(t_list *elem)
{
	int *i;

	i = &stock_data(NULL)->selected;
	((t_file*)(elem->content))->selected = 1;
	if (*i < (int)stock_data(NULL)->lstlen)
		(*i)++; 
}

void	do_deselectall(t_list *elem)
{
	int *i;

	i = &stock_data(NULL)->selected;
	((t_file*)(elem->content))->selected = 0;
	if (*i > 0)
		(*i)--; 
}