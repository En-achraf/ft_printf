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

static int	numlenth_hex(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				lenth_result;
	va_list			arg;
	char			ch_fo;
	char			*str_fo;
	int				dec_fo;
	unsigned long	ptr_val;

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
			else if (format[i] == 'p')
			{
				//this for the &
				// Get the pointer and cast it to unsigned long
				ptr_val = (unsigned long)va_arg(arg, void *);
				ft_putstr_fd("0x", 1);
				if (ptr_val == 0)
					ft_putchar_fd('0', 1);
				else
					ft_puthex_fd(ptr_val, 1);
				lenth_result += 2 + numlenth_hex(ptr_val);
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
	char *p;
	p = "hello world";

	ft_printf("this is the a char : %d %c %c %s %p \n", 6, 'b', 'n',"hello world", &p);
	printf("this is the a char : %d %c %c %s %p \n", 6, 'b', 'n',"hello world", &p);
}