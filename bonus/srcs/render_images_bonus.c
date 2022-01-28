#include "../include/so_long_bonus.h"

static void	init_enemy_sprites(t_base *base)
{
	int		width;
	int		height;
	t_enemy	*enemy;
	void	**enemy_sprites;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		exit_game(base, "Error\n init_enemy_sprites(): enemy malloc()\n");
	enemy->sprite_index = 0;
	base->enemy = enemy;
	enemy_sprites = malloc(sizeof(void *) * 1);
	if (!enemy_sprites)
		exit_game(base, "Error\n init_enemy_sprites(): enemy_sprites malloc()\n");
	enemy->sprites = enemy_sprites;
	enemy->sprites[0] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_0.xpm", &width, &height);
	enemy->sprites[1] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_1.xpm", &width, &height);
	enemy->sprites[2] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_2.xpm", &width, &height);
	enemy->sprites[3] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_3.xpm", &width, &height);
	enemy->sprites[4] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_4.xpm", &width, &height);
	enemy->sprites[5] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_5.xpm", &width, &height);
	enemy->sprites[6] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_6.xpm", &width, &height);
	enemy->sprites[7] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_7.xpm", &width, &height);
	enemy->sprites[8] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_8.xpm", &width, &height);
	enemy->sprites[9] = mlx_xpm_file_to_image(base->mlx, "./bonus/img/enemy/lava_9.xpm", &width, &height);
}


void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
	    exit_game(base, "Error\n xpm_to_image(): mlx_xpm_file_to_image()\n");
	(*image)->width = width;
	(*image)->height = height;
}

void	render_images(t_base *base)
{
	xpm_to_image(base, &base->img_p, "./bonus/img/player-5.xpm");
	xpm_to_image(base, &base->img_c, "./bonus/img/collect-item-5.xpm");
	xpm_to_image(base, &base->img_1, "./bonus/img/wall-5.xpm");
	xpm_to_image(base, &base->img_0, "./bonus/img/empty-5.xpm");
	xpm_to_image(base, &base->img_e, "./bonus/img/exit-5.xpm");
	// xpm_to_image(base, &base->img_o, "./bonus/img/enemy/lava_5.xpm");
	init_enemy_sprites(base);
}
