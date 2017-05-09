/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:43:53 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:07:25 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <input.h>

int			input(int ac, char **av, t_list **file)
{
	t_file	new;
	int		i;

	i = 1;
	if (ac == 1)
		return (usage());
	while (i < ac)
	{
		new.name = av[i];
		new.selected = 0;
		new.current = (i++ == 1) ? 1 : 0;
		ft_lstadd_end(file, ft_lstnew(&new, sizeof(t_file)));
	}
	return (1);
}
