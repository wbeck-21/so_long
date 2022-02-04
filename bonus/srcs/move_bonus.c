/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:52:33 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 18:52:34 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	up(t_base *base, int x, int y)
{
	if (base->map[x - 1][y] != '1')
		base->position_p.x -= 1;
}

void	down(t_base *base, int x, int y)
{
	if (base->map[x + 1][y] != '1')
		base->position_p.x += 1;
}

void	left(t_base *base, int x, int y)
{
	if (base->map[x][y - 1] != '1')
		base->position_p.y -= 1;
}

void	right(t_base *base, int x, int y)
{
	if (base->map[x][y + 1] != '1')
		base->position_p.y += 1;
}
