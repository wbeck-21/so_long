#include "../include/so_long.h"

void	render_init(t_base *base)
{
	base->mlx = mlx_init();
	if (!base->mlx)
	    exit_game(base);
	base->window = mlx_new_window(base->mlx, base->width * 40, base->height * 40, "so_long");
	if (!base->window)
	    exit_game(base);
	base->image = mlx_new_image(base->mlx, base->width * 40, base->height * 40);
	if (!base->image)
        exit_game(base);
}

t_base *base_init(char *map_file) // проверь потом, можно ли передать из мейна *base
{
	t_base *base;
    (void) map_file;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	    exit_game(base);
	base->mlx = 0;
	base->window = 0;
	base->image = 0;
    base->map = 0;
    base->width = 0;
    base->height = 0;
    base->count_p = 0;
    base->count_c = 0;
    base->count_e = 0;
	base->img_p = 0;
    base->img_c = 0;
    base->img_e = 0;
	base->img_1 = 0;
    base->img_0 = 0;
	base->up = 0;
	base->down = 0;
	base->right = 0;
	base->left = 0;
	base->step = 0;
	base->catch_c = 0;

    map_processor(base, map_file);
	get_position(base);
	render_init(base);
	render_images(base);
	return (base);
}

// int	file_isber(char *map_file)
// {
// 	int	len;

// 	len = ft_strlen(map_file);
// 	if (!map_file)
// 		return (0);
// 	if (len < 5)
// 		return (0);
// 	if ((ft_strncmp((map_file + len - 4), ".ber", len - 4)))
// 		return (0);
// 	return (1);
// }

int main (int argc, char **argv)
{
	t_base *base;

	if (argc == 2)
	{
		// if (!file_isber(argv[1]))
		// 	return (0);
		base = base_init(argv[1]);
		draw(base);
		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		mlx_hook(base->window, 3, 1L << 1, key_release, base);
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);
		mlx_loop(base->mlx);
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}
