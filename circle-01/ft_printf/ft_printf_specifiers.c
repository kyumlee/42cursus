/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 23:52:38 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/10 00:28:15 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_s(char *res, t_format *fmt, int *count)
{
	int		i;

	i = 0;
	if (res == NULL)
	{
		write(1, res, 6);
		*count += 6;
		return ;
	}
	if (fmt->prec > -1 && fmt->prec < (int)ft_strlen(res))
	{
		while (i < fmt->prec && res[i])
		{
			write(1, &res[i], 1);
			i++;
			(*count)++;
		}
	}
	else
	{
		write(1, res, ft_strlen(res));
		*count += ft_strlen(res);
	}
}

void		apply_flags_int(char *res, char opt, t_format *fmt, int *count)
{
	if (fmt->space > 0 && fmt->plus == 0)
		print_space(res, opt, fmt, count);
	if (fmt->plus > 0 && fmt->left > 0 && fmt->zero == 0)
		print_plus(res, opt, fmt, count);
	if (fmt->left == 0)
		print_padding(res, opt, fmt, count);
	if (fmt->plus > 0 && fmt->left == 0 && fmt->zero == 0)
		print_plus(res, opt, fmt, count);
	if (res[0] == '0' && ft_strlen(res) == 1 && fmt->prec == 0)
		(*count)--;
	else
	{
		if (res[0] == '-' && fmt->prec == -1 && fmt->zero == 0)
			write(1, "-", 1);
		if (fmt->sharp > 0 && fmt->zero == 0)
			print_base(res, opt, fmt, count);
		if (fmt->prec > -1)
			print_precision(res, opt, fmt, count);
		if (res[0] == '-')
			write(1, &res[1], ft_strlen(res) - 1);
		if (res[0] != '-')
			write(1, res, ft_strlen(res));
	}
	if (fmt->left > 0)
		print_padding(res, opt, fmt, count);
}

void		case_int(va_list ap, char opt, t_format *fmt, int *count)
{
	long long	num;
	char		*res;

	if (fmt->l == 0 && fmt->ll == 0)
		num = va_arg(ap, int);
	if (fmt->l > 0)
		num = va_arg(ap, long);
	if (fmt->ll > 0)
		num = va_arg(ap, long long);
	res = convert(num, opt, fmt);
	apply_flags_int(res, opt, fmt, count);
	*count += ft_strlen(res);
	free(res);
}

void		case_p(va_list ap, char opt, t_format *fmt, int *count)
{
	unsigned long long	num;
	char				*res;

	num = va_arg(ap, unsigned long long);
	ptoa(&res, num);
	if (fmt->left == 0)
		print_padding(res, opt, fmt, count);
	if (fmt->left > 0)
		write(1, "0x", 2);
	*count += 2;
	if (fmt->prec > -1)
		print_precision(res, opt, fmt, count);
	if (num == 0 && fmt->prec == 0)
		write(1, "", 0);
	else
	{
		write(1, res, ft_strlen(res));
		*count += ft_strlen(res);
	}
	if (fmt->left > 0)
		print_padding(res, opt, fmt, count);
	free(res);
}

void		case_char(va_list ap, char opt, t_format *fmt, int *count)
{
	char	ch;
	char	*res;

	if (opt == 'c')
	{
		ch = va_arg(ap, int);
		if (fmt->left == 0)
			print_padding_c(fmt, count);
		write(1, &ch, 1);
		if (fmt->left > 0)
			print_padding_c(fmt, count);
		(*count)++;
	}
	if (opt == 's')
	{
		res = va_arg(ap, char *);
		if (res == NULL)
			res = ft_strdup("(null)");
		if (fmt->left == 0)
			print_padding(res, opt, fmt, count);
		print_s(res, fmt, count);
		if (fmt->left > 0)
			print_padding(res, opt, fmt, count);
	}
}
