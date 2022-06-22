/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:29:21 by siokim            #+#    #+#             */
/*   Updated: 2022/06/23 04:07:52 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_no == A_STACKNO)
	{
		if (check_stack(1, *stack_b) == INPUT_ERROR)
			return (0);
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_a);
		*stack_a = *stack_b;
		*stack_b = tmp;
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else
	{
		if (check_stack(1, *stack_a) == INPUT_ERROR)
			return (0);
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_b);
		*stack_b = *stack_a;
		*stack_a = tmp;
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	return (1);
}

void	swap_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	*stack = tmp;
}

int	swap_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	if (stack_no == A_STACKNO || stack_no == BOTH_STACKNO)
		if (check_stack(2, *stack_a) == INPUT_SUCCESS)
			swap_stack(stack_a);
	if (stack_no == B_STACKNO || stack_no == BOTH_STACKNO)
		if (check_stack(2, *stack_b) == INPUT_SUCCESS)
			swap_stack(stack_b);
	if (stack_no == A_STACKNO)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (stack_no == B_STACKNO)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	else
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	return (1);
}

void	rotate_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = 0;
	ft_lstlast(tmp)->next = *stack;
	*stack = tmp;
}

int	rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	if (stack_no == A_STACKNO || stack_no == BOTH_STACKNO)
		if (check_stack(2, *stack_a) == INPUT_SUCCESS)
			rotate_stack(stack_a);
	if (stack_no == B_STACKNO || stack_no == BOTH_STACKNO)
		if (check_stack(2, *stack_b) == INPUT_SUCCESS)
			rotate_stack(stack_b);
	if (stack_no == A_STACKNO)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	else if (stack_no == B_STACKNO)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	else
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	return (1);
}
