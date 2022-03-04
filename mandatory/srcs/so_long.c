/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:32:38 by wbeck             #+#    #+#             */
/*   Updated: 2022/03/04 20:52:35 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_init(t_base *base)
{
	base->mlx = mlx_init();
	if (!base->mlx)
		exit_game(base, "Error!\nmlx_init()\n");
	base->window = mlx_new_window(base->mlx,
			base->width * 40, base->height * 40, "so_long");
	if (!base->window)
		exit_game(base, "Error!\nmlx_new_window()\n");
	base->image = mlx_new_image(base->mlx, base->width * 40, base->height * 40);
	if (!base->image)
		exit_game(base, "Error!\nmlx_new_image()\n");
}

t_base	*base_init(t_base *base, char *map_file)
{
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
	base->up = 0;
	base->down = 0;
	base->right = 0;
	base->left = 0;
	base->step = 0;
	base->catch_c = 0;
	map_processor(base, map_file);
	get_position(base);
	render_init(base);
	render_images(base);
	return (base);
}

static int	file_isber(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len > 3
		&& (
			map_file[len - 4] == '.'
			&& map_file[len - 3] == 'b'
			&& map_file[len - 2] == 'e'
			&& map_file[len - 1] == 'r'
		)
	)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_base	*base;

	if (argc == 2)
	{
		if (!file_isber(argv[1]))
			exit_game(0, ERROR_FILE);
		base = (t_base *)malloc(sizeof(t_base));
		if (!base)
			exit_game(base, "Error!\nbase_init(): malloc()\n");
		base = base_init(base, argv[1]);
		create_map(base);
		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		mlx_hook(base->window, 3, 1L << 1, key_release, base);
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);
		mlx_loop(base->mlx);
	}
	else
		exit_game(0, ERROR_ARGS);
	return (0);
}
