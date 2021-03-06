/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:39:53 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:11:16 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	free_player(t_base *base)
{
	int	i;

	i = -1;
	while (++i < 7)
		if (base->player->sprites[i] != 0)
			mlx_destroy_image(base->mlx, base->player->sprites[i]);
	if (base->player)
	{
		if (base->player->sprites)
			free(base->player->sprites);
		free(base->player);
	}
	return (0);
}

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
	if (base->img_x != 0)
		mlx_destroy_image(base->mlx, base->img_x);
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
		free_player(base);
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
