#include "../include/so_long_bonus.h"

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

static void	create_field(t_base *base, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = -1;
	while (++j < 40)
	{
		i = -1;
		while (++i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(base->image, x + i, y + j, color);
		}
	}
}

void	create_map(t_base *base)
{
	int	i;
	int	j;
	int k;

	i = -1;
	while (++i < base->height)
	{
		j = -1;
		while (++j < base->width)
		{
			create_field(base, base->img_0, j * 40, i * 40);
			if (base->map[i][j] == '1')
				create_field(base, base->img_1, j * 40, i * 40);
			if (base->position_e.x == i && base->position_e.y == j)
				create_field(base, base->img_e, j * 40, i * 40);
			k = -1;
			while (++k < base->count_c)
				if (base->position_c[k].x == i && base->position_c[k].y == j)
					create_field(base, base->img_c, j * 40, i * 40);
			if (base->position_p.x == i && base->position_p.y == j)
				create_field(base, base->img_p, j * 40, i * 40);
			if (base->position_o.x == i && base->position_o.y == j)
			{
				if (base->enemy->sprite_index == 9)
					base->enemy->sprite_index = 0;
				else
					base->enemy->sprite_index++;
				base->img_o = base->enemy->sprites[base->enemy->sprite_index];
				create_field(base, base->img_o, j * 40, i * 40);
			}
		}
	}
}

void	draw(t_base *base)
{
	create_map(base);
	mlx_put_image_to_window(base->mlx, base->window, base->image, 0, 0);
}