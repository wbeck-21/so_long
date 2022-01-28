#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

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

typedef struct s_enemy 
{
	void	**sprites;
	int		sprite_index;
}			t_enemy;


typedef struct s_base
{
    void	    *mlx;
	void	    *window;
    void        *image;
    
    char        **map;
    int         width;
    int         height;
    int         count_p;
    int         count_c;
    int         count_e;
    int         count_o;

    int         up;
    int         down;
    int         right;
    int         left;

    int         step;

    int         catch_c;

    t_img       *img_p;
    t_img       *img_e;
    t_img       *img_c;
    t_img       *img_0;
    t_img       *img_o;
    t_img       *img_1;

    t_pos       position_p;
    t_pos       position_e;
    t_pos       position_o;
    t_pos       *position_c;

    t_enemy     *enemy;
}   t_base;

int     key_press(int key, t_base *base);
int     key_release(int key, t_base *base);
int     destroy_notify(int key, t_base *base);
void    map_width(t_base *base, char *map_text);
void    map_height(t_base *base, char *map_text);
void    check_valid_map(t_base *base, char *map_text);
void    map_processor(t_base *base, char *map_file);
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