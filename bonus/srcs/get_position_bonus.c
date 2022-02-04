/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:39:59 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:11:30 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	get_position_extra(t_base *base, int i, int j)
{
	if (base->map[i][j] == 'P')
	{
		base->position_p.x = i;
		base->position_p.y = j;
		base->map[i][j] = '0';
	}
	if (base->map[i][j] == 'E')
	{
		base->position_e.x = i;
		base->position_e.y = j;
		base->map[i][j] = '0';
	}
	if (base->map[i][j] == 'X')
	{
		base->position_x.x = i;
		base->position_x.y = j;
		base->map[i][j] = '0';
	}
}

void	get_position(t_base *base)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	base->position_c = (t_pos *)malloc(sizeof(t_pos) * base->count_c + 1);
	if (!(base->position_c))
		exit_game(base, ERROR_MALLOC_0);
	while (++i < base->height)
	{
		j = -1;
		while (++j < base->width)
		{
			if (base->map[i][j] == 'C')
			{
				base->position_c[++k].x = i;
				base->position_c[k].y = j;
				base->map[i][j] = '0';
			}
			get_position_extra(base, i, j);
		}
	}
}
