#include "../include/so_long.h"

void	render_init(t_base *base)
{
	base->mlx = mlx_init();
	if (!base->mlx)
	{
		free(base);
		return ;
	}
	base->window = mlx_new_window(base->mlx, base->width * 40, base->height * 40, "so_long");
	if (!base->window)
	{
		free(base);
		return ;
	}
	base->image = mlx_new_image(base->mlx, base->width * 40, base->height * 40);
	if (!base->image)
	{
		free(base);
		return ;
	}
}

t_base *base_init(char *map_file) // проверь потом, можно ли передать из мейна *base
{
	t_base *base;
    (void) map_file;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		free(base);
		return 0;
	}
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

    map_processor(base, map_file);
	get_position(base);
	render_init(base);
	render_images(base);
	create_map(base);
	mlx_put_image_to_window(base->mlx, base->window, base->image, 0, 0);

	return (base);
}

int main (int argc, char **argv)
{
	t_base *base;

	if (argc == 2)
	{
		base = base_init(argv[1]);
		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		mlx_hook(base->window, 3, 1L << 1, key_release, base);
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);
		mlx_loop(base->mlx);
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}
