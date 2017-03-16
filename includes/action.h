/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:48 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/12 22:38:33 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <ft_select.h>

int		do_select(t_list *files, t_list **pos);
int		do_esc(void);
void	del(void *files, size_t size);
int		do_delete(t_list **files, t_list **pos);
void	do_deselectall(t_list *elem);
void	do_selectall(t_list *elem);

#endif