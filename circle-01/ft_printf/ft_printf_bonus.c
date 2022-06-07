/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:07:15 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/09 14:55:47 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_plus(char *res, char opt, t_format *fmt, int *count)
{
	if (fmt->plus == 0 || (opt != 'd' && opt != 'i' && opt != 'f') ||
			fmt->sharp > 0 || res[0] == '-')
		return ;
	write(1, "+", 1);
	(*count)++;
}

void	print_space(char *res, char opt, t_format *fmt, int *count)
{
	if (fmt->space == 0 || (opt != 'd' && opt != 'i' && opt != 'f') ||
			fmt->sharp > 0 || res[0] == '-')
		return ;
	write(1, " ", 1);
	(*count)++;
}

void	print_base(char *res, char opt, t_format *fmt, int *count)
{
	if (fmt->sharp == 0 || (opt != 'x' && opt != 'X' && opt != 'f') ||
			(res[0] == '0' && ft_strlen(res) == 1))
		return ;
	if (opt == 'x')
		write(1, "0x", 2);
	if (opt == 'X')
		write(1, "0X", 2);
	*count += 2;
}

void	case_n(va_list ap, int *count)
{
	int		*num;

	num = va_arg(ap, int *);
	*num = *count;
}
