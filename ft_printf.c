/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:12:22 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 12:48:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_formatv2(const char *format, int i, int *lenth_result,
		va_list arg)
{
	unsigned long	ptr_val;

	if (format[i] == 'p')
	{
		ptr_val = (unsigned long)va_arg(arg, void *);
		ft_putstr_fd("0x", 1);
		if (ptr_val == 0)
			ft_putchar_fd('0', 1);
		else
			ft_puthex_fd(ptr_val, 1, &lenth_result);
		*lenth_result+=2;
	}
}

static void	set_format(const char *format, int i, int *lenth_result,
		va_list arg)
{
	char	charcter;
	char	*string;
	int		intform;

	if (format[i] == 's')
	{
		string = va_arg(arg, char *);
		ft_putstr_fd(string, 1);
		*lenth_result += ft_strlen(string);
	}
	else if (format[i] == 'c')
	{
		charcter = (char)va_arg(arg, int);
		ft_putchar_fd(charcter, 1);
		(*lenth_result)++;
	}
	else if (format[i] == 'd' || format[i] == i)
	{
		intform = va_arg(arg, int);
		ft_putnbr_fd(intform, 1, &lenth_result);
	}
	else if (format[i] == '%')
		ft_putchar_fd('%', 1);
	set_formatv2(format, i, lenth_result, arg);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		lenth_result;
	va_list	arg;

	i = 0;
	lenth_result = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			set_format(format, i, &lenth_result, arg);
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
