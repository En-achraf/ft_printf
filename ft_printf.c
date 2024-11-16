/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:26 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/16 14:55:41 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	form(va_list pt_arg, const char *format, int i)
{
	int	count;
	int	len;

	count = 0;
	if (format[i] == 'c')
	{
		ft_putchar(va_arg(pt_arg, int));
		count++;
	}
	if (format[i] == 's')
	{
		len = ft_putstr(va_arg(pt_arg, char *));
		count += len;
	}
	count += more_form(pt_arg, format, i);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr_arg;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ptr_arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += form(ptr_arg, format, i);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
		i++;
	}
	return (count);
}
