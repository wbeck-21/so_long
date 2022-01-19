#include "../include/so_long.h"

void	xpm_to_image(t_base *base, t_img **image, char *xpm)
{
	int width;
	int height;
	*image = mlx_xpm_file_to_image(base->mlx, xpm, &width, &height);
	if (!(*image))
	{
		free(base);
		return ;
	}
	(*image)->width = width;
	(*image)->height = height;
}

void	render_images(t_base *base)
{
	xpm_to_image(base, &base->img_p, "./img/player.xpm");
	xpm_to_image(base, &base->img_e, "./img/exit.xpm");
	xpm_to_image(base, &base->img_c, "./img/collection_item.xpm");
	xpm_to_image(base, &base->img_1, "./img/wall.xpm");
	xpm_to_image(base, &base->img_0, "./img/ground.xpm");
}

void	render_init(t_base *base)
{
	base->mlx = mlx_init();
	if (!base->mlx)
	{
		free(base);
		return ;
	}
	base->window = mlx_new_window(base->mlx, base->width * 50, base->height * 50, "so_long");
	if (!base->window)
	{
		free(base);
		return ;
	}
	base->image = mlx_new_image(base->mlx, base->width * 50, base->height * 50);
	if (!base->image)
	{
		free(base);
		return ;
	}

}

void	get_position(t_base *base)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	base->position_c = (t_pos *)malloc(sizeof(t_pos) * base->count_c);
	if (!(base->position_c))
	{
		// printf("im here\n");
		free(base);
		return ;
	}
	while (i < base->height)
	{
		//printf("i-%d\t",i );
		j = 0;
		while (j < base->width)
		{
			//printf("\tj-%d\n",j );
			if (base->map[i][j] == 'P')
			{
				base->position_p.x = i;
				base->position_p.y = j;
				// base->map[i][j] = '0';
			}
			if (base->map[i][j] == 'E')
			{
				base->position_e.x = i;
				base->position_e.y = j;
				// base->map[i][j] = '0';
			}
			if (base->map[i][j] == 'C')
			{
				base->position_c[k].x = i;
				base->position_c[k].y = j;
				// base->map[i][j] = '0';
				k++;
			}
			j++;
		}
		i++;
	}
}

t_base *base_init(char *map_file) // проверь потом, можно ли передать из мейна *base
{
	t_base *base;
    (void) map_file;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		free(base);
		return 0;
	}
	base->mlx = 0;
	base->window = 0;
	base->image = 0;
    base->map = 0;
    base->width = 0;
    base->height = 0;
    base->count_p = 0;
    base->count_c = 0;
    base->count_e = 0;

    map_processor(base, map_file);
	get_position(base);
	// printf("P - x - %d y - %d\n", base->position_p.x, base->position_p.y);
	// printf("E - x - %d y - %d\n", base->position_e.x, base->position_e.y);
	// printf("C - x - %d y - %d, k - %d\n", base->position_c->x, base->position_c->y, k);
	render_init(base);
	render_images(base);

	return (base);
}

int main (int argc, char **argv)
{
	t_base *base;

	if (argc == 2)
	{
		base = base_init(argv[1]);
		// base->mlx = mlx_init();
        // ТАК КАК ВЫЛЕТАЮТ СИГИ, ПОКА ТАК ПРОВЕРЯЮ ЧТЕНИЕ, ПАРСИНГ И Т.Д. КАРТ
		// if (!(base->mlx))
		// {
		// 	free(base);
		// 	return 0;
		// }
		// base->window = mlx_new_window(base->mlx, 600, 600, "so_long");
		// if (!(base->window))
		// {
		// 	free(base);
		// 	return 0;
		// }

		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);

		mlx_loop(base->mlx);
	printf("LOL\n");
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}

//  надо посчитать свободные пронстранства, препядствия, замолочить, далее работа со текстурами и т.д. разложи все по папкам, уже тяжело ориентироваться