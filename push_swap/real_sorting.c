/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:48 by siokim            #+#    #+#             */
/*   Updated: 2022/06/20 17:04:27 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_arg(char stack_no, t_list **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		swap_argv(stack_no, stack, stack);
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
	pivot = find_pivot(*a, 0, 3, '3');

	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->data > pivot)
			push_argv(B_STACKNO, a, b);
		else
			rotate_argv(A_STACKNO, a, b);
	}
	sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	sort_two_arg(B_STACKNO, b);
	while (ft_lstsize(*b) > 0)
	{
		push_argv(A_STACKNO, a, b);
		rotate_argv(A_STACKNO, a, 0);
	}
}

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

//void	btoa(t_list **a, t_list **b, int size)
//{
//	int	pivot;
//	int	rb_cnt;
//	int	pa_cnt;

//	if (size <= 1)
//		return push_argv(A_STACKNO, a, b);
//	rb_cnt = 0;
//	pa_cnt = 0;
//	pivot = find_pivot(*a, '3');
//	while (size--)
//	{
//		if ((*b)->data < pivot)
//		{
//			rotate_argv(B_STACKNO, a, b);
//			rb_cnt++;
//		}
//		else
//		{
//			push_argv(A_STACKNO, a, b);
//			pa_cnt++;
//		}
//	}
//	int	i;
//	i = 0;

//	while (i++ < rb_cnt)
//		reverse_rotate_argv(B_STACKNO, a, b);
//	atob(a, b, pa_cnt);
//	btoa(a, b, rb_cnt);
//}

//void	atob(t_list **a, t_list **b, int size)
//{
//	int	pivot;
//	int	ra_cnt;
//	int	pb_cnt;

//	if (size <= 1)
//		return ;
//	if (size == 2)
//		return (sort_two_arg(A_STACKNO, a));
//	ra_cnt = 0;
//	pb_cnt = 0;
//	pivot = find_pivot(*a, '3');
//	while (size--)
//	{
//		if ((*a)->data > pivot)
//		{
//			rotate_argv(A_STACKNO, a, b);
//			ra_cnt++;
//		}
//		else
//		{
//			push_argv(B_STACKNO, a, b);
//			pb_cnt++;
//		}
//	}
//	int	i;
//	i = 0;

//	while (i++ < ra_cnt)
//		reverse_rotate_argv(A_STACKNO, a, b);
//	atob(a, b, ra_cnt);
//	btoa(a, b, pb_cnt);
//}

void	btoa(t_list **a, t_list **b, int size)
{
	int	first_pivot;
	int	second_pivot;
	int	ra_cnt;
	int	pa_cnt;
	int	rb_cnt;

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
		{
			rotate_argv(B_STACKNO, a, b);
			rb_cnt ++;
		}
		else
		{
			push_argv(A_STACKNO, a, b);
			pa_cnt++;
			if ((*a)->data < second_pivot)
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
	int 	first_pivot;
	int 	second_pivot;
	int	ra_cnt;
	int	pb_cnt;
	int	rb_cnt;

	if (size <= 1)
		return ;
	else if (size == 2)
		return (sort_two_arg(A_STACKNO, a));
	//else if (size == 3)
	//	return (sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data));
	first_pivot = find_pivot(*a, 0, size, '1');
	second_pivot = find_pivot(*a, 0, size, '2');
	ra_cnt = 0;
	pb_cnt = 0;
	rb_cnt = 0;
	while (size--)
	{
		if ((*a)->data >= second_pivot)
		{
			rotate_argv(A_STACKNO, a, b);
			ra_cnt ++;
		}
		else
		{
			push_argv(B_STACKNO, a, b);
			pb_cnt++;
			if ((*b)->data >= first_pivot)
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
		sort_two_arg(A_STACKNO, a);
	else if (size == 3)
		sort_three_arg(a, (*a)->data, (*a)->next->data, (*a)->next->next->data);
	else if (size <= 5)
		sort_five_arg(a, &b);
	else
		atob(a, &b, size);
}
