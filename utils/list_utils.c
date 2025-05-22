/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:18:58 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 15:20:58 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list *new_node;

	new_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> data = value;
	new_node -> next = NULL;
	return (new_node);
}
int	ft_lstsize(t_list *head)
{
	int count;

	count = 0;
	while (head)
	{
		count++;
		head = head -> next;
	}
	return (count);
}

void	ft_lstadd_front(t_list **head, t_list *new)
{
	if (!head || !new)
		return ;
	new -> next = *head;
	*head = new;
}

t_list *ft_lstlast(t_list *lst)//iterates til last node
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*last;

	if (!head || !new)
		return (NULL);
	last = ft_lstlast(*head);
	if (!(*head))
		*head = new;
	else
		last->next = new;
	return (*head);
}