/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:11:08 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 01:01:43 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <action.h>

void		result(t_list *elem)
{
	static int i;

	if (((t_file*)(elem->content))->selected == 1)
	{
		if (i)
			write(1, " ", 1);
		ft_putstr(((t_file*)(elem->content))->name);
		i = 1;
	}
}

void		do_return(t_select *stock)
{
	restore_config_term();
	ft_lstiter(stock->file, &result);
	if (stock->selected)
		write(1, "\n", 1);
	exit(EXIT_SUCCESS);
}
