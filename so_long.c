#include "include/so_long.h"

void read_map_file(t_base *base, int fd, char **map_text)
{
	char	*buf;
    char    *temp;
    int		bytes;

	buf = (char *)malloc(sizeof(char) * 1024 + 1); //мб как-то поколдовать с размером массива
    if (!buf)
		return ;
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, 1024);
		if (bytes < 0)
		{
			free(buf);
            free(*map_text);
            free(base);
            close(fd);
			return ;
		}
        else
        {
            buf[bytes] = '\0';
            temp = ft_strjoin(temp, buf); //temp зафришить в конце ft_strjoin
            free(*map_text);
            *map_text = temp;
            if (!(*map_text))
            {
                free(base);
                close(fd);
                return ;
            }
        }
	}
	free(buf);
}

void map_processor(t_base *base, char* map_file)
{
    int fd;
    char *map_text;
    
    fd = open(map_file, O_RDONLY);
    if (fd <= 0)
    {
        free(base);
        return ;
    }
    map_text = (char *)malloc(sizeof(char));
    if (!map_text)
    {
        close(fd);
        free(base);
        return ;
    }
    read_map_file(base, fd, &map_text);
    printf("%s", map_text);

}


t_base *base_init(char *map_file) // проверь потом, можно ли передать из мейна *base
{
	t_base *base;
    (void) map_file;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		free(base);
		return 0;
	}
	base->mlx = 0;
	base->window = 0;
    base->map = 0;
    base->width = 0;
    base->height = 0;
    map_processor(base, map_file);
	return (base);
}

int main (int argc, char **argv)
{
	t_base *base;

	if (argc == 2)
	{
		base = base_init(argv[1]);
		base->mlx = mlx_init();
		if (!(base->mlx))
		{
			free(base);
			return 0;
		}
		base->window = mlx_new_window(base->mlx, 600, 600, "so_long");
		if (!(base->window))
		{
			free(base);
			return 0;
		}
		mlx_hook(base->window, 2, 1L << 0, key_press, base);
		mlx_hook(base->window, 17, 1L << 17, destroy_notify, base);
		mlx_loop(base->mlx);
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}