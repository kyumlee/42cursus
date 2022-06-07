/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:00:46 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 17:59:30 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmps;

	tmps = (char *)s;
	while (1)
	{
		if (*tmps == (char)c)
			return (tmps);
		tmps++;
		if (*tmps == '\0')
			break ;
	}
	if ((char)c == '\0')
		return (tmps);
	else
		return (NULL);
}
