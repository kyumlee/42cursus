/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:21:17 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/10 00:48:18 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*reset_s(t_format *fmt)
{
	fmt->left = 0;
	fmt->zero = 0;
	fmt->wdth = 0;
	fmt->prec = -1;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->sharp = 0;
	fmt->h = 0;
	fmt->hh = 0;
	fmt->l = 0;
	fmt->ll = 0;
	return (fmt);
}

int			init_width(char *format, va_list ap, t_format *fmt)
{
	int		width;

	width = 0;
	while (*format >= '0' && *format <= '9')
	{
		width = (width * 10) + (*format - '0');
		format++;
	}
	if (*format == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			width *= -1;
			fmt->left++;
		}
		format++;
	}
	return (width);
}

int			init_precision(char *format, va_list ap)
{
	int		precision;

	precision = 0;
	while ((*format >= '0' && *format <= '9') || *format == '*')
		format++;
	if (*format != '.')
		return (-1);
	if (*format == '.')
		format++;
	if (*format != '*' && !(*format >= '0' && *format <= '9'))
		return (precision);
	while (*format >= '0' && *format <= '9')
	{
		precision = (precision * 10) + (*format - '0');
		format++;
	}
	if (*format == '*')
	{
		precision = va_arg(ap, int);
		if (precision < 0)
			precision = -1;
		format++;
	}
	return (precision);
}

void		init_length(t_format *fmt, char *format)
{
	while ((*format >= '0' && *format <= '9') || *format == '*')
		format++;
	if (*format == '.')
	{
		format++;
		while ((*format >= '0' && *format <= '9') || *format == '*')
			format++;
	}
	if (*format == 'h')
	{
		format++;
		if (*format != 'h')
			fmt->h++;
		else if (*format == 'h')
			fmt->hh++;
	}
	if (*format == 'l')
	{
		format++;
		if (*format != 'l')
			fmt->l++;
		else if (*format == 'l')
			fmt->ll++;
	}
}

void		init_s(t_format *fmt, char *format, va_list ap)
{
	while (*format == '-' || *format == '0' ||
			*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '0')
			fmt->zero++;
		if (*format == '-')
			fmt->left++;
		if (*format == '+')
			fmt->plus++;
		if (*format == ' ')
			fmt->space++;
		if (*format == '#')
			fmt->sharp++;
		format++;
	}
	fmt->wdth = init_width(format, ap, fmt);
	fmt->prec = init_precision(format, ap);
	init_length(fmt, format);
	if (fmt->zero > 0 && fmt->left > 0)
		fmt->zero = 0;
}
