/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:14:33 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/17 17:33:13 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add_more(va_list pt_arg, const char *format, int i)
{
	int	count;
	int	len;

	len = 0;
	count = 0;
	if (format[i] == 'x')
	{
		putnb_hex((unsigned int)va_arg(pt_arg, int), 1, &len);
		count += len;
	}
	else if (format[i] == 'X')
	{
		putnb_hex((unsigned int)va_arg(pt_arg, int), 0, &len);
		count += len;
	}
	else if (format[i] == '%')
	{
		ft_putchar('%');
		count++;
	}
	else
	{
		count = -1;
	}
	return (count);
}

int	more_form(va_list pt_arg, const char *format, int i)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	if (format[i] == 'd' || format[i] == 'i')
	{
		ft_putnbr(va_arg(pt_arg, int), &len);
		count += len;
	}
	else if (format[i] == 'p')
	{
		ft_putstr("0x");
		if (pt_arg == 0)
			ft_putchar('0');
		else
			ft_puthex((unsigned long)va_arg(pt_arg, void *), &len);
		count += (len + 2);
	}
	else if (format[i] == 'u')
		ft_unputnbr((unsigned int)va_arg(pt_arg, unsigned int), &count);
	else
		count += ft_add_more(pt_arg, format, i);
	return (count);
}
