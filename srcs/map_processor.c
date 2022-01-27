#include "../include/so_long.h"

void read_map_file(t_base *base, int fd, char **map_text)
{
	char    *buf;
    char    *temp;
    int		bytes;

	buf = (char *)malloc(sizeof(char) * 1024 + 1); //мб как-то поколдовать с размером массива
    if (!buf)
	{
        free(*map_text);
        close(fd);
        exit_game(base, "Error!\nread_map_file(): malloc()\n");
    }
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, 1024);
		if (bytes < 0)
		{
            free(*map_text);
            close(fd);
            exit_game(base, "Error!\nread_map_file(): read()\n");
		}
        buf[bytes] = '\0';
        temp = ft_strjoin(*map_text, buf); //temp зафришить в конце ft_strjoin
        free(*map_text);
        *map_text = temp;
        if (!(*map_text))
        {
            close(fd);
            exit_game(base, "Error!\nread_map_file(): ft_strjoin()\n");
        }
	}
	free(buf);
}

void map_init(t_base *base, char *map_text)
{
    map_width(base, map_text);
    map_height(base, map_text);
    check_valid_map(base, map_text);
    base->map = ft_split(map_text, '\n'); //проверить на утечки
    if (!(base->map))
    {
        free(map_text);
        exit_game(base, "Error!\nmap_init(): ft_split()\n");
    }
}

void map_processor(t_base *base, char *map_file)
{
    int     fd;
    char    *map_text;
    
    fd = open(map_file, O_RDONLY);
    if (fd <= 0)
        exit_game(0, "Error!\nuncorrect file name, map_processor(): open()\n");
    map_text = ft_calloc(1, 1);
    if (!map_text)
    {
        close(fd);
        exit_game(base, "Error!\nmap_processor(): ft_calloc()\n");
    }
    read_map_file(base, fd, &map_text);
    close(fd);
    map_init(base, map_text);
    free(map_text);
}
