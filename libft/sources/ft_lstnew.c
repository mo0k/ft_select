/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:45:24 by jmoucade          #+#    #+#             */
/*   Updated: 2017/03/17 18:34:23 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		list->content_size = 0;
		list->content = NULL;
	}
	else
	{
		printf(".........CONTENT_SIZE:%zu\n", content_size);
		if (!(list->content = (void*)malloc(content_size)))
		{
			free(list);
			return (NULL);
		}
		printf(".........CONTENT_SIZE:%zu\n", sizeof(list->content));
		printf(".........CONTENT_SIZE:%zu\n", sizeof(void*));
		list->content = ft_memcpy(list->content, content, content_size);
		//list->content = ft_memmove(list->content, content, content_size);
		printf(".........CONTENT_SIZE:%zu\n", sizeof(list->content));
		list->content_size = content_size;
	}
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
