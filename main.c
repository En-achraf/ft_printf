#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{	int *p, a;
	p = &a;


	int len =  ft_printf("the output : %d %p\n", 4556, p);
	printf("the length of ft_printf: %d\n", len);
	len = printf("the output : %d %p\n", 4556, p);
	printf("the length of printf: %d\n", len);
	return (0);
}
