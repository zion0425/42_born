/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:00:32 by siokim            #+#    #+#             */
/*   Updated: 2022/06/22 20:14:08 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_exit_program(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(1);
}

static int	is_max_int(long num)
{
	return (INT32_MAX < num || INT32_MIN > num);
}

static long	is_digit_atoi(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error_exit_program();
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

int	input_check(char *tmp_split_value)
{
	size_t	i;
	long	tmp_int;

	i = 0;
	tmp_int = is_digit_atoi(tmp_split_value);
	if (is_max_int(tmp_int))
		print_error_exit_program();
	return (tmp_int);
}
