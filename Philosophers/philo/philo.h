/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:31:00 by siokim            #+#    #+#             */
/*   Updated: 2022/08/04 15:23:48 by siokim           ###   ########.fr       */
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

# define INPUT_ERROR 1

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

#endif