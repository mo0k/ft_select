/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:01:02 by mo0ky             #+#    #+#             */
/*   Updated: 2017/02/21 18:09:20 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_SIGNALS_H
# define MANAGE_SIGNALS_H

# include <ft_select.h>

void		catch_signals(void);
void		handler_signals(int sig);

#endif