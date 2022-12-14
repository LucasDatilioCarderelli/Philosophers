/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:46:53 by ldatilio          #+#    #+#             */
/*   Updated: 2022/10/14 04:36:12 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int				id;
	int				count_of_eat;
	long long		last_time_eat;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_data			*data;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	int				dead;
	long long		start_time;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	printer_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	eat_time_mutex;
	t_philo			*philo;
}	t_data;

void		create_llist(t_data *data);
void		free_llist(t_philo **philo);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
long long	get_time(void);

void		death_checker(t_data *data);
int			check_dead(t_data *data);
int			check_eat_mutex(t_philo *philo);

void		philo_fork_lock(t_philo *philo);
void		philo_fork_unlock(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		thread_init(t_data *data);

#endif
