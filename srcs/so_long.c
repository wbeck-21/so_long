#include "../include/so_long.h"

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}


static void	draw_square(t_base *base, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 16)
	{
		i = 0;
		while (i < 16)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(base->image, x + i, y + j, color);
			i++;
		}
		j++;
	}
}


static void	draw_env(t_base *base, int i, int j)
{
	int				k;

	if (base->position_e.x == i && base->position_e.y == j)
		draw_square(base, base->img_e, i * 16, j * 16);
	k = -1;
	while (++k < base->count_c)
		if (base->position_c[k].x == i && base->position_c[k].y == j)
			draw_square(base, base->img_c, i * 16, j * 16);
	if (base->position_p.x == i && base->position_p.y == j)
		draw_square(base, base->img_p, i * 16, j * 16);
}


static void	draw_map(t_base *base)
{
	int				i;
	int				j;

	j = 0;
	while (j < base->height)
	{
		i = 0;
		while (i < base->width)
		{
			if (base->map[j][i] == 1)
				draw_square(base, base->img_1, i * 16, j * 16);
			else
				draw_square(base, base->img_0, i * 16, j * 16);
			draw_env(base, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_base *base)
{
	draw_map(base);
	mlx_put_image_to_window(base->mlx, base->window, base->image, 0, 0);
}




void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
	{
		free(base);
		return ;
	}
	(*image)->width = width;
	(*image)->height = height;
	// mlx_put_image_to_window(base->mlx, base->window, relative_path, position_img.x, position_img.y);
	printf("width - %d, height - %d\n", width, height);
}

void	render_images(t_base *base)
{
	xpm_to_image(base, &base->img_p, "./img/player-1.xpm");
	xpm_to_image(base, &base->img_e, "./img/exit-1.xpm");
	xpm_to_image(base, &base->img_c, "./img/collection_item-1.xpm");
	xpm_to_image(base, &base->img_1, "./img/wall-1.xpm");
	xpm_to_image(base, &base->img_0, "./img/empty-1.xpm");
}

void	render_init(t_base *base)
{
	base->mlx = mlx_init();
	if (!base->mlx)
	{
		free(base);
		return ;
	}
	base->window = mlx_new_window(base->mlx, base->width * 16, base->height * 16, "so_long");
	if (!base->window)
	{
		free(base);
		return ;
	}
	base->image = mlx_new_image(base->mlx, base->width * 16, base->height * 16);
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
				base->map[i][j] = '0';
			}
			if (base->map[i][j] == 'E')
			{
				base->position_e.x = i;
				base->position_e.y = j;
				base->map[i][j] = '0';
			}
			if (base->map[i][j] == 'C')
			{
				base->position_c[k].x = i;
				base->position_c[k].y = j;
				base->map[i][j] = '0';
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
	base->img_p = 0;
    base->img_c = 0;
    base->img_e = 0;
	base->img_1 = 0;
    base->img_0 = 0;

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
		draw(base);
		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);
		mlx_loop(base->mlx);
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}

//  надо посчитать свободные пронстранства, препядствия, замолочить, далее работа со текстурами и т.д. разложи все по папкам, уже тяжело ориентироваться