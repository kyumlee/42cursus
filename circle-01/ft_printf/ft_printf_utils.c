/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 04:09:02 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/10 00:48:47 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_specifier(char *format)
{
	if ((*format == 'h' && *(format + 1) != 'h') ||
			(*format == 'l' && *(format + 1) != 'l'))
		format++;
	if ((*format == 'h' && *(format + 1) == 'h') ||
			(*format == 'l' && *(format + 1) == 'l'))
		format += 2;
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x' ||
			*format == 'X' || *format == 'p' || *format == 'c' ||
			*format == 's' || *format == '%' || *format == 'n' ||
			*format == 'f')
		return (1);
	return (0);
}

char		*skip_length(char *format)
{
	if ((*format == 'h' && *(format + 1) != 'h') ||
			(*format == 'l' && *(format + 1) != 'l'))
		format++;
	if ((*format == 'h' && *(format + 1) == 'h') ||
			(*format == 'l' && *(format + 1) == 'l'))
		format += 2;
	return (format);
}

int			check_format(char *format)
{
	while (*format)
	{
		if (*format != '%')
			format++;
		if (*format == '%')
		{
			format++;
			while (*format == '0' || *format == '-' || *format == '+' ||
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
			format = skip_length(format);
			if (!check_specifier(format))
				return (0);
			format++;
		}
	}
	return (1);
}

int			cnt_digits(long long num)
{
	long long	tmp;
	int			cnt;

	tmp = num;
	if (num < 0)
	{
		tmp *= -1;
		cnt = 1;
	}
	else
		cnt = 0;
	while (tmp != 0)
	{
		cnt++;
		tmp /= 10;
	}
	if (num == 0)
		cnt = 1;
	return (cnt);
}

char		*convert(long long num, char opt, t_format *fmt)
{
	char	*res;

	if ((opt == 'd' || opt == 'i') && fmt->l == 0 && fmt->ll == 0)
		num = (int)num;
	if ((opt == 'u' || opt == 'x' || opt == 'X') &&
			fmt->l == 0 && fmt->ll == 0)
		num = (unsigned int)num;
	if (fmt->h > 0 && (opt == 'd' || opt == 'i'))
		num = (short)num;
	if (fmt->h > 0 && (opt == 'u' || opt == 'x' || opt == 'X'))
		num = (unsigned short)num;
	if (fmt->hh > 0 && (opt == 'd' || opt == 'i'))
		num = (char)num;
	if (fmt->hh > 0 && (opt == 'u' || opt == 'x' || opt == 'X'))
		num = (unsigned char)num;
	if (opt == 'd' || opt == 'i')
		dtoa(&res, num);
	if (opt == 'u')
		utoa(&res, num);
	if (opt == 'x' || opt == 'X')
		xtoa(&res, num, opt);
	return (res);
}
