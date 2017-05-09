/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 00:22:27 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:40:58 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_H
# define SEARCH_H

# include <ft_select.h>

void	do_search(t_list *files, t_list **pos, char *search);
void	quit_mode(char *search, int *id_mode, int *state);
void	del_char(t_list *files, t_list **pos, char *search);

#endif
