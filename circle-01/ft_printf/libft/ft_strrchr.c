/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:11:50 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/26 21:32:07 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmps;
	size_t	s_len;

	tmps = (char *)s;
	s_len = ft_strlen(tmps);
	if ((char)c == '\0')
		return (tmps + s_len);
	while (s_len--)
		if (*(tmps + s_len) == (char)c)
			return (tmps + s_len);
	return (NULL);
}
