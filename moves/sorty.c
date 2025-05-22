/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:00:44 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 16:48:31 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

int	sort_three(t_list **stack)
{
	int	top;
	int	mid;
	int bott;

	if (sorted(*stack) == 1)
		return ( 0);
	if (ft_lstsize(*stack) == 2)
		return (swap_a(stack), 0);
	top = (*stack)->data;
	mid = (*stack)->next->data;
	bott = (*stack)->next->next->data;
	if ( ((top < mid && top < bott)//0 9 5
		|| (bott > top && mid < bott)// 5 0 9
		|| (top > mid && mid > bott) ))// 5 9 0
			swap_a(stack);
	top = (*stack)->data;
	mid = (*stack)->next->data;
	if (top > mid && mid < bott)// 9 0 5
		rot_fwd_a(stack);
	else if (top < mid && mid > bott)
		rot_bkw_a(stack);
	return (0);
}

int	sorty(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_size;

	stack_a_size = ft_lstsize(*stack_a);
	if (sorted(*stack_a) == 1)//1 is true
		return (0);
	while (stack_a_size > 3 && !sorted(*stack_a))
	{
		if ((*stack_a)->data < get_average(*stack_b))
			push_b(stack_a, stack_b);
		else
		{
			push_b(stack_a, stack_b);
			rot_fwd_b(stack_b);
		}
		stack_a_size--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		calc_next_move(*stack_a, *stack_b);
		exec_move(stack_a, stack_b);
	}
	min_to_top(stack_a);
	return (0);
}
