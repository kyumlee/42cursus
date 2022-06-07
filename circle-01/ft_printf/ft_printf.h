/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:28:24 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/10 00:31:16 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct
{
	int		left;
	int		zero;
	int		wdth;
	int		prec;
	int		plus;
	int		space;
	int		sharp;
	int		h;
	int		hh;
	int		l;
	int		ll;
}			t_format;
int			ft_printf(const char *format, ...);
char		*reverse(char *buf, int i, int cnt);
void		dtoa(char **res, long long num);
void		utoa(char **res, unsigned long long num);
void		xtoa(char **res, unsigned long long num, char opt);
void		ptoa(char **res, unsigned long long num);
void		print_padding(char *res, char opt, t_format *fmt, int *count);
void		print_padding_c(t_format *fmt, int *count);
void		print_precision(char *res, char opt, t_format *fmt, int *count);
char		*print_cases(va_list ap, char *format, t_format *fmt, int *count);
void		case_int(va_list ap, char opt, t_format *fmt, int *count);
void		case_p(va_list ap, char opt, t_format *fmt, int *count);
void		case_char(va_list ap, char opt, t_format *fmt, int *count);
t_format	*reset_s(t_format *fmt);
void		init_s(t_format *fmt, char *format, va_list ap);
int			check_format(char *format);
int			cnt_digits(long long num);
char		*convert(long long num, char opt, t_format *fmt);
void		print_plus(char *res, char opt, t_format *fmt, int *count);
void		print_space(char *res, char opt, t_format *fmt, int *count);
void		print_base(char *res, char opt, t_format *fmt, int *count);
void		case_n(va_list ap, int *count);

#endif
