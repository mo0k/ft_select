/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:18:36 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:29:33 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_lstpos(t_list *list, t_list *elem)
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
