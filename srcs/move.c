#include "../include/so_long.h"

void	up(t_base *base, int x, int y)
{
    printf("map - %c\n", base->map[x - 1][y]);
	if (base->map[x - 1][y] != '1')
	    base->position_p.x -= 1;
}

void	down(t_base *base, int x, int y)
{
    printf("map - %c\n", base->map[x + 1][y]);

	if (base->map[x + 1][y] != '1')
	    base->position_p.x += 1;
}

void	left(t_base *base, int x, int y)
{
    printf("map - %c\n", base->map[x][y - 1]);
    if (base->map[x][y - 1] != '1')
        base->position_p.y -= 1;
}

void	right(t_base *base, int x, int y)
{
    printf("map - %c\n", base->map[x][y + 1]);
    if (base->map[x][y + 1] != '1')
	    base->position_p.y += 1;
}