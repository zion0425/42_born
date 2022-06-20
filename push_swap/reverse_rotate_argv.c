/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:19:20 by siokim            #+#    #+#             */
/*   Updated: 2022/06/20 02:31:35 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(int size, t_list *stack)
{
	if (ft_lstsize(stack) < size)
		return (INPUT_ERROR);
	return (INPUT_SUCCESS);
}

char	reverse_rotate_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack);
	ft_lstbeforelast(*stack)->next = 0;
	tmp->next = *stack;
	*stack = tmp;
	return (INPUT_SUCCESS);
}

void	reverse_rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b)
{
	if (stack_no == A_STACKNO || stack_no == BOTH_STACKNO)
		if (check_stack(2, *stack_a) == INPUT_SUCCESS)
			reverse_rotate_stack(stack_a);
	if (stack_no == B_STACKNO || stack_no == BOTH_STACKNO)
		if (check_stack(2, *stack_b) == INPUT_SUCCESS)
			reverse_rotate_stack(stack_b);
	if (stack_no == A_STACKNO)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (stack_no == B_STACKNO)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	else
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
