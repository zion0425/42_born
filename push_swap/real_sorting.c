/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:48 by siokim            #+#    #+#             */
/*   Updated: 2022/06/21 07:57:01 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_reverse_rotate(t_list **a, t_list **b, int ra_cnt, int rb_cnt)
{
	while (rb_cnt > 0 && ra_cnt > 0)
	{
		reverse_rotate_argv(BOTH_STACKNO, a, b);
		rb_cnt--;
		ra_cnt--;
	}
	while (ra_cnt-- > 0)
		reverse_rotate_argv(A_STACKNO, a, b);
	while (rb_cnt-- > 0)
		reverse_rotate_argv(B_STACKNO, a, b);
}

void	btoa(t_list **a, t_list **b, int size)
{
	int	first_pivot;
	int	second_pivot;
	int	ra_cnt;
	int	pa_cnt;
	int	rb_cnt;

	char isend_init
	if (size < 1)
		return ;
	else if (size == 1)
		return ((void)push_argv(A_STACKNO, a, b));
	else if (size == 2)
	{
		if ((*b)->data < (*b)->next->data)
			swap_argv(B_STACKNO, a, b);
		push_argv(A_STACKNO, a, b);
		return ((void)(push_argv(A_STACKNO, a, b)));
	}
	first_pivot = find_pivot(*b, 0, size, '1');
	second_pivot = find_pivot(*b, 0, size, '2');
	ra_cnt = 0;
	pa_cnt = 0;
	rb_cnt = 0;
	while (size--)
	{
		if ((*b)->data < first_pivot)
			rb_cnt += rotate_argv(B_STACKNO, a, b);
		else
		{
			pa_cnt += push_argv(A_STACKNO, a, b);
			if ((*a)->data < second_pivot)
				ra_cnt += rotate_argv(A_STACKNO, a, b);
		}
	}
	atob(a, b, pa_cnt - ra_cnt);
	stack_reverse_rotate(a, b, ra_cnt, rb_cnt);
	atob(a, b, ra_cnt);
	btoa(a, b, rb_cnt);
}

void	atob(t_list **a, t_list **b, int size)
{
	int	first_pivot;
	int	second_pivot;
	int	ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	if (size == 1)
		return ;
	else if (size == 2)
		return (sort_two_arg(A_STACKNO, a));
	first_pivot = find_pivot(*a, 0, size, '1');
	second_pivot = find_pivot(*a, 0, size, '2');
	ra_cnt = 0;
	pb_cnt = 0;
	rb_cnt = 0;
	while (size--)
	{
		if ((*a)->data >= second_pivot)
			ra_cnt += rotate_argv(A_STACKNO, a, b);
		else
		{
			pb_cnt += push_argv(B_STACKNO, a, b);
			if ((*b)->data >= first_pivot)
				rb_cnt += rotate_argv(B_STACKNO, a, b);
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
		sort_two_arg(A_STACKNO, a);
	else if (size == 3)
		sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	else if (size <= 5)
		sort_five_arg(a, &b);
	else
		atob(a, &b, size);
}
