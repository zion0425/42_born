/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/08/11 16:31:40 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
void	*start_thread2(void *philo)
{
	t_philo p;
	struct timeval		time;
	int		no[2];

	p = *(t_philo *)philo;
	no[RIGHT_FORK] = p.no;
	no[LEFT_FORK] = p.no - 1;
	if (no[LEFT_FORK] <= -1)
		no[LEFT_FORK] = p.av[NUMBER_OF_PHILOES] - 1;
	gettimeofday(&time, 0);
	p.start_time = microtomill(time);
	while (p.av[MUST_EAT]--){
		pthread_mutex_lock(&p.mutex_forks[no[RIGHT_FORK]]);
		printf("%ldms : %d 오른쪽 포크.\n",gettime(p.start_time), p.no + 1);
		pthread_mutex_lock(&p.mutex_forks[no[LEFT_FORK]]);
		printf("%ldms : %d 왼쪽 포크.\n",gettime(p.start_time), p.no + 1);
		printf("%ldms : %d 식사중\n",gettime(p.start_time), p.no + 1);
		p.last_eat_time -= p.av[TIME_TO_EAT] * 1000;
		usleep(p.av[TIME_TO_EAT] * 1000);
		p.last_eat_time = gettime(p.start_time);
		printf("%ldms : %d 식사 종료\n",p.last_eat_time, p.no + 1);
		pthread_mutex_unlock(&p.mutex_forks[no[RIGHT_FORK]]);
		pthread_mutex_unlock(&p.mutex_forks[no[LEFT_FORK]]);
		printf("%ldms : %d 취침\n",gettime(p.start_time), p.no + 1);
		usleep(p.av[TIME_TO_SLEEP] * 1000);
		printf("%ldms : %d 생각중\n",gettime(p.start_time), p.no + 1);
	}
	return (0);
}

void	*start_thread(void *philo)
{
	t_philo p;
	struct timeval		time;
	int		no[2];

	p = *(t_philo *)philo;
	no[RIGHT_FORK] = p.no;
	no[LEFT_FORK] = p.no - 1;
	if (no[LEFT_FORK] <= -1)
		no[LEFT_FORK] = p.av[NUMBER_OF_PHILOES] - 1;
	gettimeofday(&time, 0);
	p.start_time = microtomill(time);

	while (p.av[MUST_EAT]--){
		pthread_mutex_lock(&p.mutex_forks[no[LEFT_FORK]]);
		printf("%ldms : %d 왼쪽 포크.\n",gettime(p.start_time), p.no + 1);
		pthread_mutex_lock(&p.mutex_forks[no[RIGHT_FORK]]);
		printf("%ldms : %d 오른쪽 포크.\n",gettime(p.start_time), p.no + 1);
		printf("%ldms : %d 식사중\n",gettime(p.start_time), p.no + 1);
		p.last_eat_time -= p.av[TIME_TO_EAT] * 1000;
		usleep(p.av[TIME_TO_EAT] * 1000);
		p.last_eat_time = gettime(p.start_time);
		printf("%ldms : %d 식사 종료\n",p.last_eat_time, p.no + 1);
		pthread_mutex_unlock(&p.mutex_forks[no[LEFT_FORK]]);
		pthread_mutex_unlock(&p.mutex_forks[no[RIGHT_FORK]]);
		printf("%ldms : %d 취침\n",gettime(p.start_time), p.no + 1);
		usleep(p.av[TIME_TO_SLEEP] * 1000);
		printf("%ldms : %d 생각중\n",gettime(p.start_time), p.no + 1);
	}
	return (0);
}

int	*input_check(int argc, char **argv)
{
	int	*av;
	int	i;

	av = malloc(sizeof(int) * argc);
	i = argc - 1;
	if (argc == 5)
		av[MUST_EAT] = -1;
	while (--i >= 0)
	{
		av[i] = ft_atoi(argv[i + 1]);
		if (av[i] < 1)
			return (INPUT_ERROR);
	}
	return (av);
}

void	*monitoring(void *status)
{
	struct timeval		time;
	t_status s;
	int	i;
	long	t;
	int	num;


	i = 0;
	s = *(t_status *)status;
	num = s.philoes[0].av[NUMBER_OF_PHILOES];

	while (s.isfinish != '0')
	{
		gettimeofday(&time, 0);
		t = microtomill(time);
		if (t - s.philoes[i].av[TIME_TO_DIE] <= 0)
		{
			i = 0;
			while (i < num)
				pthread_detach(s.threads[i]);
			return (0);
		}
		if (i == num)
			i = 0;
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_status			status;
	t_philo			*philo;
	int				*av;
	int				i;

	if (argc != 5 && argc != 6)
		return (1);

	av = input_check(argc, argv);
	if (av == INPUT_ERROR)
		return (1);
	status.real_mutex_fork = malloc(sizeof(pthread_mutex_t) * av[0]);
	status.threads = malloc(sizeof(pthread_t) * av[0] + 1);
	philo = malloc(sizeof(t_philo) * av[0]);
	status.philoes = philo;
	//status.isfinish = '1';
	i = -1;
	while (++i < av[0])
		pthread_mutex_init(&status.real_mutex_fork[i], 0);

	while (--i >= 0)
	{
		philo[i].mutex_forks = status.real_mutex_fork;
		philo[i].no = i;
		philo[i].av = ft_cpy(av, argc);
		philo[i].last_eat_time = 0;
		if (i % 2 == 0)
			pthread_create(&status.threads[i], 0, start_thread, &philo[i]);
		else
			pthread_create(&status.threads[i], 0, start_thread2, &philo[i]);
	}
	pthread_create(&status.threads[av[NUMBER_OF_PHILOES]], 0, monitoring, &status);
	while (++i < av[0])
		pthread_join(status.threads[i], 0);
	//status.isfinish = '0';
	pthread_join(status.threads[av[0]], 0);
}
