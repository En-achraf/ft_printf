/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:26 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/19 16:05:33 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char const *format, int i, int *count)
{
	ft_putchar(format[i]);
	(*count)++;
}

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
	else if (format[i] == 's')
	{
		str = va_arg(pt_arg, char *);
		if (!str)
			len = ft_putstr("(null)");
		else
			len = ft_putstr(str);
		count += len;
	}
	else
		count += more_form(pt_arg, format, i);
	return (count);
}

static int	ft_read(const char *format, va_list ptr_arg, int i, int tmp_count)
{
	int	count;

	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmp_count = form(ptr_arg, format, i);
			if (tmp_count == -1)
				continue ;
			count += tmp_count;
		}
		else
			ft_print(format, i, &count);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr_arg;

	int
		(i), (count), (tmp_count);
	i = 0;
	count = 0;
	tmp_count = 0;
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	va_start(ptr_arg, format);
	count += ft_read(format, ptr_arg, i, tmp_count);
	va_end(ptr_arg);
	return (count);
}
