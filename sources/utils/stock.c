/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:52:54 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:49:51 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_select			*stock_data(t_select *elem)
{
	static t_select	*tmp;

	if (elem)
		tmp = elem;
	else
		return (tmp);
	return (elem);
}
