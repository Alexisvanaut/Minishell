/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:52:29 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/11 15:03:53 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>
int	main(void)
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew("Alexis");
	t_list *node2 = ft_lstnew("Vanautgaerden");

	ft_lstadd_front(&head, node1);
	printf("Premiere element ajouter a la lst :%s\n", (char *)head->content);

	ft_lstadd_front(&head, node2);
	printf("Deuxieme element ajouter dans la lst :%s -> %s\n",
		(char *)head->content, (char *)head->next->content);

	free(node1);
	free(node2);

} */
