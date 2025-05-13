/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_forward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:37:41 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/13 16:33:54 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_forw(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	if (!*head || !(*head) -> next)
		return ;
	temp = *head;
	*head = (*head) -> next;
	last = ft_lstlast(*head);
	temp -> next = NULL;
	last -> next = temp;
}
//rotate on stack a
void rot_fwd_a(t_list **stack_a)
{
	rot_forw(stack_a);
	ft_putendl_fd("ra", 1);
}
//rotate on stack b
void rot_fwd_b(t_list **stack_b)
{
	rot_forw(stack_b);
	ft_putendl_fd("rb", 1);
}
//rotate both stacks
void rot_fwd_r(t_list **stack_a, t_list **stack_b)
{
	rot_forw(stack_a);
	rot_forw(stack_b);
	ft_putendl_fd("rr", 1);
}