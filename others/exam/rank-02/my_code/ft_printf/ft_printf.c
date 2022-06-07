#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		width;
int		precision;
int		count;

int		ft_strlen(char *s)
{
	int		i = 0;

	while (s[i])
		i++;
	return (i);
}

int		check_format(char *format)
{
	while (*format)
	{
		if (*format != '%')
			format++;
		else
		{
			format++;
			while (*format >= '0' && *format <= '9')
				format++;
			if (*format == '.')
			{
				format++;
				while (*format >= '0' && *format <= '9')
					format++;
			}
			if (!(*format == 's' || *format == 'd' || *format == 'x'))
				return (0);
			format++;
		}
	}
	return (1);
}

char	*initialize_width_n_prec(char *format)
{
	width = 0;
	precision = -1;
	while (*format >= '0' && *format <= '9')
	{
		width = width * 10 + (*format - 48);
		format++;
	}
	if (*format == '.')
	{
		precision = 0;
		format++;
		while (*format >= '0' && *format <= '9')
		{
			precision = precision * 10 + (*format - 48);
			format++;
		}
	}
	return (format);
}

char	*reverse(char *buffer, int i)
{
	int		j = 0;
	char	*res;

	if(!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (buffer[j])
	{
		res[j] = buffer[i - j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*convert(char opt, va_list *ap)
{
	long long	num;
	char		buffer[50];
	char		*res;
	int			i = 0;
	int			neg = 0;

	if (opt == 'd')
		num = va_arg(*ap, int);
	else
		num = va_arg(*ap, unsigned int);
	if (num == 0)
		buffer[i++] = '0';
	else if (num < 0)
	{
		neg = 1;
		num *= -1;
	}
	while (num != 0)
	{
		if (opt == 'd')
		{
			buffer[i++] = "0123456789"[num % 10];
			num /= 10;
		}
		else
		{
			buffer[i++] = "0123456789abcdef"[num % 16];
			num /= 16;
		}
	}
	if (neg)
		buffer[i++] = '-';
	buffer[i] = '\0';
	res = reverse(buffer, i - 1);
	return (res);
}

void	count_paddings(char *res, char opt, int *space, int *zero)
{
	int		len = ft_strlen(res);

	*space = width - len;
	if (len == 0)
		*space = width;
	if (opt == 's' && precision <= len && width > precision && precision > -1)
		*space = width - precision;
	if (opt == 'd' || opt == 'x')
	{
		if (precision > len)
			*zero = precision - len;
		if (res[0] == '0' && precision == 0)
			*space = width;
		if (width > precision && precision > len)
			*space = width - precision;
		if (res[0] == '-' && precision >= len)
		{
			*zero += 1;
			*space -= 1;
		}
		if (width <= precision)
			*space = 0;
	}
	if (*space < 0)
		*space = 0;
	if (*zero < 0)
		*zero = 0;
}

void	print(char *res, char opt, int *space, int *zero)
{
	count += *space + *zero;
	while ((*space)--)
		write(1, " ", 1);
	if (precision > -1 && opt == 'd' && res[0] == '-')
		count += write(1, "-", 1);
	while ((*zero)--)
		write(1, "0", 1);
	if (res[0] == '0' && opt != 's' && precision == 0)
		write(1, "", 0);
	else if (res[0] == '-' && opt == 'd' && precision > -1)
		count += write(1, &res[1], ft_strlen(res) - 1);
	else if (opt == 's' && precision > -1 && precision < ft_strlen(res))
		count += write(1, res, precision);
	else
		count += write(1, res, ft_strlen(res));
}

char	*process(char *format, va_list *ap)
{
	int		space = 0;
	int		zero = 0;
	char	*res = NULL;

	format = initialize_width_n_prec(format);
	if (*format == 's')
	{
		res = va_arg(*ap, char *);
		if (res == NULL)
			res = "(null)";
	}
	else
		res = convert(*format, ap);
	count_paddings(res, *format, &space, &zero);
	print(res, *format, &space, &zero);
	if (*format != 's')
		free(res);
	return (format);
}

int		ft_printf(const char *format, ...)
{
	char	*temp = (char *)format;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	if (!check_format(temp))
		return (-1);
	while (*(char *)format)
	{
		if (*format != '%')
			count += write(1, format, 1);
		else
		{
			format++;
			format = process((char *)format, &ap);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
