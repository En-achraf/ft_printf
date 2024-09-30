/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:16:20 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 18:37:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned long n, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_fd(n / 16, fd);
	ft_putchar_fd(hex[n % 16], 1);
}
