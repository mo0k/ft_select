/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:59:28 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:04:43 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <move.h>

static int	get_nbrjump_left(t_display display, int pos, int lstlen)
{
	int		i;

	i = 1;
	if (pos <= (int)(display.row - MARGIN_TOP))
	{
		while ((int)(display.row - MARGIN_TOP) *
				((int)display.col - i) + pos > lstlen)
			i++;
		return ((int)(display.row - MARGIN_TOP) * ((int)display.col - i));
	}
	else
	{
		return (-1 * (display.row - MARGIN_TOP));
	}
}

static int	get_nbrjump_right(t_display display, int pos, int lstlen)
{
	int		i;

	i = 1;
	if ((pos > (int)(display.row - MARGIN_TOP) * ((int)display.col - 1) &&
			pos <= (int)(display.row - MARGIN_TOP) * (int)display.col) ||
			(int)(display.row - MARGIN_TOP) + pos > lstlen)
	{
		while (pos - (int)(display.row - MARGIN_TOP) *
				((int)display.col - i) <= 0)
			i++;
		return (-1 * (int)(display.row - MARGIN_TOP) * ((int)display.col - i));
	}
	else
	{
		return ((display.row - MARGIN_TOP));
	}
}

int			get_njump(t_display display, int pos, int lstlen, int direction)
{
	if (direction == RIGHT)
		return (get_nbrjump_right(display, pos, lstlen));
	else if (direction == LEFT)
		return (get_nbrjump_left(display, pos, lstlen));
	else
		return (0);
}
