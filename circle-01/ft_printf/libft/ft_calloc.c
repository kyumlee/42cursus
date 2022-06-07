/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:12:20 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 18:03:31 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	void			*p;
	unsigned char	*tmp;

	total = count * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	tmp = (unsigned char *)p;
	while (total--)
		*tmp++ = 0;
	return (p);
}
