/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:24:26 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 15:25:51 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//find biggest value
t_list	*ft_lst_bf_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

t_list	*get_val(t_list *stack, int value)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (current -> data == value)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

t_list	*get_min(t_list *stack)
{
	t_list	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack != NULL)
	{
		if (stack -> data < min -> data)
			min = stack;
		stack = stack -> next;
	}
	return (min);
}

int	sorted(t_list *stack)
{
	if (stack == NULL)
		return (0);
	while (stack -> next != NULL)
	{
		if (stack -> data > stack->next->data)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

char	**dup_matrix(char **str, int argc)
{
	//int argc mi da' la dimensione
	int		i;
	char	**matrix;

	matrix = ft_calloc(argc + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		matrix[i] = ft_strdup(str[i]);
		if (!matrix[i])
			return (free(matrix), NULL);
	}
	return (matrix);
}