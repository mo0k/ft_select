/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:18:28 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/08 20:21:12 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_lstjump(t_list *lst, t_list **jump, int len)
{
	t_list *cur;

	cur = lst;
	while (cur && len > 0)
	{
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
