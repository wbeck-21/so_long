/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:51:20 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:19:48 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_map(t_base *base)
{
	int	i;

	if (base->map != 0)
	{
		i = 0;
		while (i < base->height)
			free(base->map[i++]);
		free(base->map);
	}
	free(base);
}

static void	destroy_images(t_base *base)
{
	if (base->img_1 != 0)
		mlx_destroy_image(base->mlx, base->img_1);
	if (base->img_0 != 0)
		mlx_destroy_image(base->mlx, base->img_0);
	if (base->img_c != 0)
		mlx_destroy_image(base->mlx, base->img_c);
	if (base->img_e != 0)
		mlx_destroy_image(base->mlx, base->img_e);
	if (base->img_p != 0)
		mlx_destroy_image(base->mlx, base->img_p);
	if (base->image != 0)
		mlx_destroy_image(base->mlx, base->image);
}

void	exit_game(t_base *base, char *error)
{
	if (error)
		ft_putstr_fd(error, 1);
	if (base != 0)
	{
		destroy_images(base);
		if (base->window != 0)
			mlx_destroy_window(base->mlx, base->window);
		if (base->mlx != 0)
			mlx_destroy_display(base->mlx);
		if (base->position_c != 0)
			free(base->position_c);
		free_map(base);
	}
	exit(0);
}
