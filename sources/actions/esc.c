/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:01:18 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <action.h>

int		do_esc(void)
{
	restore_config_term();
	exit(EXIT_FAILURE);
}