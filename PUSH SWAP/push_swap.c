/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:27:05 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/13 16:40:06 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_mklist(int argc, char *argv[])
{
	char	**string;
	t_list	*stack_a;

	if (argc == 1)//one arg is not enough
		return (NULL);
	if (argc == 2)//second argument is between brackets, split content
		string = ft_split(argv[1], ' ');
	else//if not bracketed, assumes each argument is a separate value and duplicates the array of arguments (excluding the program name) using mat_dupl.
		// string = dup_matrix(&argv[1], argc - 1);//I use the address to skip argv[0] // make funct
	if (!string)
		return (ft_putendl_fd("Error", 2), exit (1), NULL);
	// stack_a = parse(string);
	if (stack_a == NULL && string[0])//error in parsing
		return (free_mat(string), exit (1), NULL);
	free_mat(string);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_mklist(argc, argv);
	if (stack_a == NULL)//error in list creation
		return (0);
	//sorty(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}