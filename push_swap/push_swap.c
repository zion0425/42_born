/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:46 by siokim            #+#    #+#             */
/*   Updated: 2022/06/02 14:01:48 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**malloc_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}

t_list	**create_StackA(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	char **tmpSplitValue;
	t_list **stackA;
	t_list *tmpListValue;

	stackA = ft_lstnew(0);
	i = 1;
	while (i < argc)
	{
		tmpSplitValue = ft_split(argv[i++], ' ');
		j = 0;
		while (*tmpSplitValue[j])
			if (input_check(tmpSplitValue[j++]) == INPUT_ERROR)
				printError(stackA);
		if (strCmp(stackA))
			printError(stackA);
		if (j == 0)
			printError(stackA);
		tmpListValue = ft_lstnew(tmpSplitValue[i]);
		ft_lstadd_front(stackA, tmpListValue);
		malloc_free(tmpSplitValue);
		free(tmpListValue);
	}
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list **stackA;
	if (argv > 1)
		stackA = create_StackA(argc, argv);
}

//int	check_stack(int stack_no, t_list *stackA, t_list *stackB)
//{
//	if (stack_no == BOTH_STACKNO || stack_no == A_STACKNO)
//		if (!ft_lstsize(stackA))
//			return (INPUT_ERROR);
//	if (stack_no == BOTH_STACKNO || stack_no == B_STACKNO)
//		if (!ft_lstsize(stackB))
//			return (INPUT_ERROR);
//	return(INPUT_SUCCESS);
//}

//int	swap_argv(int stack_no, t_list *stackA, t_list *stackB)
//{
//	return (INPUT_ERROR);
//}

//int	push_argv(int stack_no, t_list *stackA, t_list *stackB)
//{
//	return (INPUT_ERROR);
//}

//int	rotate_argv(int stack_no, t_list *stackA, t_list *stackB)
//{
//	return (INPUT_ERROR);
//}

//int	reverse_rotate_argv(int stack_no, t_list *stackA, t_list *stackB)
//{
//	return (INPUT_ERROR);
//}
