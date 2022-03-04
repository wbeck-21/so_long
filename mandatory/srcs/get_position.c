/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:17:51 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/04 20:51:59 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_position_extra(t_base *base, int i, int j)
{
	if (base->map[i][j] == 'P')
	{
		base->position_p.x = i;
		base->position_p.y = j;
		base->map[i][j] = '0';
	}
}

void	get_position(t_base *base)
{
	int	i;
	int	j;
	int	k;
	int	m;

	k = -1;
	m = -1;
	i = -1;
	base->position_c = (t_pos *)malloc(sizeof(t_pos) * base->count_c + 1);
	if (!(base->position_c))
		exit_game(base, ERROR_MALLOC_0);
	base->position_e = (t_pos *)malloc(sizeof(t_pos) * base->count_e + 1);
	if (!(base->position_e))
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
			if (base->map[i][j] == 'E')
			{
				base->position_e[++m].x = i;
				base->position_e[m].y = j;
				base->map[i][j] = '0';
			}
			get_position_extra(base, i, j);
		}
	}
}
