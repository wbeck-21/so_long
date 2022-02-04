/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:52:41 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:18:21 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
		exit_game(base, ERROR_MLX_XPM);
}

static void	init_player_sprites(t_base *base)
{
	int			w;
	int			h;
	void		**player_sprites;
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit_game(base, ERROR_MALLOC_2);
	player->sprite_index = 0;
	base->player = player;
	player_sprites = malloc(sizeof(void *) * 7);
	if (!player_sprites)
		exit_game(base, ERROR_MALLOC_3);
	player->sprites = player_sprites;
	player->sprites[0] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_0, &w, &h);
	player->sprites[1] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_1, &w, &h);
	player->sprites[2] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_2, &w, &h);
	player->sprites[3] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_3, &w, &h);
	player->sprites[4] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_4, &w, &h);
	player->sprites[5] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_5, &w, &h);
	player->sprites[6] = mlx_xpm_file_to_image(base->mlx, IMG_PLAYER_6, &w, &h);
}

void	render_images(t_base *base)
{
	init_player_sprites(base);
	xpm_to_image(base, &base->img_c, "./bonus/img/collect_item.xpm");
	xpm_to_image(base, &base->img_1, "./bonus/img/wall.xpm");
	xpm_to_image(base, &base->img_0, "./bonus/img/empty.xpm");
	xpm_to_image(base, &base->img_e, "./bonus/img/exit.xpm");
	xpm_to_image(base, &base->img_x, "./bonus/img/enemy.xpm");
}
