/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:54:47 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/09 17:16:17 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	char			cc;
	unsigned int	i;

	cc = (char)c;
	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}
	if (cc == s[i])
		res = (char *)&s[i];
	return (res);
}
