/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:00:44 by giomastr          #+#    #+#             */
/*   Updated: 2025/03/08 15:55:56 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_list **stack)
{
	int	top;
	int	mid;
	int bott;

	//135 - do nothing
	
	//315 - swap first 2
	//531 - swap + rev rot
	
	//513 - rotate
	
	//351 - rev rotate
	//153 - rev rot + swap

	if (sorted(*stack) == 1)
		return (0);
	if (ft_lstsize(*stack) == 2)
		return (swap_a(stack), 0);
	top = (*stack)->data;
	mid = (*stack)->next->data;
	bott = (*stack)->next->next->data;
}