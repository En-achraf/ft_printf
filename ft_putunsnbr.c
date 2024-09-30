#include "ft_printf.h"

void ft_putunsnbr_fd(unsigned int nb, int fd) {
	
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putunsnbr_fd(nb / 10, fd);
		ft_putunsnbr_fd(nb % 10, fd);
	}
}