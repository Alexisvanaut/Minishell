/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:36:24 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/14 14:34:31 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*s;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len || len == 0)
		return (ft_strdup(""));
	if (start + len > str_len)
		s = (char *)malloc(sizeof(char) * (str_len - start + 1));
	else
		s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[start] && i < len)
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}
/* #include <stdio.h>

int	main(void)
{
	const char	str[] = "Alexis Vanautgaerden";

	printf("Ma ft_substr : %s\n", ft_substr(str, 0, ft_strlen(str)));
	return (0);
} */
