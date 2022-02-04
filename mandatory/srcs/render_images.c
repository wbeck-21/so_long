/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:30:17 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:20:25 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
		exit_game(base, ERROR_MLX_XPM);
}

void	render_images(t_base *base)
{
	xpm_to_image(base, &base->img_p, "./mandatory/img/player.xpm");
	xpm_to_image(base, &base->img_c, "./mandatory/img/collect_item.xpm");
	xpm_to_image(base, &base->img_1, "./mandatory/img/wall.xpm");
	xpm_to_image(base, &base->img_0, "./mandatory/img/empty.xpm");
	xpm_to_image(base, &base->img_e, "./mandatory/img/exit.xpm");
}
