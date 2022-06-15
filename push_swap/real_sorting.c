/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:48 by siokim            #+#    #+#             */
/*   Updated: 2022/06/14 21:19:31 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_arg(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	if ((*stack)->data > (*stack)->next->data)
		swap_argv(A_STACKNO, stack, 0);
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
	pivot = find_pivot(*a);

	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->data > pivot)
			push_argv(B_STACKNO, a, b);
		else
			rotate_argv(A_STACKNO, a, b);
	}
	sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	sort_two_arg(b);
	while (ft_lstsize(*b) > 0)
	{
		push_argv(A_STACKNO, a, b);
		rotate_argv(A_STACKNO, a, 0);
	}
}

void	btoa(t_list **a, t_list **b, int size)
{
	int	pivot;
	int	size_a;
	int	size_b;

	size_a = 0;
	size_b = 0;
	if (size == 1)
		return (push_argv(A_STACKNO, a, b));
	pivot = find_pivot(*b);
	while (size--)
	{
		if ((*b)->data < pivot)
			rotate_argv(B_STACKNO, 0, b);
		else
			push_argv(A_STACKNO, a, b);
	}
	reverse_rotate_argv(B_STACKNO, 0, b);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	atob(a, b, size_a);
	btoa(a, b, size_b);
}

void	atob(t_list **a, t_list **b, int size)
{
	int	pivot;
	int	size_a;
	int	size_b;

	size_a = 0;
	size_b = 0;
	if (size == 1)
		return ;
	if (size == 2)
		return (sort_two_arg(a));
	pivot = find_pivot(*a);
	while (size--)
	{
		if ((*a)->data > pivot)
			rotate_argv(A_STACKNO, a, 0);
		else
			push_argv(B_STACKNO, a, b);
	}
	reverse_rotate_argv(B_STACKNO, 0, b);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	atob(a, b, size_a);
	btoa(a, b, size_b);
}

void	real_sorting(t_list **a)
{
	t_list	*b;
	int		pivot;
	size_t	size;

	size = ft_lstsize(*a);
	b = malloc(sizeof(t_list));
	b = 0;
	pivot = find_pivot(*a);
	if (size <= 2)
		sort_two_arg(a);
	else if (size == 3)
		sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	else if (size <= 5)
		sort_five_arg(a, &b);
	else
		atob(a, &b, size);
}

