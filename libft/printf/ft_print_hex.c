/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:17:26 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/16 14:43:31 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	len++;
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 0;
	n = (unsigned long)ptr;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	len += 2;
	len += ft_print_hex(n);
	return (len);
}

int	ft_print_hex_lower(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex_lower(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	len++;
	return (len);
}

int	ft_print_hex_upper(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex_upper(n / 16);
	ft_putchar("0123456789ABCDEF"[n % 16]);
	len++;
	return (len);
}
