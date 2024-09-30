/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:12:22 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 22:12:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_fornat(const char *format, int i, int *lenth_result, va_list arg)
{
	char charcter;
	char *string;
	
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
	/*else if(format[i] == 'd') {
		va_arg(arg, int);
	}*/
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
			set_fornat(format, i, &lenth_result, arg);
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
