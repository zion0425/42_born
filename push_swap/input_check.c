/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:00:32 by siokim            #+#    #+#             */
/*   Updated: 2022/06/02 14:01:59 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printError(char **s)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	malloc_free(s);
	exit(1);
}

int	isMaxInt(char *num)
{
	return (INT32_MAX < num || INT32_MIN > num);
}

int	isLstContentCmp(t_list **lst)
{

}

int	input_check(char *tmpSplitValue)
{
	size_t	i;

	i = 0;
	while (tmpSplitValue[i])
		if (!ft_isdigit(tmpSplitValue[i]) ||\
		 isMaxInt(tmpSplitValue[i++]))
			return (INPUT_ERROR);
	return (INPUT_SUCCESS);
}
