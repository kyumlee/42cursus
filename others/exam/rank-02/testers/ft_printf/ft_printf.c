#include <unistd.h>
#include <string.h>
#include <stdarg.h>

int	count;
int	width;
int	prec;

int	ft_strlen(char *s)
{
	int	i = 0;
	
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	check_format(char *s)
{
	while (*s)
	{
		if (*s != '%')
			s++;
		else if (*s == '%')
		{
			s++;
			while (*s >= '0' && *s <= '9')
				s++;
			if (*s == '.')
			{
				s++;
				while (*s >= '0' && *s <= '9')
					s++;
			}
			if (!(*s == 'd' || *s == 's' || *s == 'x'))
				return (0);
			s++;
		}
	}
	return (1);
}

char	*init_wp(char *s)
{
	width = 0;
	prec = -1;
	while (*s >= '0' && *s <= '9')
	{
		width = width * (*s) - 48;
		s++;
	}
	if (*s == '.')
	{
		prec = 0;
		while (*s >= '0' && *s <= '9')
		{
			prec = prec * (*s) - 48;
			s+;
		}
	}
	return (s);
}

char	*reverse(char *s, int i)
{
	char	*ret = malloc(sizeof(char) * i);
	int		j = -1;

	if (!ret)
		return (0);
	while (++j < i)
		ret[j] = s[i - 1 - j];
	ret[j] = '\0';
	return (ret);
}

char	*convert(char opt, va_list *ap)
{
	char	*ret;
	char	buf[50];
	int		neg = 0;
	long	num = 0;
	int		i = 0;

	if (opt == 'd')
		num = va_arg(*ap, int);
	else
		num = va_arg(*ap, unsigned int);
	if (num == 0)
		buf[i++] = '0';
	else if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	while (num != 0)
	{
		if (opt == 'd')
		{
			buf[i++] = "0123456789"[num % 10];
			num /= 10;
		}
		if (opt == 'x')
		{
			buf[i++] = "0123456789abcdef"[num % 16];
			num /= 16;
		}
	}
	if (neg)
		buf[i++] = '-';
	buf[i] = '\0';
	ret = reverse(buf, i);
	return (ret);
}

void	count_paddings(char *s, char opt, int *space, int *zero)
{
	int	len = ft_strlen(s);

	*space = width - len;
	if (len == 0)
		*space = width;
	if (opt == 's' && prec <= len && width > prec && prec > -1)
		*space = width - prec;
	if (opt == 'd' || opt == 'x')
	{
		if (prec > len)
			*zero = prec - len;
		if (s[0] == '0' && prec == 0)
			*space = width;
		if (width > prec && prec > len)
			*space = width - prec;
		if (s[0] == '-' && prec >= len)
		{
			*zero += 1;
			*space -= 1;
		}
		if (width <= prec)
			*space = 0;
	}
	if (*space < 0)
		*space = 0;
	if (*zero < 0)
		*zero = 0;
}

void	print(char *s, char opt, int space, int zero)
{
	int	len = ft_strlen(s);

	while (space--)
		count += write(1, " ", 1);
	if (s[0] == '-' && opt == 'd' && prec > -1)
		count += write(1, "-", 1);
	while (zero--)
		count += write(1, "0", 1);
	if (s[0] == '0' && opt != 's' && prec == 0)
		count += write(1, "", 0);
	else if (s[0] == '-' && opt == 'd' && prec > -1)
		count += write(1, &s[1], len - 1);
	else if (opt == 's' && prec > -1 && prec < len)
		count += write(1, s, prec);
	else
		count += write(1, s, len);
}

char	*process(char *s, va_list *ap)
{
	int		space = 0;
	int		zero = 0;
	char	*ret = 0;

	s = init_wp(s);
	if (*s == 's')
	{
		ret = va_arg(*ap, char *);
		if (!ret)
			ret = "(null)";
	}
	else
		ret = convert(*s, ap);
	count_paddings(ret, *s, &space, &zero);
	print(ret, *s, space, zero);
	if (*s != 's')
		free(ret);
	return (s);
}

int	ft_printf(const char *format, ...)
{
	char	*temp = (char *)format;
	va_list ap;
	
	count = 0;
	va_start(ap, format);
	if (!check_format(temp))
		return (-1);
	while (*format)
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
