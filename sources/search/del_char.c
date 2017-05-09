/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 00:22:06 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:27:59 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <search.h>

void	del_char(t_list *files, t_list **pos, char *search)
{
	tputs(tgetstr("le", NULL), AFFCNT, &my_putchar);
	if (ft_strlen(search) > 0)
		search[ft_strlen(search) - 1] = 0;
	do_search(files, pos, search);
}
