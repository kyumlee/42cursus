/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:24:43 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 00:07:50 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (p == NULL)
		return (p);
	ft_strlcpy(p, (char *)s, ft_strlen(s) + 1);
	return (p);
}
