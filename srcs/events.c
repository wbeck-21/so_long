#include "../include/so_long.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	move_up(t_base *base, int x, int y)
{
	(void) x;
	(void) y;
	// printf("1-P - x - %d y - %d\n", base->position_p.x, base->position_p.y);
	base->position_p.y = base->position_p.y - 1;
	// printf("2-P - x - %d y - %d\n", base->position_p.x, base->position_p.y);
	
}

void	move_down(t_base *base, int x, int y)
{
	(void) x;
	(void) y;
	// printf("1-P - x - %d y - %d\n", base->position_p.x, base->position_p.y);
	base->position_p.y = base->position_p.y + 1;
	// printf("2-P - x - %d y - %d\n", base->position_p.x, base->position_p.y);

}

void	move_left(t_base *base, int x, int y)
{
	(void) x;
	(void) y;

	base->position_p.x -= 1;
}

void	move_right(t_base *base, int x, int y)
{
	(void) x;
	(void) y;

	base->position_p.x += 1;
}

void	update(t_base *base)
{
	int				x;
	int				y;

	x = base->position_p.x;
	y = base->position_p.y;

	if (base->up)
		move_up(base, x, y);
	else if (base->down)
		move_down(base, x, y);
	else if (base->left)
		move_left(base, x, y);
	else if (base->right)
		move_right(base, x, y);
	// добавтьб функцию подсчета движений 

	create_map(base);
	mlx_put_image_to_window(base->mlx, base->window, base->image, 0, 0);
}

int	key_press(int key, t_base *base)
{
	printf("%d\n", key);
	if (key == 65307)
	{
		free(base);
		return (0);
	}
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
	if (key == 65307)
	{
		free(base);
		return (0);
	}
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
	
    mlx_destroy_window(0, 0); // seg fault
	return (0);
}