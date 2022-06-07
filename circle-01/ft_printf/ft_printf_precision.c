/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:47:34 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/03 19:58:45 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision(char *res, char opt, t_format *fmt, int *count)
{
	int		i;
	int		len;
	int		cnt;

	i = 0;
	len = ft_strlen(res);
	cnt = 0;
	if (fmt->prec > len)
		cnt = fmt->prec - len;
	if ((opt == 'd' || opt == 'i') && res[0] == '-')
	{
		if (fmt->prec >= len)
			cnt++;
		write(1, "-", 1);
	}
	while (i++ < cnt)
		write(1, "0", 1);
	*count += cnt;
}
