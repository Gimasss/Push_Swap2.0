/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:30:39 by giomastr          #+#    #+#             */
/*   Updated: 2025/03/03 17:41:34 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushy(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	if (*dst == NULL)
	{
		//Node from stack_a becomes first node of stack_b
		temp = (*src) -> next;
		(*src) -> next = NULL;
		*dst = *src;
		*src = temp;
	}
	temp = (*src) -> next;
	(*src) -> next = *dst;
	*dst = *src;
	*src = temp;
}

void	 push_b(t_list **stack_a, t_list **stack_b)
{
	pushy(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	pushy(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}