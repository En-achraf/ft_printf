/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:31:08 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/16 17:08:29 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, int *lenth)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, lenth);
	ft_putchar(hex[n % 16]);
	(*lenth)++;
}
