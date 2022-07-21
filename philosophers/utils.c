/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:27:24 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/20 23:53:29 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * minus);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	moment(void) //почитать
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	destroy_mutex(t_data *data, t_philosopher *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_amount)
		pthread_join(philo[i].thread_id, NULL);
	i = data->philo_amount;
	while (--i >= 0)
		pthread_mutex_destroy(&(data->mutex.forks_mutex[i]));
	pthread_mutex_destroy(&(data->mutex.write_mutex));
	pthread_mutex_destroy(&(data->mutex.meal_mutex));
}
