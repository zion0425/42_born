/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/08/18 03:53:45 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork(t_philo *p, int *first_fork, int *second_fork, int *no)
{
	*first_fork = p->no % 2;
	if (*first_fork == 0)
		usleep(10000);
	*second_fork = (*first_fork - 1) * -1;
	no[LEFT_FORK] = p->no - 1;
	no[RIGHT_FORK] = p->no;
	if (no[LEFT_FORK] <= -1)
		no[LEFT_FORK] = p->av[NUMBER_OF_PHILOES] - 1;
}

void	*start_thread(void *philo)
{
	t_philo	*p;
	int		no[2];
	int		first_fork;
	int		second_fork;

	p = (t_philo *)philo;
	set_fork(p, &first_fork, &second_fork, no);
	p->start_time = gettime(0);
	p->last_eat_time = p->start_time;
	while (p->av[MUST_EAT]--)
	{
		pthread_mutex_lock(&p->mutex_forks[no[first_fork]]);
		printf("%ldms : %d has taken a fork\n", gettime(p->start_time), p->no + 1);
		pthread_mutex_lock(&p->mutex_forks[no[second_fork]]);
		printf("%ldms : %d has taken a fork\n", gettime(p->start_time), p->no + 1);
		printf("%ldms : %d is eating\n", gettime(p->start_time), p->no + 1);
		//p->last_eat_time = gettime(-(p->av[TIME_TO_EAT] * 1000));
		usleep(p->av[TIME_TO_EAT] * 1000);
		p->last_eat_time = gettime(0);
		pthread_mutex_unlock(&p->mutex_forks[no[first_fork]]);
		pthread_mutex_unlock(&p->mutex_forks[no[second_fork]]);
		printf("%ldms : %d is sleeping\n", gettime(p->start_time), p->no + 1);
		usleep(p->av[TIME_TO_SLEEP] * 1000);
		printf("%ldms : %d is thinking\n", gettime(p->start_time), p->no + 1);
	}
	return ((void *)0);
}

void	monitoring(t_status *s)
{
	int	i;
	int	finished_philo;
	int	j;

	i = -1;
	j = -1;
	finished_philo = 0;
	while (++i <= s->philoes[0].av[NUMBER_OF_PHILOES])
	{
		if (i == s->philoes[0].av[NUMBER_OF_PHILOES])
			i = 0;
		if (s->philoes[i].av[MUST_EAT] == -1)
			if (++finished_philo >= s->philoes[i].av[NUMBER_OF_PHILOES])
				break ;
		if (gettime(s->philoes[i].last_eat_time) >= s->philoes[0].av[TIME_TO_DIE])
		{
			printf("%d is died\n", i + 1);
			while (++j < s->philoes[i].av[NUMBER_OF_PHILOES])
				pthread_detach(s->threads[j]);
			break ;
		}
	}
}

int	*input_check(int argc, char **argv)
{
	int	*av;
	int	i;

	if (argc != 5 && argc != 6)
		return (INPUT_ERROR);
	av = malloc(sizeof(int) * 5);
	i = argc - 1;
	while (--i >= 0)
	{
		av[i] = ft_atoi(argv[i + 1]);
		if (av[i] < 1)
			return (INPUT_ERROR);
	}
	if (argc == 5)
		av[MUST_EAT] = -2;
	return (av);
}

int	main(int argc, char **argv)
{
	t_status	*status;
	int			*av;
	int			i;

	av = input_check(argc, argv);
	if (av == INPUT_ERROR)
		return (1);
	status = malloc(sizeof(t_status));
	status->real_mutex_fork = malloc(sizeof(pthread_mutex_t) * av[0]);
	status->threads = malloc(sizeof(pthread_t) * av[0] + 1);
	status->philoes = malloc(sizeof(t_philo) * av[0]);
	i = -1;
	while (++i < av[0])
		pthread_mutex_init(&status->real_mutex_fork[i], 0);
	while (--i >= 0)
	{
		status->philoes[i].mutex_forks = status->real_mutex_fork;
		status->philoes[i].no = i;
		ft_cpy(status->philoes[i].av, av);
		status->philoes[i].start_time = gettime(0);
		status->philoes[i].last_eat_time = status->philoes[i].start_time;
		pthread_create(&status->threads[i], 0, start_thread, &status->philoes[i]);
	}
	monitoring(status);
	while (++i < av[0])
		pthread_join(status->threads[i], 0);
}
