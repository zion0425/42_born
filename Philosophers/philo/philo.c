/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/08/16 17:21:32 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork(t_philo p, int *first_fork, int *second_fork, int *no)
{
	*first_fork = p.no % 2;
	*second_fork = (*first_fork - 1) * -1;
	no[LEFT_FORK] = p.no - 1;
	no[RIGHT_FORK] = p.no;
	if (no[LEFT_FORK] <= -1)
		no[RIGHT_FORK] = p.av[NUMBER_OF_PHILOES] - 1;
}

void	*start_thread(void *philo)
{
	t_philo	p;
	int		no[2];
	int		first_fork;
	int		second_fork;

	p = *(t_philo *)philo;
	set_fork(p, &first_fork, &second_fork, no);
	p.start_time = gettime(0);
	while (p.av[MUST_EAT]--)
	{
		pthread_mutex_lock(&p.mutex_forks[no[first_fork]]);
		printf("%ldms : %d has taken a fork\n", gettime(p.start_time), p.no + 1);
		pthread_mutex_lock(&p.mutex_forks[no[second_fork]]);
		printf("%ldms : %d has taken a fork\n", gettime(p.start_time), p.no + 1);
		printf("%ldms : %d is eating\n", gettime(p.start_time), p.no + 1);
		p.last_eat_time -= p.av[TIME_TO_EAT] * 1000;
		usleep(p.av[TIME_TO_EAT] * 1000);
		p.last_eat_time = gettime(p.start_time);
		pthread_mutex_unlock(&p.mutex_forks[no[first_fork]]);
		pthread_mutex_unlock(&p.mutex_forks[no[second_fork]]);
		printf("%ldms : %d is sleeping\n", gettime(p.start_time), p.no + 1);
		usleep(p.av[TIME_TO_SLEEP] * 1000);
		printf("%ldms : %d is thinking\n", gettime(p.start_time), p.no + 1);
	}
	return (0);
}

void	*monitoring(void *philo)
{
	t_philo *p;
	int	i;
	//int	num;

	i = 0;
	p = (t_philo *)philo;
	//while (p.isfinish != '0')
	//{

	//	if (p.philoes[i].last_eat_time <= 0)
	//	{
	//		i = 0;
	//		while (i < num)
	//		{
	//			pthread_detach(p.threads[i++]);
	//		}

	//		return (0);
	//	}
	//	i++;
	//	if (i == num)
	//		i = 0;
	//}
	return (0);
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
		av[MUST_EAT] = -1;
	return (av);
}

int	main(int argc, char **argv)
{
	t_status	status;
	t_philo		*philo;
	int			*av;
	int			i;

	av = input_check(argc, argv);
	if (av == INPUT_ERROR)
		return (1);
	status.real_mutex_fork = malloc(sizeof(pthread_mutex_t) * av[0]);
	status.threads = malloc(sizeof(pthread_t) * av[0] + 1);
	philo = malloc(sizeof(t_philo) * av[0]);
	status.philoes = philo;
	i = -1;
	while (++i < av[0])
		pthread_mutex_init(&status.real_mutex_fork[i], 0);
	while (--i >= 0)
	{
		philo[i].mutex_forks = status.real_mutex_fork;
		philo[i].no = i;
		ft_cpy(philo[i].av, av);
		philo[i].last_eat_time = av[TIME_TO_EAT];
		pthread_create(&status.threads[i], 0, start_thread, &philo[i]);
		//pthread_create(&status.threads[i], 0, monitoring, &philo[i]);
	}
	//for (int i = 0; i < av[0]; i++)
	//	pthread_detach(status.threads[i]);
	while (++i < av[0])
		pthread_join(status.threads[i], 0);
	pthread_join(status.threads[av[0]], 0);
}
