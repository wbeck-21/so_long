/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:17:16 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/21 23:27:45 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	cut_moment(int last_meal_timer, long long moment)
{
	return (moment - last_meal_timer);
}

void	is_dead(t_data *data, t_philosopher	*philo)
{
	int	i;

	while (!(data->amount_fed_philo) || !(data->is_dead))
	{
		i = -1;
		while (++i < data->philo_amount && !(data->is_dead))
		{
			pthread_mutex_lock(&(data->mutex.meal_mutex));
			//printf("HERE TIME IS %lli", cut_moment(philo[i].last_meal_timer, moment()));
			if (cut_moment(philo[i].last_meal_timer, moment())
				> data->death_timer)
			{
				print_act(data, i, "is dead");
				data->is_dead = 1;
			}
			pthread_mutex_unlock(&(data->mutex.meal_mutex));
		}
		if (data->is_dead)
			break ;
		i = 0;
		while (!(data->max_meal) && i < data->philo_amount
			&& philo[i].ate >= data->max_meal)
			i++;
		if (i == data->philo_amount)
			data->amount_fed_philo = 1;
	}
}

void	thinking(t_data *data, long long time)
{
	long long	i;

	i = moment();
	while (!(data->is_dead))
	{
		if (cut_moment(i, moment()) >= time)
			break ;
		usleep(50);
	}
}

void	eating(t_data *data, t_philosopher	*philo)
{
	if (philo->left_fork_id > philo->right_fork_id)
	{
		pthread_mutex_lock(&(data->mutex.forks_mutex[philo->right_fork_id]));
		print_act(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&(data->mutex.forks_mutex[philo->left_fork_id]));
		print_act(data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(data->mutex.forks_mutex[philo->left_fork_id]));
		print_act(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&(data->mutex.forks_mutex[philo->right_fork_id]));
		print_act(data, philo->id, "has taken a fork");
	}
	print_act(data, philo->id, "is eating");
	philo->last_meal_timer = moment();
	thinking(data, data->eat_timer);
	(philo->ate)++;
	pthread_mutex_unlock(&(data->mutex.forks_mutex[philo->left_fork_id]));
	pthread_mutex_unlock(&(data->mutex.forks_mutex[philo->right_fork_id]));
}
