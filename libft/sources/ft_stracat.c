/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stracat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:53:17 by jmoucade          #+#    #+#             */
/*   Updated: 2017/05/08 18:35:40 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_stracat(char **dst, char *src)
{
	char	*tmp;

	if (!dst || !src || !*dst)
		return (0);
	if (!(tmp = ft_strjoin(*dst, src)))
		return (0);
	free(*dst);
	if (!(*dst = ft_strdup(tmp)))
		return (0);
	free(tmp);
	return (1);
}
