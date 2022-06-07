/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:23:29 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/09 15:01:20 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_percent(t_format *fmt, int *count)
{
	int		padding;

	padding = fmt->wdth - 1;
	if (padding < 0)
		padding = 0;
	*count += padding;
	if (fmt->left == 0)
	{
		if (fmt->zero == 0)
			while (padding--)
				write(1, " ", 1);
		if (fmt->zero > 0)
			while (padding--)
				write(1, "0", 1);
	}
	write(1, "%", 1);
	(*count)++;
	if (fmt->left > 0)
		while (padding--)
			write(1, " ", 1);
}

char		*skip_flags_width_precision_length(char *format)
{
	while (*format == '-' || *format == '0' || *format == '+' ||
			*format == ' ' || *format == '#')
		format++;
	while ((*format >= '0' && *format <= '9') || *format == '*')
		format++;
	if (*format == '.')
	{
		format++;
		while ((*format >= '0' && *format <= '9') || *format == '*')
			format++;
	}
	if ((*format == 'h' && *(format + 1) != 'h') ||
			(*format == 'l' && *(format + 1) != 'l'))
		format++;
	if ((*format == 'h' && *(format + 1) == 'h') ||
		(*format == 'l' && *(format + 1) == 'l'))
		format += 2;
	return (format);
}

char		*print_cases(va_list ap, char *format, t_format *fmt, int *count)
{
	format = skip_flags_width_precision_length(format);
	if (*format == 'd' || *format == 'i' || *format == 'u' ||
			*format == 'x' || *format == 'X')
		case_int(ap, *format, fmt, count);
	if (*format == 'p')
		case_p(ap, *format, fmt, count);
	if (*format == 'c' || *format == 's')
		case_char(ap, *format, fmt, count);
	if (*format == 'n')
		case_n(ap, count);
	if (*format == '%')
		print_percent(fmt, count);
	format++;
	return (format);
}
