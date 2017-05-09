/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:30:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/09 01:21:03 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <terms.h>

int			init_config_term(t_term *new, t_term *origin)
{
	char	*name;
	int		ret;

	(!getenv("TERM")) ? fatal(ERR_GETENV) : (name = getenv("TERM"));
	if ((ret = tgetent(NULL, name)) == -1)
		fatal(ERR_TGETENT_NOFOUND);
	else if (ret == 0)
		fatal(ERR_TGETENT_NOENTRY);
	if (tcgetattr(0, new) == -1)
		fatal(ERR_TCGETATTR);
	if (!(origin = (t_term*)ft_memmove((t_term*)origin,
		(t_term*)new, sizeof(t_term))))
		exit(EXIT_FAILURE);
	new->c_lflag &= ~(ICANON | ECHO);
	new->c_cc[VMIN] = 1;
	new->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, new) == -1)
		exit(EXIT_FAILURE);
	tputs(tgetstr("ti", NULL), AFFCNT, &my_putchar);
	tputs(tgetstr("vi", NULL), AFFCNT, &my_putchar);
	return (1);
}

int			restore_config_term(void)
{
	if (tcsetattr(0, TCSADRAIN, stock_data(NULL)->origin_term) == -1)
		exit(EXIT_FAILURE);
	tputs(tgetstr("te", NULL), AFFCNT, &my_putchar);
	tputs(tgetstr("ve", NULL), AFFCNT, &my_putchar);
	return (1);
}
