#include "../include/so_long.h"

void	catch_c(t_base *base, int x, int y)
{
	int	i;

	i = 0;
	while (i < base->count_c)
	{
		printf("i - %d\n", i);
		if (base->position_p.x == base->position_c[i].x && base->position_p.y == base->position_c[i].y)
		{
			base->map[x][y] = 'P';
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
	// printf("x - %d y - %d\n", x, y);
	if (base->up != 0)
		up(base, x, y);
	else if (base->down != 0)
		down(base, x, y);
	else if (base->left != 0)
		left(base, x, y);
	else if (base->right != 0)
		right(base, x, y);
	catch_c(base, x, y);
	draw(base);
	printf("Px - %d Ex - %d\nPy - %d Ey - %d\n", base->position_p.x, base->position_e.x, base->position_p.y, base->position_e.y);
	printf("catch - %d count - %d\n", base->catch_c, base->count_c);
	if(base->position_p.x == base->position_e.x && base->position_p.y == base->position_e.y && base->catch_c == base->count_c)
	{
		printf("finish\n");
		free(base);
		return ;
	}
}