/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:56:11 by giomastr          #+#    #+#             */
/*   Updated: 2025/03/04 16:20:16 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swappy(t_list **stack)
{
	int temp;

	temp = (*stack) -> data;
	(*stack) -> data = (*stack) -> next -> data;
	(*stack) -> next -> data = temp;	
}

void	swap_a(t_list **stack_a)
{
	swappy(stack_a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_list **stack_b)
{
	swappy(stack_b);
	ft_putendl_fd("sb", 1);
}