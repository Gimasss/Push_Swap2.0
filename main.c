/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:27:05 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 16:48:48 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = make_parsed_list(argc, argv);
	if (stack_a == NULL)
		return (0);
	sorty(&stack_a, &stack_b);
	if (!sorted(stack_a))
		printf("shiet\n");
	// print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}