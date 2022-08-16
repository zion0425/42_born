/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:51:30 by siokim            #+#    #+#             */
/*   Updated: 2022/08/16 17:18:45 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

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
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}

void    ft_cpy(int *pav, int *argv)
{
	int	i;

	i = -1;
	while (++i <= 4)
		pav[i] = argv[i];
}

long	microtomill(struct timeval time)
{
	long	micro;
	long	sec;

	micro = time.tv_usec / 1000;
	sec = time.tv_sec * 1000;
	return (micro + sec);
}

long	gettime(long start_time)
{
	struct timeval		time;

	gettimeofday(&time, 0);
	return (microtomill(time) - start_time);
}
