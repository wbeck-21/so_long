#include "../include/so_long_bonus.h"

void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
	    exit_game(base, "Error\n xpm_to_image(): mlx_xpm_file_to_image()\n");
	// (*image)->width = width;
	// (*image)->height = height;
	// printf("w - %d h - %d\n", width, height);
}

static void	init_player_sprites(t_base *base)
{
	int		width;
	int		height;
	void	**player_sprites;
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit_game(base, "Error\n");
	player->sprite_index = 0;
	base->player = player;
	player_sprites = malloc(sizeof(void *) * 5);
	if (!player_sprites)
		exit_game(base, "Error\n");
	player->sprites = player_sprites;
	player->sprites[0] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/sprites/player-5_0.xpm", &width, &height);
	player->sprites[1] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/sprites/player-5_1.xpm", &width, &height);
	player->sprites[2] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/sprites/player-5_2.xpm", &width, &height);
	player->sprites[3] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/sprites/player-5_3.xpm", &width, &height);
	player->sprites[4] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/sprites/player-5_4.xpm", &width, &height);
}

void	render_images(t_base *base)
{
	// xpm_to_image(base, &base->img_p, "./bonus/img/player-5.xpm");
	init_player_sprites(base);
	xpm_to_image(base, &base->img_c, "./bonus/img/collect-item-5.xpm");
	xpm_to_image(base, &base->img_1, "./bonus/img/wall-5.xpm");
	xpm_to_image(base, &base->img_0, "./bonus/img/empty-5.xpm");
	xpm_to_image(base, &base->img_e, "./bonus/img/exit-5.xpm");
	xpm_to_image(base, &base->img_x, "./bonus/img/enemy-5.xpm");
}
