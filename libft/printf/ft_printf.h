/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:08:05 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/16 14:38:55 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_parsing(char c, va_list args);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(unsigned long n);
int	ft_putnbr(long long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_print_hex_lower(unsigned int n);
int	ft_print_hex_upper(unsigned int n);

#endif
