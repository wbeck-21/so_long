#include "../include/so_long_bonus.h"

void	map_width(t_base *base, char *map_text)
{
	while (map_text[base->width] && map_text[base->width] != '\n')
		base->width++;
	if (!base->width)
	{
		free(map_text);
		exit_game(base, ERROR_INVALID_MAP_3);
	}
}

void	map_height(t_base *base, char *map_text)
{
	int	i;
	int	j;

	if (base->width)
	{
		i = 0;
		while (map_text[i])
		{
			j = 0;
			while (map_text[i + j] && map_text[i + j] != '\n')
				j++;
			if (j != base->width)
			{
				free(map_text);
				exit_game(base, ERROR_INVALID_MAP_4);
			}
			i += base->width + 1;
			base->height++;
		}
	}
	return ;
}
