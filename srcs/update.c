#include "../include/so_long.h"

void	catch_c(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->count_c)
	{
		if (base->position_p.x == base->position_c[i].x && base->position_p.y == base->position_c[i].y)
		{
			base->position_c[i].x = -1;
			base->position_c[i].y = -1;
			base->catch_c = base->catch_c + 1;
		}
		i++;
	}
}

void	update(t_base *base)
{
	int				x;
	int				y;

	x = base->position_p.x;
	y = base->position_p.y;
	if (base->up != 0)
		up(base, x, y);
	else if (base->down != 0)
		down(base, x, y);
	else if (base->left != 0)
		left(base, x, y);
	else if (base->right != 0)
		right(base, x, y);
	if (base->position_p.x != x || base->position_p.y != y)
	{
		base->step++;
		// printf("step - ");
		ft_putnbr_fd(base->step, 1);
		printf("\n");
	}
	catch_c(base);
	draw(base);
	// printf("Px - %d Ex - %d\nPy - %d Ey - %d\n", base->position_p.x, base->position_e.x, base->position_p.y, base->position_e.y);
	if(base->position_p.x == base->position_e.x && base->position_p.y == base->position_e.y && base->catch_c == base->count_c)
	{
		ft_putstr_fd("finish\n", 1);
		exit_game(base, 0);
	}
}