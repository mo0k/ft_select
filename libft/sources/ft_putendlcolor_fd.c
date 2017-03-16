/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlcolor_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:41:32 by mo0ky             #+#    #+#             */
/*   Updated: 2017/03/16 00:06:37 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendlcolor_fd(char const *s, int fd, char *color)
{
	int		i;

	i = 0;
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(color, fd);
	write(fd, s, ft_strlen(s));
	ft_putstr_fd(C_DFL, fd);
	ft_putchar_fd('\n', fd);
}