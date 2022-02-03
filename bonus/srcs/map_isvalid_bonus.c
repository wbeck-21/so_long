#include "../include/so_long_bonus.h"

int	check_border(t_base *base, int i)
{
	if (i < base->width || i % (base->width + 1) == base->width - 1
		|| i % (base->width + 1) == 0
		|| i >= (base->width + 1) * (base->height - 1))
		return (1);
	return (0);
}

//  i < base->width ----------------------------------- top
//  i % (base->width + 1) == base->width - 1 ---------- right
//  i % (base->width + 1) == 0 ------------------------ left
//  i >= (base->width + 1) * (base->height - 1) ------- bottom

int	check_symbols(t_base *base, char *map_text, int i)
{
	if (map_text[i] == 'P' || map_text[i] == 'C' || map_text[i] == 'E'
		|| map_text[i] == '1' || map_text[i] == '0' || map_text[i] == 'X')
	{
		if (map_text[i] == 'P')
			base->count_p++;
		else if (map_text[i] == 'C')
			base->count_c++;
		else if (map_text[i] == 'E')
			base->count_e++;
		else if (map_text[i] == 'X')
			base->count_x++;
		else if (map_text[i] == '1' || map_text[i] == '0')
			return (1);
		return (1);
	}
	return (0);
}

void	check_valid_map(t_base *base, char *map_text)
{
	int	i;

	i = 0;
	while (map_text[++i])
	{
		if (map_text[i] == '\n')
			continue ;
		if (check_border(base, i))
		{
			if (map_text[i] != '1')
			{
				free(map_text);
				exit_game(0, ERROR_INVALID_MAP_0);
			}
		}
		else if (!check_symbols(base, map_text, i))
		{
			free(map_text);
			exit_game(0, ERROR_INVALID_MAP_1);
		}
	}
	if (base->count_p != 1 || base->count_e != 1
		|| base->count_x != 1 || base->count_c < 0)
	{
		free(map_text);
		exit_game(0, ERROR_INVALID_MAP_2);
	}
}
