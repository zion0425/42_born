/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/08/04 19:45:18 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*take_left_fork(int data)
// {
// 	pthread_mutex_lock(lock);
// }

// void	*take_right_fork(int data)
// {
// 	pthread_mutex_lock(lock);
	
// }

 void	*start_thread(void *p)
{
	t_philo philo;
	int		no[2];

	philo = *(t_philo *)p;
	no[RIGHT_FORK] = philo.no;
	no[LEFT_FORK] = philo.no - 1;
	if (no[LEFT_FORK] <= -1)
		no[LEFT_FORK] = philo.av[NUMBER_OF_PHILOES] - 1;
	printf("%d이 지니고 있는 왼쪽 포크 %d \n", philo.no, no[LEFT_FORK]);
	printf("%d이 지니고 있는 오른쪽 포크 %d \n", philo.no, no[RIGHT_FORK]);

	if (philo.no == philo.av[NUMBER_OF_PHILOES] - 1)
	{
		pthread_mutex_lock(&philo.mutex_forks[no[RIGHT_FORK]]);
		printf("%d가 오른쪽 포크를 집었습니다.\n", philo.no);
		pthread_mutex_lock(&philo.mutex_forks[no[LEFT_FORK]]);
		printf("%d가 왼쪽 포크를 집었습니다.\n", philo.no);

	}
	else
	{
		pthread_mutex_lock(&philo.mutex_forks[no[LEFT_FORK]]);
		printf("%d가 왼쪽 포크를 집었습니다. \n", philo.no);
		pthread_mutex_lock(&philo.mutex_forks[no[RIGHT_FORK]]);
		printf("%d가 오른쪽 포크를 집었습니다.\n", philo.no);
		printf("%d : 식사중\n", philo.no);
	}
	printf("%d : 식사 종료\n", philo.no);
	pthread_mutex_unlock(&philo.mutex_forks[no[RIGHT_FORK]]);
	pthread_mutex_unlock(&philo.mutex_forks[no[LEFT_FORK]]);
	return (0);
}

int	*input_check(int argc, char **argv)
{	
	int	*av;
	int	i;

	av = malloc(sizeof(int) * argc);
	i = argc - 1;
	while (--i >= 0)
	{
		av[i] = ft_atoi(argv[i + 1]);
		if (av[i] < 1)
			return (INPUT_ERROR);
	}
	return (av);
}

int main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
    pthread_t		*threads;
	t_philo			*philo;
	int				*av;
	int				i;

	if (argc != 5 && argc != 6)
		return (1);
	av = input_check(argc, argv);
	if (av == INPUT_ERROR)
		return (1);
	forks = malloc(sizeof(pthread_mutex_t) * av[0]);
	threads = malloc(sizeof(pthread_t) * av[0]);
	philo = malloc(sizeof(t_philo) * av[0]);
	i = -1;
	while (++i < av[0])
		pthread_mutex_init(&forks[i], 0);
	while (--i >= 0)
	{
		philo[i].mutex_forks = forks;
		philo[i].no = i;
		philo[i].av = av;
		pthread_create(&threads[i], 0, start_thread, &philo[i]);
	}
	
	while (++i < av[0])
		pthread_join(threads[i], 0);


}