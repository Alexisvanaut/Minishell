/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:43:27 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/11 14:51:14 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = (t_list *)malloc(sizeof(t_list));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
/* #include <stdio.h>

int	main(void)
{
	char *content = "Hello World !";

	t_list *node = ft_lstnew((void *)content);

	if (node == NULL)
	{
		printf("Erreur pour creer la node !");
		return (1);
	}
	printf("Node content : %s\n", (char *)node->content);

	free(node);
} */
