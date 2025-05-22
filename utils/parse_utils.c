/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:10:36 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 18:07:41 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	solid_number(char *s)
// {
// 	int i = 0;
// 	//check for multiple signs
// 	if (s[i] == '+' || s[i] == '-')


// }
int	sign_check(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (sign);
}

int	*parse_atoi(const char *str)
{
	int		i;
	int		sign;
	int		temp;
	int 	*result;

	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	sign = sign_check(str);
	if (sign == 0)
		return(free(result), NULL);
	i = 0;
	*result = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		temp = *result;
		*result = (*result * 10) + (str[i] - '0');
		if (*result / 10 != temp)
			return (free(result), NULL);
		i++;
	}
	if (str[i] != '\0')
		return (free(result), NULL);
	*result = *result * sign;
	return (result);
}

t_list	*parse_more(char **string)
{
	int	i;
	int	*number;
	t_list *stack_a;
	t_list *node;

	i = -1;
	stack_a = NULL;
	while (string[++i])
	{
		number = parse_atoi(string[i]);
		if (!number)//qualcosa non numero
			return (err_free("Number: Error", stack_a), NULL);
		if (get_val(stack_a, *number))//if del doppione
			return (err_free("Double: Error", stack_a), free(number), NULL);
		node = ft_lstnew(*number);
		free(number);
		if (!node)//error in list creationn
			return (err_free("NODE: Error", stack_a), NULL);
		ft_lstadd_back(&stack_a, node);
	}
	return (stack_a);
}

t_list	*make_parsed_list(int argc, char *argv[])
{
	char	**string;
	t_list	*stack_a;

	if (argc == 1)//one arg is not enough
		return (NULL);
	if (argc == 2)//second argument is between brackets, split content
		string = ft_split(argv[1], ' ');
	else//if not bracketed, assumes each argument is a separate value and duplicates the array of arguments (excluding the program name) using mat_dupl.
		string = dup_matrix(&argv[1], argc - 1);//I use the address to skip argv[0]
	if (!string)
		return (ft_putendl_fd("Error", 2), exit (1), NULL);
	stack_a = parse_more(string);
	if (stack_a == NULL && string[0])//error in parsing
		return (free_mat(string), exit (1), NULL);
	free_mat(string);
	return (stack_a);
}