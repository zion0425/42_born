/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/07/30 18:50:31 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*take_left_fork(int data)
{
	pthread_mutex_lock(lock);
}

void	*take_right_fork(int data)
{
	pthread_mutex_lock(lock);
	
}

void	*create_philo(void *status)
{
	philo_idx = (t_status)status.forks;
	take_left_fork(philo_idx);

	take_right_fork();

	go_to_bed();
}

int main(int argc, char **argv)
{
	t_status	status;
    pthread threads[2];
	int	forks;

	forks = atoi(argv[1]);
	status.forks = malloc(sizeof(forks) + 1);
	status.forks[forks] = 0;

	pthread_mutex_init(&status.mutex, 0);
	for (int i = 0; i < forks; i++)
		status.forks[i] = '0';
	
	while (i < forks)
		pthread_create(&thread[i], 0, take_left_fork, status);
	
	while ()
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	printf("end");
}