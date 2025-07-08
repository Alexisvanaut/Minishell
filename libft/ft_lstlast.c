/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:11:47 by alvanaut          #+#    #+#             */
/*   Updated: 2025/04/14 10:19:36 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/* #include <stdio.h>

int	main(void)
{
	t_list *head = NULL;

	ft_lstadd_front(&head, ft_lstnew("node 1"));
	ft_lstadd_front(&head, ft_lstnew("node 2"));
	ft_lstadd_front(&head, ft_lstnew("node 3"));

	t_list *lstlast = ft_lstlast(head);
	printf("Le derniere element de ma liste est : %s\n",
		(char *)lstlast->content);

	t_list *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

	return (0);
} */
