/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:26 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/16 17:03:04 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	form(va_list pt_arg, const char *format, int i)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	if (format[i] == 'c')
	{
		ft_putchar(va_arg(pt_arg, int));
		count++;
	}
	if (format[i] == 's')
	{
		str = va_arg(pt_arg, char *);
		if (!str)
			len = ft_putstr("(null)");
		else
			len = ft_putstr(str);
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

	i = 0;
	count = 0;
	if (!format || write(1, 0, 0))
		return (-1);
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
			count++;
		}
		i++;
	}
	return (count);
}
