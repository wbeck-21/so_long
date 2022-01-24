#include "../include/so_long.h"

void	get_position(t_base *base)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	
	base->position_c = (t_pos *)malloc(sizeof(t_pos) * base->count_c + 1);
	if (!(base->position_c))
	{
		printf("im here\n");
		free(base);
		return ;
	}
	while (i < base->height)
	{
		j = 0;
		while (j < base->width)
		{
			if (base->map[i][j] == 'C')
			{
				base->position_c[k].x = i;
				base->position_c[k].y = j;
				base->map[i][j] = '0';

				k++;
			}
			if (base->map[i][j] == 'P')
			{
				base->position_p.x = i;
				base->position_p.y = j;
				base->map[i][j] = '0';
			}
			if (base->map[i][j] == 'E')
			{
				base->position_e.x = i;
				base->position_e.y = j;
			}
			j++;
		}
		i++;
	}
}