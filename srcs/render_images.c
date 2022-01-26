#include "../include/so_long.h"

void	xpm_to_image(t_base *base, t_img **image, char *relative_path)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	if (!(*image))
	    exit_game(base);
	(*image)->width = width;
	(*image)->height = height;
}

void	render_images(t_base *base)
{
	xpm_to_image(base, &base->img_p, "./img/player-5.xpm");
	xpm_to_image(base, &base->img_c, "./img/collect-item-5.xpm");
	xpm_to_image(base, &base->img_1, "./img/wall-5.xpm");
	xpm_to_image(base, &base->img_0, "./img/empty-5.xpm");
	xpm_to_image(base, &base->img_e, "./img/exit-5.xpm");
}
