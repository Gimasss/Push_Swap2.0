/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:10:36 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/13 15:38:55 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ---------------------------------------------------------------------------
//
// 1. Check for valid integers -> only integers, no duplicates,
// 							within INT_MIN and INT_MAX
// 2. Convert arguments into a linked list or array-based stack.
// 3. Handle duplicates and errors properly.
//
// ---------------------------------------------------------------------------

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	while ((nptr[i] && nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

