#include "include/so_long.h"

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

void map_width(t_base *base, char *map_text)
{
    while (map_text[base->width] && map_text[base->width] != '\n') // или здесь ||
        base->width++;
    if (!base->width) //здесь можно проверить первую строчку на наличие 1
    {
        free(map_text);
        free(base);
        return ;
    }
    
}

void map_height(t_base *base, char *map_text)
{
    int				i;
	int				j;

    if (base->width)
    {
        i = 0;
        while (map_text[i])
        {
            j = 0;
            while (map_text[i + j] && map_text[i + j] != '\n')
                j++;
            if (j != base->width) //проверка на равенство ширин каждой строки карты
            {
                // free(map_text);
                free(base);
                return ;			
            }
            i += base->width + 1;
            base->height++;
        }
    }
    return ;
}

void map_init(t_base *base, char *map_text)
{
    map_width(base, map_text);
    // printf("%d", base->width); //проверка на ширину
    map_height(base, map_text);
    printf("%d", base->height); //проверка на высоту
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
        /*    ТАК КАК ВЫЛЕТАЮТ СИГИ, ПОКА ТАК ПРОВЕРЯЮ ЧТЕНИЕ, ПАРСИНГ И Т.Д. КАРТ
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
        */
        
	}
	else 
		printf("ERROR\nmore or less args\n");
	return (0);
}