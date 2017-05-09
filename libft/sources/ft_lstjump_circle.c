/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjump_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:18:22 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:29:23 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_lstjump_circle(t_list *lst, t_list **jump, int len)
{
	t_list	*cur;

	cur = *jump;
	if (len < 0)
	{
		len *= -1;
		while (len-- > 0)
		{
			if (cur && !cur->prev)
				while (cur->next)
					cur = cur->next;
			else
				cur = cur->prev;
		}
	}
	else
		while (--len > 0)
			cur = (!cur) ? lst : cur->next;
	*jump = ((cur) ? cur : lst);
	return (1);
}
