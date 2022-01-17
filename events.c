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