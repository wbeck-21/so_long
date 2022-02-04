/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:39:46 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 18:51:38 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	animate_player(t_base *base)
{
	void	*img;
	int		i;
	int		j;

	if (base->player->sprite_index == 6)
		base->player->sprite_index = 0;
	else
		base->player->sprite_index++;
	img = base->player->sprites[base->player->sprite_index];
	i = 0;
	while (base->map[i])
	{
		j = 0;
		while (base->map[i][j])
		{
			if (base->position_p.x == i && base->position_p.y == j)
				mlx_put_image_to_window(base->mlx, base->window,
					img, j * 40, i * 40);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_steps(t_base *base)
{
	char	*steps;
	char	*res;

	steps = ft_itoa(base->step);
	res = ft_strjoin("Steps: ", steps);
	mlx_string_put(base->mlx, base->window, 5, 10, 0x0000FF00, res);
	free(steps);
	free(res);
}

int	key_press(int key, t_base *base)
{
	if (key == 65307)
		exit_game(base, 0);
	if (key == 119)
		base->up = 1;
	if (key == 115)
		base->down = 1;
	if (key == 97)
		base->left = 1;
	if (key == 100)
		base->right = 1;
	update(base);
	return (0);
}

int	key_release(int key, t_base *base)
{
	if (key == 119)
		base->up = 0;
	if (key == 115)
		base->down = 0;
	if (key == 97)
		base->left = 0;
	if (key == 100)
		base->right = 0;
	update(base);
	return (0);
}

int	destroy_notify(t_base *base)
{
	(void)base;
	exit_game(0, 0);
	return (0);
}
