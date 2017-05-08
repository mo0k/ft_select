/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_termios.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:52 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/08 14:13:13 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_TERMIOS_H
# define MANAGE_TERMIOS_H

# include <ft_select.h>

# define IS_SPECIAL_KEYS(x) (x[0] == 27 && x[1] == 91) ? 1 : 0
# define IS_KEY_ARROW_RIGHT(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 67) ? 1 : 0
# define IS_KEY_ARROW_LEFT(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 68) ? 1 : 0
# define IS_KEY_ARROW_UP(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 65) ? 1 : 0
# define IS_KEY_ARROW_DOWN(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 66) ? 1 : 0
//# define IS_KEY_HOME(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 72) ? 1 : 0
//# define IS_KEY_END(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 70) ? 1 : 0
# define IS_KEY_SUPPR(x) ((IS_SPECIAL_KEYS(x)) && x[2] == 51 && x[3] == 126) ? 1 : 0
# define IS_KEY_DELETE(x) (x[0] == 127 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_RETURN(x) (x[0] == 10 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_SPACE(x) (x[0] == 32 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_CTRL_A(x) (x[0] == 1 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_CTRL_X(x) (x[0] == 24 && x[1] == 0 && x[2] == 0) ? 1 : 0
# define IS_KEY_SPACE(x) (x[0] == 32 && x[1] == 0 && x[2] == 0) ? 1 : 0

int			init_config_term(t_term *new, t_term *origin);
int			restore_config_term(void);

#endif