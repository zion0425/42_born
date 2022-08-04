/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:44:32 by siokim            #+#    #+#             */
/*   Updated: 2022/08/04 15:25:39 by siokim           ###   ########.fr       */
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

// void	*create_philo(void *status)
// {
// 	philo_idx = (t_status)status.forks;
// 	take_left_fork(philo_idx);

// 	take_right_fork();

// 	go_to_bed();
// }

/*
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_die;
	int				number_of_times_each_philosopher_must_eat;
*/
int ft_atoi(const char *str)
{
    int sign;
    int result;

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

int	*input_check(int argc, char **argv)
{	
	int	*av;
	int	i;

	av = malloc(sizeof(int) * argc);
	i = argc;
	while (--i >= 0)
	{
		av[i] = ft_atoi(argv[i+1]);
		if (av[i] < 1)
			exit(1);
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

	av = input_check(argc, argv);
	forks = malloc(sizeof(pthread_mutex_t) * av[0]);
	threads = malloc(sizeof(pthread_t) * av[0]);
	philo = malloc(sizeof(t_philo) * av[0]);
	philo->av = av;

	i = -1;
	while (++i < av[0])
		pthread_mutex_init(&forks[i], 0);
		
	
	// while (i < forks)
	// 	pthread_create(&thread[i], 0, take_left_fork, status);
	
	// while ()
	// pthread_join(thread1, 0);
	// pthread_join(thread2, 0);
	// printf("end");
}