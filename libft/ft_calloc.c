/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:21:26 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/14 14:12:14 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	i = 0;
	tmp = (unsigned char *)malloc(sizeof(char) * (count * size));
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}
