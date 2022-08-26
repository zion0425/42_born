/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:31:00 by siokim            #+#    #+#             */
/*   Updated: 2022/08/27 00:46:59 by siokim           ###   ########.fr       */
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

# define NUMBER_OF_PHILOES 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define MUST_EAT 4
# define LEFT_FORK 0
# define RIGHT_FORK 1
# define WAIT_TIME_BEFORE_MONITOR 1000

typedef struct s_philo
{
	int				no;
	int				av[5];
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_musteat;
	long			start_time;
	long			last_eat_time;
}	t_philo;

typedef struct s_status
{
	pthread_t		*threads;
	pthread_mutex_t	*real_mutex_fork;
	pthread_mutex_t	*real_mutex_print;
	pthread_mutex_t	*real_mutex_musteat;
	t_philo			*philoes;
	int				finished_philoes;
}	t_status;

t_status	*init_status(int av);
int			ft_atoi(const char *str);
int			*input_check(int argc, char **argv);
void		ft_cpy(int *pav, int *argv);
long		microtomill(struct timeval time);
long		gettime(long start_time);
void		init_philoes(t_status *status, int i, int *av, long start_time);
void		ft_sleep(long wait_time);
void		eating(t_philo *p, int no[2], int first_fork, int second_fork);
int			eat_cnt(t_status *s, int i, int max);
void		print(t_philo *p, char *str, char is_eating);

#endif
