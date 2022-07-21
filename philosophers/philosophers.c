/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:20:55 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/21 23:34:16 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			i++;
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_args(char **argv)
{
	if (!is_valid_arg(argv[1]))
		return (0);
	if (!is_valid_arg(argv[2]))
		return (0);
	if (!is_valid_arg(argv[3]))
		return (0);
	if (!is_valid_arg(argv[4]))
		return (0);
	if (argv[5])
	{
		if (!is_valid_arg(argv[5]))
			return (0);
	}
	return (1);
}

void	*process(void *void_ph)
{
	t_philosopher	*philo;
	t_data			*data;

	philo = (t_philosopher *)void_ph;
	data = philo->data;
	if (philo->id % 2)
		usleep(100);
	while (!(data->is_dead) && !(data->amount_fed_philo))
	{
		if (data->amount_fed_philo)
			break ;
		eating(data, philo);
		if (data->amount_fed_philo)
			break ;
		print_act(data, philo->id, "is sleeping");
		thinking(data, data->sleep_timer);
		print_act(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	threads_process(t_data *data)
{
	t_philosopher	*philo;
	int				i;

	philo = data->philosophers;
	i = 0;
	data->first_time = moment();
	while (i < data->philo_amount)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, process, &(philo[i])))
			return ;
		philo[i].last_meal_timer = moment();
		i++;
	}
	is_dead(data, philo);
	destroy_mutex(data, philo);
}

int	main(int agrc, char **argv)
{
	t_data	data;

	if (agrc != 5 && agrc != 6)
	{
		print_err_msg("Wrong amount of arguments!");
		return (-1);
	}
	if (!check_valid_args(argv))
	{
		print_err_msg("Invalid arguments!");
		return (-1);
	}
	if (!init_data(&data, argv))
	{
		print_err_msg("Wrong arguments!");
		return (-1);
	}
	if (!init_mutex(&data))
	{
		print_err_msg("Error of creating mutex!");
		return (-1);
	}
	//printf("%d %d %d %d!!\n", data.philo_amount, data.death_timer, data.eat_timer, data.sleep_timer);
	//sleep(5);
	threads_process(&data);
	return (0);
}
