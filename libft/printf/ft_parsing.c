/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:07:05 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/16 14:38:31 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}
