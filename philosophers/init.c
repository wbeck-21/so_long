/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:01:14 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/17 20:12:44 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philo_amount)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].ate = 0;
		data->philosophers[i].last_meal_timer = 0;
		data->philosophers[i].left_fork_id = i;
		data->philosophers[i].right_fork_id = (i + 1) % data->philo_amount;
		data->philosophers[i].data = data;
	}
}

int	init_data(t_data *data, char **argv)
{
	data->philo_amount = ft_atoi(argv[1]);
	data->death_timer = ft_atoi(argv[2]);
	data->eat_timer = ft_atoi(argv[3]);
	data->sleep_timer = ft_atoi(argv[4]);
	if ((data->philo_amount < 1 || data->philo_amount > 250)
		|| data->death_timer < 0 || data->eat_timer < 0
		|| data->sleep_timer < 0)
		return (0);
	data->max_meal = 0;
	if (argv[5])
	{
		data->max_meal = ft_atoi(argv[5]);
		if (data->max_meal < 1)
			return (0);
	}
	init_philosophers(data);
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philo_amount)
	{
		if (pthread_mutex_init(&(data->mutex.forks_mutex[i]), NULL))
			return (0);
	}
	if (pthread_mutex_init(&(data->mutex.write_mutex), NULL))
		return (0);
	if (pthread_mutex_init(&(data->mutex.meal_mutex), NULL))
		return (0);
	return (1);
}
