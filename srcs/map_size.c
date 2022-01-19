#include "../include/so_long.h"

void    map_width(t_base *base, char *map_text)
{
    while (map_text[base->width] && map_text[base->width] != '\n') // или здесь ||
        base->width++;
    if (!base->width)
    {
        // free(map_text);
        free(base);
        return ;
    }
}

void    map_height(t_base *base, char *map_text)
{
    int i;
	int j;

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
