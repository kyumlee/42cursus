/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:54:28 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 17:31:20 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(tmpd, tmps, len);
	else
	{
		while (len--)
			tmpd[len] = tmps[len];
	}
	return (dst);
}
