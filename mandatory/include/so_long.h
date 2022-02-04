/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:27:11 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 21:40:49 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR_FILE "Error!\nFile isn't exit: check name or format\n"
# define ERROR_ARGS "Error!\nMore or less args\n"

# define ERROR_MALLOC_0 "Error!\nget_position(): malloc()\n"
# define ERROR_MALLOC_1 "Error!\nread_map_file(): malloc()\n"

# define ERROR_INVALID_MAP_0 "Error!\nInvalid map: map borders contain only '1'\n"
# define ERROR_INVALID_MAP_1 "Error!\nInvalid map: map contain only 01PECX\n"
# define ERROR_INVALID_MAP_2 "Error!\nInvalid map: uncorrect count of symbols\n"
# define ERROR_INVALID_MAP_3 "Error!\nInvalid map: width = 0 and height = 0\n"
# define ERROR_INVALID_MAP_4 "Error!\nInvalid map: different width\n"

# define ERROR_READ "Error!\nread_map_file(): read()\n"
# define ERROR_MLX_XPM "Error!\nxpm_to_image(): mlx_xpm_file_to_image()\n"

# define ERROR_FT_CALLOC "Error!\nmap_processor(): ft_calloc()\n"
# define ERROR_FT_STRJOIN "Error!\nread_map_file(): ft_strjoin()\n"
# define ERROR_FT_SPLIT "Error!\nmap_init(): ft_split()\n"

// typedef struct s_texture
// {
//     t_xpm   *img_p;
//     t_xpm   *img_c;
//     t_xpm   *img_e;
//     t_xpm   *img_0;
//     t_xpm   *img_1;
// }   t_texture;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_base
{
	void		*mlx;
	void		*window;
	void		*image;

	char		**map;
	int			width;
	int			height;

	int			count_p;
	int			count_c;
	int			count_e;

	int			up;
	int			down;
	int			right;
	int			left;

	int			step;

	int			catch_c;

	t_img		*img_e;
	t_img		*img_c;
	t_img		*img_0;
	t_img		*img_1;
	t_img		*img_p;

	t_pos		position_p;
	t_pos		position_e;
	t_pos		*position_c;

}				t_base;

int		key_press(int key, t_base *base);
int		key_release(int key, t_base *base);
int		destroy_notify(int key);
void	map_width(t_base *base, char *map_text);
void	map_height(t_base *base, char *map_text);
void	check_valid_map(t_base *base, char *map_text);
void	map_processor(t_base *base, char *map_file);
void	create_map(t_base *base);
void	render_images(t_base *base);
void	get_position(t_base *base);
void	draw(t_base *base);
void	update(t_base *base);

void	up(t_base *base, int x, int y);
void	down(t_base *base, int x, int y);
void	left(t_base *base, int x, int y);
void	right(t_base *base, int x, int y);

void	exit_game(t_base *base, char *error);

#endif