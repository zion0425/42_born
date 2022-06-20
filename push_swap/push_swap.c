/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:46 by siokim            #+#    #+#             */
/*   Updated: 2022/06/20 17:04:41 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_arr_malloc_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i++] = 0;
	}
	free(s);
	s = 0;
}

void	malloc_free(t_list *s)
{
	free(s);
	s = 0;
}

char	is_cmp_values(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*cur;

	cur = stack_a;
	while (cur->next)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->data == tmp->data)
				return (INPUT_ERROR);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (INPUT_SUCCESS);
}

t_list	*create_stack_a(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tmp_split_value;
	t_list	*stack_a;
	t_list	*tmp_list_value;

	i = 1;
	stack_a = malloc(sizeof(t_list));
	stack_a = 0;
	while (i < argc)
	{
		tmp_split_value = ft_split(argv[i++], ' ');
		j = 0;
		while (tmp_split_value[j])
		{
			tmp_list_value = ft_lstnew(input_check(tmp_split_value[j]));
			ft_lstadd_back(&stack_a, tmp_list_value);
			j++;
		}
		two_arr_malloc_free(tmp_split_value);
		if (j == 0 || is_cmp_values(stack_a) == INPUT_ERROR)
			print_error_exit_program();
	}
	return (stack_a);
}
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a=0;

	if (argc > 1)
	{
		stack_a = create_stack_a(argc, argv);
		real_sorting(&stack_a);
	}

}
