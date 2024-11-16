/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:14:20 by acennadi          #+#    #+#             */
/*   Updated: 2024/11/16 17:26:15 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n, int *len);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		more_form(va_list pt_arg, const char *format, int i);
void	ft_puthex(unsigned long n, int *lenth);
void	ft_unputnbr(unsigned int nb, int *len);
void	putnb_hex(unsigned int number, int mode, int *len);

#endif