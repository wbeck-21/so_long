#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_base
{
    void	*mlx;
	void	*window;
    char    **map;
    int     width;
    int     height;

}   t_base;

int	key_press(int key, t_base *base);
int	destroy_notify(int key, t_base *base);

#endif