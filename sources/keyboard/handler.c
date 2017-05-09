/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:37:07 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/09 02:34:55 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>

static int		mode_search(char *buff, t_list **pos, int *state, t_select *stk)
{
	*state = 1;
	stk->id_mode = ID_SEARCH;
	if (IS_KEY_ESC(buff))
		quit_mode(stk->search, &stk->id_mode, state);
	else if (IS_KEY_RETURN(buff))
		do_select(stk->file, pos, &stk->selected);
	else if (IS_KEY_DELETE(buff))
		del_char(stk->file, pos, stk->search);
	else if (ft_isprint(buff[0]))
	{
		ft_addchar(&stk->search, buff[0]);
		do_search(stk->file, pos, stk->search);
	}
	return (1);
}

static int		mode_move(char *buff, t_list **f, t_list **pos, t_select *stk)
{
	if (IS_KEY_ARROW_UP(buff))
		move_up(*f, pos);
	else if (IS_KEY_ARROW_DOWN(buff))
		move_down(*f, pos);
	else if (IS_KEY_ARROW_RIGHT(buff))
		move_right(*f, pos);
	else if (IS_KEY_ARROW_LEFT(buff))
		move_left(*f, pos);
	else if (IS_KEY_SPACE(buff))
		do_select(*f, pos, &stk->selected);
	else if (IS_KEY_CTRL_A(buff))
		ft_lstiter(*f, &do_selectall);
	else if (IS_KEY_CTRL_X(buff))
		ft_lstiter(*f, &do_deselectall);
	else if (IS_KEY_RETURN(buff))
		do_return(stk);
	else if (IS_KEY_ESC(buff))
		do_esc();
	else if (IS_KEY_DELETE(buff))
		do_delete(f, pos, &stk->selected, &stk->lstlen);
	else if (IS_KEY_SUPP(buff))
		do_delete(f, pos, &stk->selected, &stk->lstlen);
	return (1);
}

void			keyboard_handler(char *buff, t_list **files, t_list **position)
{
	static int	state;

	if (!state && !my_isprint(buff[0]))
		mode_move(buff, files, position, stock_data(NULL));
	else
		mode_search(buff, position, &state, stock_data(NULL));
}
