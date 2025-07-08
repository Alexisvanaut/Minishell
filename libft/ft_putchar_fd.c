/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:22:20 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/11 12:35:53 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return ;
}

/* int main(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	return (0);
} */
