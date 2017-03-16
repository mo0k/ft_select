/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 00:52:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/11 23:21:59 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		fatal(char *error)
{
		ft_putendl_fd(error, STDERR_FILENO);
		exit(EXIT_FAILURE);
}