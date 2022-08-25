/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/08/26 00:42:07 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *p, char *str, char is_eating)
{
	pthread_mutex_lock(p->mutex_print);
	printf("%ldms\t%d %s\n", gettime(p->start_time), p->no + 1, str);
	if (is_eating == '1')
		p->last_eat_time = gettime(0);
	pthread_mutex_unlock(p->mutex_print);
}

void	set_fork(t_philo *p, int *first_fork, int *second_fork, int *no)
{
	*first_fork = p->no % 2;
	*second_fork = (*first_fork - 1) * -1;
	no[LEFT_FORK] = p->no;
	no[RIGHT_FORK] = p->no + 1;
	if (no[RIGHT_FORK] == p->av[NUMBER_OF_PHILOES])
		no[RIGHT_FORK] = 0;
	if (*first_fork == 1)
		usleep(100);
}

void	*start_thread(void *philo)
{
	t_philo	*p;
	int		no[2];
	int		first_fork;
	int		second_fork;

	p = (t_philo *)philo;
	set_fork(p, &first_fork, &second_fork, no);
	while (p->av[MUST_EAT]--)
	{
		pthread_mutex_lock(&p->mutex_forks[no[first_fork]]);
		print(p, "has taken a fork", '0');
		pthread_mutex_lock(&p->mutex_forks[no[second_fork]]);
		print(p, "has taken a fork", '0');
		print(p, "has eating", '1');
		ft_sleep(p->av[TIME_TO_EAT]);
		pthread_mutex_unlock(&p->mutex_forks[no[second_fork]]);
		pthread_mutex_unlock(&p->mutex_forks[no[first_fork]]);
		print(p, "has sleeping", '0');
		ft_sleep(p->av[TIME_TO_SLEEP]);
		print(p, "has thinking", '0');
		usleep(200);
	}
	return ((void *)0);
}

void	monitoring(t_status *s)
{
	int	i;
	int	finished_philo;

	i = -1;
	finished_philo = 0;
	while (++i <= s->philoes[0].av[NUMBER_OF_PHILOES])
	{
		if (i == s->philoes[0].av[NUMBER_OF_PHILOES])
			i = 0;
		if (s->philoes[i].av[MUST_EAT] == -1)
			if (++finished_philo >= s->philoes[i].av[NUMBER_OF_PHILOES])
				break ;
		pthread_mutex_lock(s->real_mutex_print);
		if (gettime(s->philoes[i].last_eat_time) \
		>= s->philoes[0].av[TIME_TO_DIE])
		{
			printf("%ldms\t%d is died\n", \
			gettime(s->philoes[i].start_time), i + 1);
			while (--(s->philoes[i].av[NUMBER_OF_PHILOES]) >= 0)
				pthread_detach(s->threads[s->philoes[i].av[NUMBER_OF_PHILOES]]);
			break ;
		}
		pthread_mutex_unlock(s->real_mutex_print);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	t_status	*status;
	int			*av;
	int			i;
	long		start_time;

	av = input_check(argc, argv);
	if (!av)
		return (1);
	status = init_status(av[0]);
	if (!status)
		return (1);
	i = -1;
	start_time = gettime(0);
	while (++i < av[0])
	{
		init_philoes(status, i, av, start_time);
		pthread_create(&status->threads[i], \
		0, start_thread, &status->philoes[i]);
	}
	monitoring(status);
}
