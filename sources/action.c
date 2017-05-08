/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/08 13:49:39 by mo0ky            ###   ########.fr       */
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
	//free(((t_file*)(files))->name);
	//((t_file*)(files))->name = NULL;
	printf("...........%p...........files:%lu, files*:%lu\n", files, sizeof(t_file), sizeof(t_file*));
	//
	free((t_file*)(files));
	//free((files));
	printf(".......AFTER FREE...\n");
	files = NULL;
	(void)size;
}

int		do_delete(t_list **files, t_list **pos)
{
	t_list *temp;
	if (!files || !*files || !pos || !*pos)
		do_esc();

	if (((t_file*)((*pos)->content))->selected)
			stock_data(NULL)->selected--;
	if (*files == *pos)
	{
		printf("avant ft_lstdelfirst\n");
		ft_lstdelfirst(pos, &del);
		*files = *pos;
		if (*pos)
			((t_file*)((*pos)->content))->current = 1;
		printf("apres ft_lstdelfirst\n");
	}
	else
	{
		printf("avant ft_lstdelnest\n");
		temp = (*pos)->prev;
		ft_lstdelnext(&(*pos)->prev, &del);
		*pos = temp;
		printf("apres ft_lstdelnest\n");
		move_down(*files, pos);
	}
	printf("TEST.............................................\n");
	stock_data(NULL)->lstlen--;
	if (*files == NULL)
		do_esc();

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