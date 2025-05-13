/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:00:44 by giomastr          #+#    #+#             */
/*   Updated: 2025/03/26 16:55:56 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******** */
/* SORT MAP */
/* ******** */

#include "push_swap.h"

int	sort_three(t_list **stack)
{
	int	top;
	int	mid;
	int bott;	

	top = (*stack)->data;
	mid = (*stack)->next->data;
	bott = (*stack)->next->next->data;
	if (sorted(*stack) == 1) //(0)
		return (0);
	if (ft_lstsize(*stack) == 2)
		return (swap_a(stack), 0);
	if (top < bott && mid > bott) //132 -> 312
		swap_a(stack);
	if (top > mid && top < bott ) //213 -> 123 OK
		swap_a(stack);
	if (top > mid && mid < bott) //321 -> 231
		swap_a(stack);
	if (top > bott && mid < bott) // 312 
		rot_fwd_a(stack);
	else if (top < mid && top > bott) //231
		rot_bkw_a(stack);
	return (0);		
}
