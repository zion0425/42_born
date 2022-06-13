/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:56:43 by siokim            #+#    #+#             */
/*   Updated: 2022/06/13 23:02:48 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*stack_to_arr(t_list *stack)
{
	int		*arr;
	size_t	i;

	arr = malloc(sizeof(int) * ft_lstsize(stack) + 1);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	arr[i] = 0;
	return (arr);
}

void	get_pivot(int *arr, int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	low = left;
	high = right;
	pivot = arr[(left + right) / 2];
	while (low < high)
	{
		while (arr[low] < pivot && low <= right)
			low++;
		while (arr[high] > pivot && high >= left)
			high--;
		if (low < high)
			swap(&arr[low++], &arr[high--]);
	}
	if (left < high)
		get_pivot(arr, left, high);
	if (left < low)
		get_pivot(arr, low, right);
}

int	find_pivot(t_list *stack_a)
{
	int		*arr;
	size_t	size;

	size = ft_lstsize(stack_a);
	arr = stack_to_arr(stack_a);
	get_pivot(arr, 0, size - 1);
	return (arr[size / 2]);
}
