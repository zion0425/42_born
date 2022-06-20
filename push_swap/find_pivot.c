/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:56:43 by siokim            #+#    #+#             */
/*   Updated: 2022/06/20 17:01:52 by siokim           ###   ########.fr       */
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
	int		size;

	size = ft_lstsize(stack);
	arr = (int *)malloc(sizeof(int) * (size + 1));
	i = 0;
	while (stack)
	{
		arr[i++] = stack->data;
		stack = stack->next;
	}
	arr[i] = 0;
	return (arr);
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	low = left;
	high = right;
	pivot = arr[(left + right) / 2];
	while (low < high)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high)
			swap(&arr[low++], &arr[high--]);
	}
	if (left < high)
		quick_sort(arr, left, high);
	if (right > low)
		quick_sort(arr, low, right);
}

int	find_pivot(t_list *stack_a, int left, int right ,char f)
{
	int		*arr;
	int		pivot;

	arr = stack_to_arr(stack_a);
	quick_sort(arr, left, right - 1);
	if (f == '1')
		pivot = arr[right / 3];
	else if (f == '2')
		pivot = arr[right * 2 / 3];
	else
		pivot = arr[right / 2];
	free(arr);
	return (pivot);
}
