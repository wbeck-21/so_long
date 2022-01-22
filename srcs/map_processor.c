#include "../include/so_long.h"

void read_map_file(t_base *base, int fd, char **map_text)
{
	char    *buf;
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
	free(buf);
}

void map_init(t_base *base, char *map_text)
{
    map_width(base, map_text);
    // printf("%d", base->width); //проверка на ширину
    map_height(base, map_text);
    // printf("%d", base->height); //проверка на высоту
    check_valid_map(base, map_text);
    base->map = ft_split(map_text, '\n'); //проверить на утечки
    // int i;

    // i = 0;
    // while (i < base->height)
    //     printf("%s\n", base->map[i++]);
    // проверка двумерного массива

}

void map_processor(t_base *base, char *map_file)
{
    int     fd;
    char    *map_text;
    
    fd = open(map_file, O_RDONLY);
    if (fd <= 0)
    {
        free(base);
        return ;
    }
    map_text = ft_calloc(1, 1);
    if (!map_text)
    {
        close(fd);
        free(map_text); //надо ли здесь фришить эту запупу
        free(base);
        return ;
    }
    read_map_file(base, fd, &map_text);
    // printf("%s", map_text); //проверка чтения карты
    close(fd);
    map_init(base, map_text);
    free(map_text);
}
