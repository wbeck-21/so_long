/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:29:49 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/18 23:20:37 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_err_msg(char *err)
{
	write(2, "Error: ", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
}

void	print_act(t_data *data, int philo_id, char *msg)
{
	pthread_mutex_lock(&(data->mutex.write_mutex));
	if (!(data->is_dead))
	{
		printf("%lli ", moment() - data->first_time);
		printf("%d ", philo_id + 1);
		printf("%s\n", msg);
	}
	pthread_mutex_unlock(&(data->mutex.write_mutex));
	return ;
}
