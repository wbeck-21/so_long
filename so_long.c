#include "include/so_long.h"

int	key_press(int key, t_base *base)
{
    (void)key;
	(void)base;

	mlx_destroy_window(0, 0); // seg fault
	return (0);
}

int	destroy_notify(int key, t_base *base)
{
	(void)key;
	(void)base;
	
    mlx_destroy_window(0, 0); // seg fault
	return (0);
}

t_base *base_init(char *map)
{
	t_base *base;
	(void) map;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		free(base);
		return 0;
	}
	base->mlx = 0;
	base->window = 0;
	return (base);
}

int main (int argc, char **argv)
{
	t_base *base;

	if (argc == 2)
	{
		base = base_init(argv[1]);
		base->mlx = mlx_init();
		if (!(base->mlx))
		{
			free(base);
			return 0;
		}
		base->window = mlx_new_window(base->mlx, 600, 600, "so_long");
		if (!(base->window))
		{
			free(base);
			return 0;
		}
		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);
		mlx_loop(base->mlx);
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}