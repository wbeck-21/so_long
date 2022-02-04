/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:04 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:21:51 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static unsigned int	mlx_get_color(t_img *img, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int *)(img->data
			+ (x * img->bpp / 8 + y * img->size_line));
	return (*color);
}

static void	mlx_put_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*dst;

	dst = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)dst = color;
}

static void	draw_field(t_base *base, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	i = -1;
	while (++i < 40)
	{
		j = -1;
		while (++j < 40)
		{
			color = mlx_get_color(img, i, j);
			mlx_put_pixel(base->image, x + i, y + j, color);
		}
	}
}

static void	draw_map(t_base *base)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < base->height)
	{
		j = -1;
		while (++j < base->width)
		{
			draw_field(base, base->img_0, j * 40, i * 40);
			if (base->map[i][j] == '1')
				draw_field(base, base->img_1, j * 40, i * 40);
			if (base->position_e.x == i && base->position_e.y == j)
				draw_field(base, base->img_e, j * 40, i * 40);
			k = -1;
			while (++k < base->count_c)
				if (base->position_c[k].x == i && base->position_c[k].y == j)
					draw_field(base, base->img_c, j * 40, i * 40);
			if (base->position_p.x == i && base->position_p.y == j)
				draw_field(base, base->img_p, j * 40, i * 40);
		}
	}
}

void	create_map(t_base *base)
{
	draw_map(base);
	mlx_put_image_to_window(base->mlx, base->window, base->image, 0, 0);
}
