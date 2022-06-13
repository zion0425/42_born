/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:29:21 by siokim            #+#    #+#             */
/*   Updated: 2022/06/13 22:49:53 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(int size, t_list *stack)
{
	if (ft_lstsize(stack) < size)
		return (INPUT_ERROR);
	return (INPUT_SUCCESS);
}

void	push_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_no == A_STACKNO)
	{
		if (check_stack(1, *stack_b) == INPUT_ERROR)
			return ;
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_a);
		*stack_a = *stack_b;
		*stack_b = tmp;
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else
	{
		if (check_stack(1, *stack_a) == INPUT_ERROR)
			return ;
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_b);
		*stack_b = *stack_a;
		*stack_a = tmp;
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}

void	swap_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_no == A_STACKNO || stack_no == BOTH_STACKNO)
	{
		if (check_stack(2, *stack_a) == INPUT_ERROR)
			return ;
		tmp = (*stack_a)->next;
		(*stack_a)->next = tmp->next;
		tmp->next = (*stack_a);
		*stack_a = tmp;
	}
	if (stack_no == B_STACKNO || stack_no == BOTH_STACKNO)
	{
		if (check_stack(2, *stack_b) == INPUT_ERROR)
			return ;
		tmp = (*stack_b)->next;
		(*stack_b)->next = tmp->next;
		tmp->next = (*stack_b);
		*stack_b = tmp;
	}
	if (stack_no == A_STACKNO)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (stack_no == B_STACKNO)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	else
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}

void	rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_no == A_STACKNO || stack_no == BOTH_STACKNO)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = 0;
		ft_lstlast(tmp)->next = *stack_a;
		*stack_a = tmp;
	}
	if (stack_no == B_STACKNO || stack_no == BOTH_STACKNO)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = 0;
		ft_lstlast(tmp)->next = *stack_b;
		*stack_b = tmp;
	}
	if (stack_no == A_STACKNO)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	else if (stack_no == B_STACKNO)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	else
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	reverse_rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_no == A_STACKNO || stack_no == BOTH_STACKNO)
	{
		tmp = ft_lstlast(*stack_a);
		ft_lstbeforelast(*stack_a)->next = 0;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	if (stack_no == B_STACKNO || stack_no == BOTH_STACKNO)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = 0;
		ft_lstlast(tmp)->next = *stack_b;
		*stack_b = tmp;
	}
	if (stack_no == A_STACKNO)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (stack_no == B_STACKNO)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	else
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
