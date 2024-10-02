/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:13:31 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 11:44:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int **lenth)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		(**lenth)++;
		nb = -n;
	}
	else
		nb = n;
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		(**lenth)++;
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd, lenth);
		ft_putchar_fd((nb % 10) + '0', fd);
		(**lenth)++;
	}
}
