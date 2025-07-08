/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:33:45 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/10 16:40:49 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		tab[i] = (*f)(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/* #include <stdio.h>

char	my_func(unsigned int i, char c)
{
	return (c + i % 26);
}

int	main(void)
{
	char *res = ft_strmapi("abc", my_func);
	printf("%s\n", res);
	free(res);
	return (0);
} */
