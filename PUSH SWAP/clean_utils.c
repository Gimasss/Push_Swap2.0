/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:31:36 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/13 16:31:59 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mat(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	free_stack(t_list *stack)
{
	t_list *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free (stack);
		stack = temp;
	}
}