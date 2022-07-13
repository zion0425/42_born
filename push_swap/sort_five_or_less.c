/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 06:40:36 by siokim            #+#    #+#             */
/*   Updated: 2022/06/23 04:38:08 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	is_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (INPUT_ERROR);
		a = a->next;
	}
	return (INPUT_SUCCESS);
}

int	sort_two_arg(char stack_no, t_list **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		swap_argv(stack_no, stack, stack);
	return (1);
}

void	sort_three_arg(t_list **stack, int fir, int sec, int trd)
{
	if (fir < sec && fir < trd)
	{
		if (sec > trd)
		{
			swap_argv(A_STACKNO, stack, 0);
			rotate_argv(A_STACKNO, stack, 0);
		}
	}
	else if (sec < fir && sec < trd)
	{
		if (fir > trd)
			rotate_argv(A_STACKNO, stack, 0);
		else
			swap_argv(A_STACKNO, stack, 0);
	}
	else if (trd < fir && trd < sec)
	{
		if (fir > sec)
		{
			swap_argv(A_STACKNO, stack, 0);
			reverse_rotate_argv(A_STACKNO, stack, 0);
		}
		else
			reverse_rotate_argv(A_STACKNO, stack, 0);
	}
}

void	sort_five_arg(t_list **a, t_list **b)
{
	int	pivot;

	pivot = find_pivot(*a, 0, 5, '3');
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->data > pivot)
			push_argv(B_STACKNO, a, b);
		else
			rotate_argv(A_STACKNO, a, b);
	}
	sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	if (ft_lstsize(*b) == 2)
		sort_two_arg(B_STACKNO, b);
	while (ft_lstsize(*b) > 0)
	{
		push_argv(A_STACKNO, a, b);
		rotate_argv(A_STACKNO, a, 0);
	}
}
