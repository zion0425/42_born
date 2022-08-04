/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:31:00 by siokim            #+#    #+#             */
/*   Updated: 2022/08/04 19:23:04 by siokim           ###   ########.fr       */
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

typedef struct s_status
{
	pthread_t		*threads;
	long			now_time;
}	t_status;

typedef struct s_philo
{
	int				no;
	int				*av;
	pthread_mutex_t	*mutex_forks;

}	t_philo;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
