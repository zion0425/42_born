/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:11:42 by siokim            #+#    #+#             */
/*   Updated: 2022/08/23 19:11:01 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*input_check(int argc, char **argv)
{
	int	*av;
	int	i;

	if (argc != 5 && argc != 6)
		return (0);
	av = malloc(sizeof(int) * 5);
	i = argc - 1;
	while (--i >= 0)
	{
		av[i] = ft_atoi(argv[i + 1]);
		if (av[i] < 1)
			return (0);
	}
	if (argc == 5)
		av[MUST_EAT] = -2;
	return (av);
}

t_status	*init_status(int av)
{
	t_status	*status;
	int			i;

	i = -1;
	status = malloc(sizeof(t_status));
	status->real_mutex_fork = malloc(sizeof(pthread_mutex_t) * av);
	status->real_mutex_print = malloc(sizeof(pthread_mutex_t));
	status->threads = malloc(sizeof(pthread_t) * av);
	status->philoes = malloc(sizeof(t_philo) * av);
	if (!status || !status->real_mutex_print \
	|| !status->real_mutex_fork || \
	!status->threads || !status->philoes)
		return (0);
	pthread_mutex_init(status->real_mutex_print, 0);
	while (++i < av)
		pthread_mutex_init(&status->real_mutex_fork[i], 0);
	return (status);
}

void	init_philoes(t_status *status, int i, int *av, long start_time)
{
	status->philoes[i].mutex_forks = status->real_mutex_fork;
	status->philoes[i].mutex_print = status->real_mutex_print;
	status->philoes[i].no = i;
	ft_cpy(status->philoes[i].av, av);
	status->philoes[i].start_time = start_time;
	status->philoes[i].last_eat_time = status->philoes[i].start_time;
}
