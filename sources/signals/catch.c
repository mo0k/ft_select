/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:00:48 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 03:44:56 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void		catch_signals(void)
{
	int		sig;

	sig = 0;
	while (++sig < 32)
		signal(sig, &handler_signals);
}
