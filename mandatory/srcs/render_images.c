#include "../include/so_long.h"

void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
	    exit_game(base, "Error\n xpm_to_image(): mlx_xpm_file_to_image()\n");
	// (*image)->width = width;
	// (*image)->height = height;
	// printf("w - %d h - %d\n", width, height);
}

void	render_images(t_base *base)
{
	xpm_to_image(base, &base->img_p, "./mandatory/img/player-5.xpm");
	xpm_to_image(base, &base->img_c, "./mandatory/img/collect-item-5.xpm");
	xpm_to_image(base, &base->img_1, "./mandatory/img/wall-5.xpm");
	xpm_to_image(base, &base->img_0, "./mandatory/img/empty-5.xpm");
	xpm_to_image(base, &base->img_e, "./mandatory/img/exit-5.xpm");
}