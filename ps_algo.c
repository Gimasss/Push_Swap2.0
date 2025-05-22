/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:12:58 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 18:12:51 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_is_target(t_list *current, t_list *other)
{
	t_list	*min;
	int		index;

	min = get_min(other);
	if (!min || !current)
		return ;
	index = 0;
	while (other->data != min->data)
	{
		other = other->next;
		index++;
	}
	current->target.next_bigger = other;
	current->target.next_index = index;
}

void	calc_next_move(t_list *stack_a, t_list *stack_b)//ex where to insert
{
	const int	stack_a_size = ft_lstsize(stack_a);
	const int	stack_b_size = ft_lstsize(stack_b);
	int			i;//index of the stack's number of stack b

	i = -1;
	while (++i < stack_b_size)
	{
		stack_b->target.rot = i;//and how many moves to get there
		stack_b->target.rrot = stack_b_size - i;
		if (get_next_bigger(stack_b, stack_a) == -1)//funzione maledetta
			min_is_target(stack_b, stack_a);
		stack_b->target.next_rot = stack_b->target.next_index;//
		stack_b->target.next_rrot = stack_a_size - stack_b->target.next_index;//su next_index = 3 --> 4(stack_a_size) - 3 = 1 (mossa)
		stack_b->target.totmoves = stack_b->target.next_rrot;
		if (stack_b->target.next_rot < stack_b->target.next_rrot)
			stack_b->target.totmoves = stack_b->target.next_rot;
		if (stack_b->target.rot < stack_b->target.rrot)
			stack_b->target.totmoves += stack_b->target.rot;
		else
			stack_b->target.totmoves += stack_b->target.rrot;
		stack_b = stack_b->next;
	}
}

void	exec_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*best;

	best = best_target(*stack_b);
	if (best->target.rot < best->target.rrot)
		while (best->target.rot-- > 0)
			rot_fwd_b(stack_b);
	else
		while (best->target.rrot-- > 0)
			rot_bkw_b(stack_b);
	if (best->target.next_rot < best->target.next_rrot)
		while (best->target.next_rot-- > 0)
			rot_fwd_a(stack_a);
	else
		while (best->target.next_rrot-- > 0)
			rot_bkw_a(stack_a);
	push_a(stack_a, stack_b);
}