/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:31:00 by siokim            #+#    #+#             */
/*   Updated: 2022/08/10 18:59:08 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

# define INPUT_ERROR 0
# define NUMBER_OF_PHILOES 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define MUST_EAT 4
# define LEFT_FORK 0
# define RIGHT_FORK 1

typedef struct s_philo
{
	int				no;
	int				*av;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_print;
	long		start_time;
	long		last_eat_time;
}	t_philo;

typedef struct s_status
{
	pthread_t		*threads;
	pthread_mutex_t	*real_mutex_fork;
	pthread_mutex_t	*real_mutex_print;
	t_philo	*philoes;
	char	isfinish;
}	t_status;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int    *ft_cpy(int *src, int argc);

#endif
