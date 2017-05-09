/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:43:16 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/08 18:34:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*tmp;

	prev = NULL;
	cur = *alst;
	if (!*alst)
		return ;
	while (cur)
	{
		tmp = cur->next;
		cur->next = cur->prev;
		cur->prev = tmp;
		prev = cur;
		cur = cur->prev;
	}
	*alst = prev;
}
