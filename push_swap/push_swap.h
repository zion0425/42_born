/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:13:48 by siokim            #+#    #+#             */
/*   Updated: 2022/06/20 17:02:05 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define A_STACKNO 0
# define B_STACKNO 1
# define BOTH_STACKNO 2
# define INPUT_ERROR 1
# define INPUT_SUCCESS 0
# define FORMAT_PUSH 0
# define FORMAT_SWAP 1

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int data);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstbeforelast(t_list *lst);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		input_check(char *tmpSplitValue);
void	print_error_exit_program(void);

void	swap_argv(char stack_no, t_list **stack_a, t_list **stack_b);
void	rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b);
void	reverse_rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b);
void	push_argv(char stack_no, t_list **stack_a, t_list **stack_b);
int		find_pivot(t_list *stack_a, int left, int right ,char f);
void	real_sorting(t_list **a);
int		check_stack(int size, t_list *stack);
void	atob(t_list **a, t_list **b, int size);
void	btoa(t_list **a, t_list **b, int size);
void	sort_five_arg(t_list **a, t_list **b);
void	sort_three_arg(t_list **stack, int fir, int sec, int trd);
void	sort_two_arg(char stack_no, t_list **stack);
void	reverse_rotate_argv(char stack_no, t_list **stack_a, t_list **stack_b);

#endif
