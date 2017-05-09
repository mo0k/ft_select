/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:16:48 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 02:32:17 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <ft_select.h>

int		do_select(t_list *files, t_list **pos, int *selected);
int		do_esc(void);
int		do_delete(t_list **files, t_list **pos, int *selected, int *lstlen);
void	do_deselectall(t_list *elem);
void	do_selectall(t_list *elem);
void	del(void *files, size_t size);
void	search(t_list *files, t_list **pos, char *search);
void	do_return(t_select *stock);
void	result(t_list *elem);

#endif
