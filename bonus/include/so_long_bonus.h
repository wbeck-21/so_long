/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:44:53 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 22:04:44 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR_FILE "Error!\nFile doesn't exist: check name or format\n"
# define ERROR_ARGS "Error!\nMore or less args\n"

# define ERROR_INVALID_MAP_0 "Error!\nInvalid map: map borders contain only '1'\n"
# define ERROR_INVALID_MAP_1 "Error!\nInvalid map: map contain only 01PECX\n"
# define ERROR_INVALID_MAP_2 "Error!\nInvalid map: uncorrect count of symbols\n"
# define ERROR_INVALID_MAP_3 "Error!\nInvalid map: width = 0 and height = 0\n"
# define ERROR_INVALID_MAP_4 "Error!\nInvalid map: different width\n"

# define ERROR_MALLOC_0 "Error!\nget_position(): malloc()\n"
# define ERROR_MALLOC_1 "Error!\nread_map_file(): malloc()\n"
# define ERROR_MALLOC_2 "Error!\ninit_player_sprites(): player = malloc()\n"
# define ERROR_MALLOC_3 "Error!\ninit_player_sprites(): malloc()\n"

# define ERROR_READ "Error!\nread_map_file(): read()\n"
# define ERROR_MLX_XPM "Error!\nxpm_to_image(): mlx_xpm_file_to_image()\n"

# define ERROR_FT_CALLOC "Error!\nmap_processor(): ft_calloc()\n"
# define ERROR_FT_STRJOIN "Error!\nread_map_file(): ft_strjoin()\n"
# define ERROR_FT_SPLIT "Error!\nmap_init(): ft_split()\n"

# define IMG_PLAYER_0 "./bonus/img/sprites/player_0.xpm"
# define IMG_PLAYER_1 "./bonus/img/sprites/player_1.xpm"
# define IMG_PLAYER_2 "./bonus/img/sprites/player_2.xpm"
# define IMG_PLAYER_3 "./bonus/img/sprites/player_3.xpm"
# define IMG_PLAYER_4 "./bonus/img/sprites/player_4.xpm"
# define IMG_PLAYER_5 "./bonus/img/sprites/player_5.xpm"
# define IMG_PLAYER_6 "./bonus/img/sprites/player_6.xpm"

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

typedef struct s_player
{
	void	**sprites;
	int		sprite_index;
}			t_player;

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
	int			count_x;

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
	t_img		*img_x;

	t_pos		position_p;
	t_pos		position_e;
	t_pos		position_x;
	t_pos		*position_c;

	t_player	*player;

}				t_base;

int		animate_player(t_base *base);
int		key_press(int key, t_base *base);
int		key_release(int key, t_base *base);
int		destroy_notify(t_base *base);

void	map_width(t_base *base, char *map_text);
void	map_height(t_base *base, char *map_text);

void	print_steps(t_base *base);
void	check_valid_map(t_base *base, char *map_text);
void	map_processor(t_base *base, char *map_file);
void	create_map(t_base *base);
void	render_images(t_base *base);
void	get_position(t_base *base);
void	create_map(t_base *base);
void	update(t_base *base);

void	up(t_base *base, int x, int y);
void	down(t_base *base, int x, int y);
void	left(t_base *base, int x, int y);
void	right(t_base *base, int x, int y);

void	exit_game(t_base *base, char *error);

#endif