/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 00:21:35 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 01:18:20 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <search.h>

void	quit_mode(char *search, int *id_mode, int *state)
{
	ft_bzero(search, ft_strlen(search));
	*id_mode = ID_MOVE;
	*state = 0;
}
