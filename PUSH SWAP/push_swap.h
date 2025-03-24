/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:25:05 by giomastr          #+#    #+#             */
/*   Updated: 2025/03/06 15:40:27 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"


//******************************/
//**    	struct 		     **/
//****************************/
typedef struct s_list
{
	int data;
	struct s_list *previous;
	struct s_list *next;
} 
t_list;

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
//**     list functions      **/
//****************************/

t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *head);
void	ft_lstadd_front(t_list **head, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **head, t_list *new);

//******************************/
//**    utility functions    **/
//****************************/

t_list	ft_lst_bf_last(t_list *lst);
t_list	*get_val(t_list *stack, int value);
t_list	*get_min(t_list *stack);
int		sorted(t_list *stack);

#endif