/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:29:31 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/09 14:55:40 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print(va_list ap, char *format, t_format *fmt, int *count)
{
	char	*temp;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			(*count)++;
			format++;
		}
		if (*format == '%')
		{
			format++;
			temp = format;
			reset_s(fmt);
			init_s(fmt, temp, ap);
			format = print_cases(ap, format, fmt, count);
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	fmt;
	char		*temp;
	int			count;

	temp = (char *)format;
	if (!check_format(temp))
		return (-1);
	va_start(ap, format);
	count = 0;
	print(ap, (char *)format, &fmt, &count);
	return (count);
}
