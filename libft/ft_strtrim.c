/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:11:32 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/10 14:53:42 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_set(const char *str, size_t start, size_t len)
{
	size_t	i;
	char	*strtrim;

	i = 0;
	if (len <= 0)
		return (ft_strdup(""));
	strtrim = ft_calloc(1 + len, sizeof(char));
	if (!strtrim)
		return (NULL);
	while (i < len)
	{
		strtrim[i] = str[start + i];
		i++;
	}
	return (strtrim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	j = j - 1;
	while (is_set(s1[i], set))
		i++;
	if (i > j)
		return (ft_strdup(""));
	while (is_set(s1[j], set))
		j--;
	return (str_set(s1, i, j - i + 1));
}
/* #include <stdio.h>
int	main(void)
{
	const char s1[] = "aaaalllexisss";
	const char set[] = "als";
	printf("MOn ft_strtrim : %s\n", ft_strtrim(s1, set));
} */
