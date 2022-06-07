/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:19:09 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/08 17:02:18 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cnt_padding1(char *res, char opt, t_format *fmt)
{
	int		len;
	int		cnt;

	len = ft_strlen(res);
	cnt = fmt->wdth - len;
	if (opt == 'p')
	{
		if (len == 1 && res[0] == '0' && fmt->prec > -1)
			cnt = fmt->wdth - fmt->prec;
		cnt -= 2;
	}
	if (opt == 's')
	{
		if (fmt->prec <= len && fmt->wdth > fmt->prec && fmt->prec > -1)
			cnt = fmt->wdth - fmt->prec;
		if (len == 0)
			cnt = fmt->wdth;
	}
	if (cnt < 0 || fmt->zero > 0)
		cnt = 0;
	return (cnt);
}

int			cnt_padding2(char *res, char opt, t_format *fmt)
{
	int		len;
	int		cnt;

	len = ft_strlen(res);
	cnt = fmt->wdth - len;
	if (len == 1 && res[0] == '0' && fmt->prec == 0)
		cnt = fmt->wdth;
	if (fmt->wdth > fmt->prec && fmt->prec > len)
		cnt = fmt->wdth - fmt->prec;
	if ((fmt->prec >= len && (opt == 'd' || opt == 'i') && res[0] == '-') ||
			((fmt->space > 0 || fmt->plus > 0) && res[0] != '-'))
		cnt--;
	if ((opt == 'x' || opt == 'X') && fmt->sharp > 0)
	{
		cnt = fmt->wdth - len - 2;
		if (fmt->prec > len)
			cnt = fmt->wdth - fmt->prec - 2;
		if (res[0] == '0' && len == 1 && fmt->prec > -1)
			cnt = fmt->wdth - fmt->prec;
		if (res[0] == '0' && len == 1 && fmt->prec == -1)
			cnt = fmt->wdth - 1;
	}
	if (cnt < 0 || (fmt->zero > 0 && fmt->prec == -1) || fmt->wdth <= fmt->prec)
		cnt = 0;
	return (cnt);
}

int			cnt_zero_padding(char *res, char opt, t_format *fmt)
{
	int		len;
	int		cnt;

	cnt = 0;
	if (fmt->zero == 0)
		return (cnt);
	len = ft_strlen(res);
	if (opt == 'p')
		len += 2;
	cnt = fmt->wdth - len;
	if ((opt == 'x' || opt == 'X') && fmt->sharp > 0)
	{
		cnt = fmt->wdth - len - 2;
		if (fmt->prec > len)
			cnt = fmt->wdth - fmt->prec - 2;
		if (res[0] == '0' && len == 1 && fmt->prec > -1)
			cnt = fmt->wdth - fmt->prec;
		if (res[0] == '0' && len == 1 && fmt->prec == -1)
			cnt = fmt->wdth - 1;
	}
	if ((fmt->space > 0 || fmt->plus > 0) && res[0] != '-')
		cnt--;
	if (cnt < 0 || (fmt->zero > 0 && fmt->prec > -1) || fmt->wdth <= fmt->prec)
		cnt = 0;
	return (cnt);
}

void		print_padding(char *res, char opt, t_format *fmt, int *count)
{
	int		padding;
	int		zero_padding;

	if (opt == 's' || opt == 'p')
		padding = cnt_padding1(res, opt, fmt);
	if (opt != 's' && opt != 'p')
		padding = cnt_padding2(res, opt, fmt);
	zero_padding = cnt_zero_padding(res, opt, fmt);
	*count += padding + zero_padding;
	while (padding--)
		write(1, " ", 1);
	if (fmt->plus > 0 && fmt->zero > 0)
		print_plus(res, opt, fmt, count);
	if (opt == 'p' && fmt->left == 0)
		write(1, "0x", 2);
	if (fmt->sharp > 0 && fmt->zero > 0)
		print_base(res, opt, fmt, count);
	if (fmt->zero > 0 && fmt->left == 0)
	{
		if ((opt == 'd' || opt == 'i') && res[0] == '-' && fmt->prec == -1)
			write(1, "-", 1);
		while (zero_padding--)
			write(1, "0", 1);
	}
}

void		print_padding_c(t_format *fmt, int *count)
{
	int		padding;

	padding = fmt->wdth - 1;
	if (padding < 0)
		padding = 0;
	*count += padding;
	while (padding--)
		write(1, " ", 1);
}
