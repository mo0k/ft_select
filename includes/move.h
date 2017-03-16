/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:13:04 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/14 15:00:43 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include <ft_select.h>

# define RIGHT 1
# define LEFT 2

int			move_up(t_list *files, t_list **pos);
int			move_down(t_list *files, t_list **pos);
int			move_left(t_list *files, t_list **pos);
int			move_right(t_list *files, t_list **pos);
int			get_njump(t_display display, int pos, int lstlen, int direction);

#endif