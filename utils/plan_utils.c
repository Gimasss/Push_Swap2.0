/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:12:34 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 15:38:56 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_top(t_list **stack_a)
{
	t_list	*min;
	t_list	*temp;
	int		index;
	int		stack_a_sz;

	index = -1;
	temp = *stack_a;
	min = get_min(*stack_a);// min value
	stack_a_sz = ft_lstsize(*stack_a);
	while (temp && ++index > -1)//ask about this
	{
		if (temp->data == min->data)
			break ;
		temp = temp->next;
	}
	if (index <= stack_a_sz / 2)
		while (index-- > 0)
			rot_fwd_a(stack_a);
	else
		while (stack_a_sz - index++ > 0)
			rot_bkw_a(stack_a);
}

int	get_average(t_list *stack)
{
	const int		size = ft_lstsize(stack);
	int				sum;

	sum = 0;
	if (size == 0)
		return (0);
	while (stack)
	{
		sum += stack->data;
		stack = stack->next;
	}
	return (sum / size);
}

t_list	*best_target(t_list *stack_b)
{
	t_list		*best;

	best = stack_b;
	while (stack_b)
	{
		if (best->target.totmoves > stack_b->target.totmoves)
			best = stack_b;
		stack_b = stack_b->next;
	}
	return (best);
}

//current is the number in stack b
//other_stack is the number in stack a
int	get_next_bigger(t_list *current, t_list *other_stack)
{
	const int		data = current->data;
	t_list			*cur;
	int				res;
	int				i;

	cur = other_stack;//nodo target
	other_stack = other_stack->next;
	i = 0;
	res = -1;
	if (cur->data > data)
		res = 0;
	while (other_stack && ++i)
	{
		if (other_stack->data > data
			&& (res == -1 || (other_stack->data < cur->data)))
		{
			cur = other_stack;
			res = i;
		}
		other_stack = other_stack->next;
	}
	current->target.next_bigger = cur;
	current->target.next_index = res;
	return (res);
}
