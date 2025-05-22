/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:25:05 by giomastr          #+#    #+#             */
/*   Updated: 2025/05/22 18:12:11 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//******************************/
//**    	struct 		     **/
//****************************/

typedef struct s_next_node
{
	struct s_list	*next_bigger;
	int				next_index;
	size_t			next_rot;
	size_t			next_rrot;
	size_t			rot;
	size_t			rrot;
	size_t			totmoves;

}	t_next_node;

typedef struct s_list
{
	int				data;
	t_next_node		target;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

//******************************/
//**    rotation functions   **/
//****************************/

void	rot_backw(t_list **head);
void	rot_bkw_a(t_list **stack_a);
void	rot_bkw_b(t_list **stack_b);
void	rot_bkw_r(t_list **stack_a, t_list **stack_b);
void	rot_forw(t_list **head);
void	rot_fwd_a(t_list **stack_a);
void	rot_fwd_b(t_list **stack_b);
void	rot_fwd_r(t_list **stack_a, t_list **stack_b);

//******************************/
//**  push & swap functions  **/
//****************************/

void	pushy(t_list **src, t_list **dst);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swappy(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);

//******************************/
//**    sorting functions    **/
//****************************/

int		sort_three(t_list **stack);
int		sorty(t_list **stack_a, t_list **stack_b);

//******************************/
//**     list functions      **/
//****************************/

t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *head);
void	ft_lstadd_front(t_list **head, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **head, t_list *new);
t_list	*ft_lst_bf_last(t_list *lst);

//******************************/
//**    utility functions    **/
//****************************/

t_list	*get_val(t_list *stack, int value);
t_list	*get_min(t_list *stack);
char	**dup_matrix(char **str, int argc);
int		sorted(t_list *stack);

//******************************/
//**    cleaner functions    **/
//****************************/

void	free_mat(char **str);
void	free_stack(t_list *stack);
void	err_free(char *s, t_list *stack);

//******************************/
//**    parse   functions    **/
//****************************/

t_list	*make_parsed_list(int argc, char *argv[]);
int		*parse_atoi(const char *str);
t_list	*parse_more(char **string);

// other

int		get_average(t_list *stack);
void	min_to_top(t_list **stack_a);
int		get_next_bigger(t_list *current, t_list *other_stack);
t_list	*best_target(t_list *stack_b);

//******************************/
//**    algo   functions     **/
//****************************/

void	min_is_target(t_list *current, t_list *other);
void	exec_move(t_list **stack_a, t_list **stack_b);
void	calc_next_move(t_list *stack_a, t_list *stack_b);
void	print_stack(t_list *stack);

#endif