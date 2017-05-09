/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstselect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:43:27 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/08 18:34:47 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstselect(t_list **alst, char *elem, int (*select)(t_list*, char*))
{
	t_list *cur;

	cur = *alst;
	if (!cur)
		return (NULL);
	while (cur)
	{
		if (select(cur, elem))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
