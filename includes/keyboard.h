/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:28:33 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:36:19 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include <ft_select.h>

# define IS_SPEC_KEYS(x) (x[0] == 27 && x[1] == 91) ? 1 : 0
# define IS_KEY_ARROW_RIGHT(x) ((IS_SPEC_KEYS(x)) && x[2] == 67) ? 1 : 0
# define IS_KEY_ARROW_LEFT(x) ((IS_SPEC_KEYS(x)) && x[2] == 68) ? 1 : 0
# define IS_KEY_ARROW_UP(x) ((IS_SPEC_KEYS(x)) && x[2] == 65) ? 1 : 0
# define IS_KEY_ARROW_DOWN(x) ((IS_SPEC_KEYS(x)) && x[2] == 66) ? 1 : 0
# define IS_KEY_SUPP(x) ((IS_SPEC_KEYS(x)) && x[2] == 51 && x[3] == 126) ? 1 : 0
# define IS_KEY_DELETE(x) (x[0] == 127 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_RETURN(x) (x[0] == 10 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_SPACE(x) (x[0] == 32 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_ESC(x) (x[0] == 27 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_CTRL_A(x) (x[0] == 1 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_CTRL_X(x) (x[0] == 24 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_SPACE(x) (x[0] == 32 && x[1] == 0 && x[2] == 0) ? 1 : 0

void	keyboard_handler(char *buff, t_list **files, t_list **position);

#endif
