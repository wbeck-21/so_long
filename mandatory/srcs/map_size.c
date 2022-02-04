/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:26:39 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 21:26:46 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
				exit_game(base, ERROR_INVALID_MAP_4);
			}
			i += base->width + 1;
			base->height++;
		}
	}
}
