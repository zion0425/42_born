/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:48 by siokim            #+#    #+#             */
/*   Updated: 2022/06/15 20:17:12 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <assert.h>

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
	pivot = find_pivot(*a, '3');

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

void	stack_reverse_rotate(t_list **a, t_list **b, int ra_cnt, int rb_cnt)
{
	while (rb_cnt-- > 0 && ra_cnt-- > 0)
		reverse_rotate_argv(BOTH_STACKNO, a, b);
	while (ra_cnt-- > 0)
		reverse_rotate_argv(A_STACKNO, a, 0);
	while (rb_cnt-- > 0)
		reverse_rotate_argv(B_STACKNO, a, b);
}

void	btoa(t_list **a, t_list **b, int size)
{
	int first_pivot;
	int second_pivot;
	int ra_cnt;
	int	pa_cnt;
	int	rb_cnt;

	first_pivot = find_pivot(*b, '1');
	second_pivot = find_pivot(*b, '2');
	ra_cnt = 0;
	pa_cnt = 0;
	rb_cnt = 0;
	if (size == 1)
		return (void)push_argv(A_STACKNO, a, b);
	while (size--)
	{
		if ((*b)->data < first_pivot)
		{
			rotate_argv(A_STACKNO, b, 0);
			rb_cnt ++;
		}
		else
		{
			push_argv(A_STACKNO, a, b);
			pa_cnt++;
			if ((*b)->data < second_pivot)
			{
				rotate_argv(A_STACKNO, a, b);
				ra_cnt++;
			}
		}
	}
	atob(a, b, pa_cnt - ra_cnt);
	stack_reverse_rotate(a, b, ra_cnt, rb_cnt);
	atob(a, b, ra_cnt);
	btoa(a, b, rb_cnt);
}

void	atob(t_list **a, t_list **b, int size)
{
	int first_pivot;
	int second_pivot;
	int ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	first_pivot = find_pivot(*a, '1');
	second_pivot = find_pivot(*a, '2');
	ra_cnt = 0;
	pb_cnt = 0;
	rb_cnt = 0;
	if (size == 1)
		return ;
	else if (size == 2)
		return (sort_two_arg(a));
	else if (size == 3)
		return (sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data));
	while (size--)
	{
		if ((*a)->data >= second_pivot)
		{
			rotate_argv(A_STACKNO, a, 0);
			ra_cnt ++;
		}
		else
		{
			push_argv(B_STACKNO, a, b);
			pb_cnt++;
			if ((*a)->data >= first_pivot)
			{
				rotate_argv(B_STACKNO, a, b);
				rb_cnt++;
			}
		}
	}
	stack_reverse_rotate(a, b, ra_cnt, rb_cnt);
	atob(a, b, ra_cnt);
	btoa(a, b, rb_cnt);
	btoa(a, b, pb_cnt - rb_cnt);
}

void	real_sorting(t_list **a)
{
	t_list	*b;
	size_t	size;
	
	size = ft_lstsize(*a);
	b = malloc(sizeof(t_list));
	b = 0;
	if (size <= 2)
		sort_two_arg(a);
	else if (size == 3)
		sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	else if (size <= 5)
		sort_five_arg(a, &b);
	else
		atob(a, &b, size);
}
