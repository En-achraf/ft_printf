#include "ft_printf.h"

static int	lenthstr(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i);
}

static int	numlenth(int a)
{
	int	count;

	count = 0;
	if (a <= 0)
		count = 1;
	while (0 != a)
	{
		a /= 10;
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		lenth_result;
	va_list	arg;
	char	ch_fo;
	char	*str_fo;
	int		dec_fo;

	i = 0;
	lenth_result = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// for the char type
			if (format[i] == 'c')
			{
				ch_fo = (char)va_arg(arg, int);
				ft_putchar_fd(ch_fo, 1);
				lenth_result++;
			}
			else if (format[i] == 's')
			{
				// for string type
				str_fo = va_arg(arg, char *);
				ft_putstr_fd(str_fo, 1);
				lenth_result += lenthstr(str_fo);
			}
			else if (format[i] == 'd')
			{
				// for integer type
				dec_fo = va_arg(arg, int);
				ft_putnbr_fd(dec_fo, 1);
				lenth_result += numlenth(dec_fo);
			}
			else if () {
				
			}
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			lenth_result++;
		}
		i++;
	}
	va_end(arg);
	return (lenth_result);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("this is the a char : %d %c %c %s \n", 6, 'b', 'n',
		"hello world");
	printf("this is the a char : %c %c %c %s \n", 'v', 'b', 'n', "hello world");
}