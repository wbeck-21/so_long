/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:28:19 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/21 00:07:37 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	pthread_t		thread_id;
	int				id;
	int				ate;
	int				last_meal_timer;
	int				left_fork_id;
	int				right_fork_id;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_mutex
{
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	forks_mutex[250];
}	t_mutex;

typedef struct s_data
{
	long long		first_time;
	int				death_timer;
	int				eat_timer;
	int				sleep_timer;
	int				philo_amount;
	int				max_meal;
	int				is_dead;
	int				amount_fed_philo;
	t_philosopher	philosophers[250];
	t_mutex			mutex;
}	t_data;

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
long long	moment(void);

int			init_data(t_data *data, char **argv);
int			init_mutex(t_data *data);
void		destroy_mutex(t_data *data, t_philosopher *philo);

void		eating(t_data *data, t_philosopher *philo);
void		is_dead(t_data *data, t_philosopher	*philo);
void		thinking(t_data *data, long long time);

void		print_err_msg(char *err);
void		print_act(t_data *data, int philo_id, char *msg);

#endif