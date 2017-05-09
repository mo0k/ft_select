/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:23:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/08 22:31:16 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <ft_select.h>

# define MARGIN_BOTTON 1
# define MARGIN_TOP 1
# define MARGIN_RIGHT 0

void				display(t_list *f, int lstlen, t_uint col, t_uint row);

#endif
