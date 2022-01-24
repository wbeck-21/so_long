#include "../include/so_long.h"

void	update(t_base *base)
{
	int				x;
	int				y;

	x = base->position_p.x;
	y = base->position_p.y;
	printf("x - %d y - %d\n", x, y);
	if (base->up != 0)
		up(base, x, y);
	else if (base->down != 0)
		down(base, x, y);
	else if (base->left != 0)
		left(base, x, y);
	else if (base->right != 0)
		right(base, x, y);
	draw(base);
}