/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 04:51:40 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/16 04:51:41 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnb_hex(unsigned int number, int mode, int *len)
{
	char	*hex;
	char	*hex1;

	hex = "0123456789abcdef";
	hex1 = "012345689ABCDEF";
	if (number >= 16)
		ft_puthex(number / 16, len);
	if (mode == 1)
	{
		ft_putchar(hex[number % 16]);
		(*len)++;
	}
	if (mode == 0)
	{
		ft_putchar(hex1[number % 16]);
		(*len)++;
	}
}
