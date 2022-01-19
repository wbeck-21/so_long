#ifndef SO_LONG_H
# define SO_LONG_H

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

    t_img       *img_p;
    t_img       *img_e;
    t_img       *img_c;
    t_img       *img_0;
    t_img       *img_1;

    t_pos       position_p;
    t_pos       position_e;
    t_pos       *position_c;
    // t_pos       *position_0;
    // t_pos       *position_1;

}   t_base;

int     key_press(int key, t_base *base);
int     destroy_notify(int key, t_base *base);
void    map_width(t_base *base, char *map_text);
void    map_height(t_base *base, char *map_text);
void    check_valid_map(t_base *base, char *map_text);
void    map_processor(t_base *base, char *map_file);


#endif