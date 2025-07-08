/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:05:00 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/11 15:11:23 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* #include <stdio.h>

int	main(void)
{
	t_list *head = NULL;

	ft_lstadd_front(&head, ft_lstnew("node 1"));
	ft_lstadd_front(&head, ft_lstnew("node 2"));
	ft_lstadd_front(&head, ft_lstnew("node 3"));

	int size = ft_lstsize(head);
	printf("La taille de la liste est de : %d\n", size);

	t_list *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
} */
