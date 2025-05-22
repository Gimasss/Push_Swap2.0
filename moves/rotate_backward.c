/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_backward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:25:27 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/21 16:21:02 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_backw(t_list **head)
{
	t_list	*temp;
	t_list	*bf_last;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	bf_last = ft_lst_bf_last(*head);
	last = bf_last -> next;
	bf_last -> next = NULL;
	last -> next = *head;
	*head = last;
}

void rot_bkw_a(t_list **stack_a)
{
	rot_backw(stack_a);
	ft_putendl_fd("rra", 1);
}

void rot_bkw_b(t_list **stack_b)
{
	rot_backw(stack_b);
	ft_putendl_fd("rrb", 1);
}

void rot_bkw_r(t_list **stack_a, t_list **stack_b)
{
	rot_backw(stack_a);
	rot_backw(stack_b);
	ft_putendl_fd("rrr", 1);
}