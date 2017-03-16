/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termios.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:52 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/05 09:43:38 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_TERMIOS_H
# define MANAGE_TERMIOS_H

# include <ft_select.h>

int			init_config_term(t_term *new, t_term *origin);
int			restore_config_term(void);

#endif