/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:31:41 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/04 20:50:20 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	catch_c(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->count_c)
	{
		if (base->position_p.x == base->position_c[i].x
			&& base->position_p.y == base->position_c[i].y)
		{
			base->position_c[i].x = -1;
			base->position_c[i].y = -1;
			base->catch_c = base->catch_c + 1;
		}
		i++;
	}
}

static void	conditions_exit_game(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->count_e)
	{
		if (base->position_p.x == base->position_e[i].x
			&& base->position_p.y == base->position_e[i].y
			&& base->catch_c == base->count_c)
		{
			ft_putstr_fd("YOU WIN!\n", 1);
			exit_game(base, 0);
		}
		i++;
	}
}

void	update(t_base *base)
{
	int				x;
	int				y;

	x = base->position_p.x;
	y = base->position_p.y;
	if (base->up != 0)
		up(base, x, y);
	else if (base->down != 0)
		down(base, x, y);
	else if (base->left != 0)
		left(base, x, y);
	else if (base->right != 0)
		right(base, x, y);
	if (base->position_p.x != x || base->position_p.y != y)
		base->step++;
	catch_c(base);
	create_map(base);
	conditions_exit_game(base);
}
