/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 00:57:52 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <action.h>

void	del(void *files, size_t size)
{
	free((t_file*)(files));
	files = NULL;
	(void)size;
}

int		do_delete(t_list **files, t_list **pos, int *selected, int *lstlen)
{
	t_list *temp;

	if (!files || !*files || !pos || !*pos)
		do_esc();
	if (((t_file*)((*pos)->content))->selected)
		(*selected)--;
	if (*files == *pos)
	{
		ft_lstdelfirst(pos, &del);
		*files = *pos;
		if (*pos)
			((t_file*)((*pos)->content))->current = 1;
	}
	else
	{
		temp = (*pos)->prev;
		ft_lstdelnext(&(*pos)->prev, &del);
		*pos = temp;
		move_down(*files, pos);
	}
	(*lstlen)--;
	if (*files == NULL)
		do_esc();
	return (1);
}
