/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:46 by siokim            #+#    #+#             */
/*   Updated: 2022/05/27 04:05:50 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//void	push_swap()
//{

//}

int	input_check(char **argv)
{
	size_t	i;
	size_t	j;

	if (argv[1][0] == "" || argv[1][0] == '\0')
		return (INPUT_ERROR);
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (INPUT_ERROR);
		++i;
	}
	return (INPUT_SUCCESS);
}

int	main(int argc, char **argv)
{

	printf("%d\n",1);
	//t_list *stackA = ft_lstnew(argv[0]);
	if (argc < 2 || input_check(argv) == INPUT_ERROR)
		exit(1);
	printf("%c",argv[1][0]);

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
