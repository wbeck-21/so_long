#include "../include/so_long_bonus.h"

int print_steps(t_base *base)
{
	char	*steps;
	char	*res;
	steps = ft_itoa(base->step);
	res = ft_strjoin("Steps: ", steps);
	mlx_string_put(base->mlx, base->window, 5, 10, 0x0000FF00, res); 
	// не понимаю какие координаты надо ставить
	free(steps);
	free(res);
	return (0);
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