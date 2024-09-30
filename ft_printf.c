#include "ft_printf.h"

static int lenthstr(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i);
}

static int numlenth(int a)
{
	int count;

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

static int numlenth_hex(unsigned long num)
{
	int len;

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

static int unslenth_num(unsigned int nb)
{
	int count;

	count = 0;
	if (nb == 0)
		count = 1;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void lowhex_value(int x)
{
	char *hex = "0123456789abcdef";
	if (x >= 16)
		lowhex_value(x / 16);
	ft_putchar_fd(hex[x % 16], 1);
}

static void uphex_value(int x)
{
	char *hex = "0123456789ABCDEF";
	if (x >= 16)
		uphex_value(x / 16);
	ft_putchar_fd(hex[x % 16], 1);
}

static void set_fornat (const char *format, int i, int lenth_result, va_list arg) {
	char ch_fo;
	char *str_fo;
	int dec_fo;
	unsigned long ptr_val;
	unsigned int unsdec_fo;
	unsigned int lowhex_fo;
	unsigned int uphex_fo;
	
	if (format[i] == 'c')
			{
				//for the char type
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
			else if (format[i] == 'd' || format[i] == 'i')
			{
				// for integer type
				dec_fo = va_arg(arg, int);
				ft_putnbr_fd(dec_fo, 1);
				lenth_result += numlenth(dec_fo);
			}
			else if (format[i] == 'p')
			{
				// Get the pointer and cast it to unsigned long
				ptr_val = (unsigned long)va_arg(arg, void *);
				ft_putstr_fd("0x", 1);
				if (ptr_val == 0)
					ft_putchar_fd('0', 1);
				else
					ft_puthex_fd(ptr_val, 1);
				lenth_result += 2 + numlenth_hex(ptr_val);
			}
			else if (format[i] == 'u')
			{
				unsdec_fo = va_arg(arg, unsigned int);
				ft_putunsnbr_fd(unsdec_fo, 1);
				lenth_result += unslenth_num(unsdec_fo);
			}
			else if (format[i] == 'x')
			{
				lowhex_fo = va_arg(arg, unsigned int);
				lowhex_value(lowhex_fo);
				lenth_result += numlenth_hex(lowhex_fo);
			}
			else if (format[i] == 'X')
			{
				uphex_fo = va_arg(arg, unsigned int);
				uphex_value(uphex_fo);
				lenth_result += numlenth_hex(uphex_fo);
			}
			else if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
				lenth_result++;
				
			}
}

int ft_printf(const char *format, ...)
{
	int i;
	int lenth_result;
	va_list arg;

	i = 0;
	lenth_result = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// for the format type
			set_fornat(format, i, lenth_result, arg);
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