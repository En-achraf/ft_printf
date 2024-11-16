/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 04:51:47 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/16 04:55:01 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unputnbr(unsigned int nb, int *len)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		(*len)++;
	}
	else
	{
		ft_unputnbr(nb / 10, len);
		ft_unputnbr(nb % 10, len);
	}
}
