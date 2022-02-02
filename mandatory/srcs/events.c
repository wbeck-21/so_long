#include "../include/so_long.h"

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

int	destroy_notify(int key, t_base *base)
{
	(void)key;
	(void)base;
	
    exit_game(0, 0);
	return (0);
}