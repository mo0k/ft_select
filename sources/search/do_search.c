/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:07:58 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 01:19:34 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <search.h>

void		do_search(t_list *files, t_list **pos, char *search)
{
	int		i;
	t_list	*cur;

	i = 0;
	while (files)
	{
		if (!ft_strncmp(((t_file*)(files->content))->name,
			search, ft_strlen(search)))
		{
			if (!i)
				cur = files;
			++i;
		}
		files = files->next;
	}
	if (i && *pos != cur)
	{
		((t_file*)(cur->content))->current = 1;
		((t_file*)((*pos)->content))->current = 0;
		*pos = cur;
	}
}
