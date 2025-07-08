/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:54:01 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/14 14:44:26 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	word_count(char const *s, char c)
{
	int	word;
	int	in_word;
	int	i;

	i = 0;
	in_word = 0;
	word = 0;
	while (s[i])
	{
		if (!in_word && !is_sep(s[i], c))
		{
			in_word = 1;
			word++;
		}
		if (in_word && is_sep(s[i], c))
			in_word = 0;
		i++;
	}
	return (word);
}

static char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

static char	*get_word(char const *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, (i + 1));
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] && j < word_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		tab[j] = get_word(s + i, c);
		if (!tab[j])
			return (ft_free(tab));
		i += ft_strlen(tab[j]);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
/* #include <stdio.h>

int	main(void)
{
	int i = 0;
	char *str = "Hello word !How are you ?";
	char **res = ft_split(str, ' ');

	while (res[i])
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
	return (0);
} */
