/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:52:26 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/04 20:12:53 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	map_width(t_base *base, char *map_text)
{
	while (map_text[base->width] && map_text[base->width] != '\n')
		base->width++;
	if (!base->width)
	{
		free(map_text);
		exit_game(base, ERROR_INVALID_MAP_3);
	}
}

void	map_height(t_base *base, char *map_text)
{
	int	i;
	int	j;

	if (base->width)
	{
		i = 0;
		while (map_text[i])
		{
			j = 0;
			while (map_text[i + j] && map_text[i + j] != '\n')
				j++;
			if (j != base->width)
			{
				free(map_text);
				exit_game(0, ERROR_INVALID_MAP_4);
			}
			i += base->width + 1;
			base->height++;
		}
	}
}
