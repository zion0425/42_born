/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:31:00 by siokim            #+#    #+#             */
/*   Updated: 2022/07/30 18:35:53 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>

typedef struct s_phlio
{
	char	fork[2];
}	t_phlio;

typedef struct s_status
{
	pthread_mutex_t	mutex;
	char			*forks;
	t_phlio			phlios;
}	t_status;

#endif
