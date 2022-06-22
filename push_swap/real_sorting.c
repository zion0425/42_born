/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:48 by siokim            #+#    #+#             */
/*   Updated: 2022/06/21 18:07:00 by siokim           ###   ########.fr       */
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

char	escape_loop(t_list **a, t_list **b, int size, char format)
{
	char	res;

	res = 0;
	if (format == 'b' && size <= 2)
	{
		if (size < 1)
			return (INPUT_ERROR);
		else if (size == 1)
			res = push_argv(A_STACKNO, a, b);
		else if (size == 2)
		{
			if ((*b)->data < (*b)->next->data)
				swap_argv(B_STACKNO, a, b);
			push_argv(A_STACKNO, a, b);
			res = push_argv(A_STACKNO, a, b);
		}
	}
	else if (format == 'a' && size <= 2)
	{
		if (size == 1)
			return (INPUT_ERROR);
		else if (size == 2)
			res = sort_two_arg(A_STACKNO, a);
	}
	return (res);
}

void	btoa(t_list **a, t_list **b, int size)
{
	int	first_second_pivot[2];
	int	rb_pa_ra[3];

	if (escape_loop(a, b, size, 'b'))
		return ;
	first_second_pivot[0] = find_pivot(*b, 0, size, '1');
	first_second_pivot[1] = find_pivot(*b, 0, size, '2');
	rb_pa_ra[0] = 0;
	rb_pa_ra[1] = 0;
	rb_pa_ra[2] = 0;
	while (size--)
	{
		if ((*b)->data < first_second_pivot[0])
			rb_pa_ra[0] += rotate_argv(B_STACKNO, a, b);
		else
		{
			rb_pa_ra[1] += push_argv(A_STACKNO, a, b);
			if ((*a)->data < first_second_pivot[1])
				rb_pa_ra[2] += rotate_argv(A_STACKNO, a, b);
		}
	}
	atob(a, b, rb_pa_ra[1] - rb_pa_ra[2]);
	stack_reverse_rotate(a, b, rb_pa_ra[2], rb_pa_ra[0]);
	atob(a, b, rb_pa_ra[2]);
	btoa(a, b, rb_pa_ra[0]);
}

void	atob(t_list **a, t_list **b, int size)
{
	int	f_s_pivot[2];
	int	ra_pb_rb[3];

	if (escape_loop(a, b, size, 'a'))
		return ;
	f_s_pivot[0] = find_pivot(*a, 0, size, '1');
	f_s_pivot[1] = find_pivot(*a, 0, size, '2');
	ra_pb_rb[0] = 0;
	ra_pb_rb[1] = 0;
	ra_pb_rb[2] = 0;
	while (size--)
	{
		if ((*a)->data >= f_s_pivot[1])
			ra_pb_rb[0] += rotate_argv(A_STACKNO, a, b);
		else
		{
			ra_pb_rb[1] += push_argv(B_STACKNO, a, b);
			if ((*b)->data >= f_s_pivot[0])
				ra_pb_rb[2] += rotate_argv(B_STACKNO, a, b);
		}
	}
	stack_reverse_rotate(a, b, ra_pb_rb[0], ra_pb_rb[2]);
	atob(a, b, ra_pb_rb[0]);
	btoa(a, b, ra_pb_rb[2]);
	btoa(a, b, ra_pb_rb[1] - ra_pb_rb[2]);
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
