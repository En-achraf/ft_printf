#include "ft_printf.h"

void	ft_puthex_fd(unsigned long n, int fd)
{
	char *hex = "0123456789abcdef";
	if(n >= 16)
		ft_puthex_fd(n / 16, fd);
	ft_putchar_fd(hex[n % 16], 1);
}
