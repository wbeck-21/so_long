#include "../include/so_long.h"

int check_border(t_base *base, int i)
{
    if (i < base->width || i % (base->width + 1) == base->width - 1 || i % (base->width + 1) == 0 || i >= (base->width + 1) * (base->height - 1))
		return (1);
	return (0);
}

//  i < base->width ----------------------------------- top
//  i % (base->width + 1) == base->width - 1 ---------- right
//  i % (base->width + 1) == 0 ------------------------ left
//  i >= (base->width + 1) * (base->height - 1) ------- bottom

int check_symbols(t_base *base, char *map_text, int i)
{
    if (map_text[i] == 'P' || map_text[i] == 'C' || map_text[i] == 'E' || map_text[i] == '1' || map_text[i] == '0')
    {
        if (map_text[i] == 'P')
            base->count_p++;
        else if (map_text[i] == 'C')
            base->count_c++;
        else if (map_text[i] == 'E')
            base->count_e++;
        else if (map_text[i] == '1' || map_text[i] == '0')
            return (1);
        return (1);
    }
    return (0);
}

void check_valid_map(t_base *base, char *map_text)
{
    int i;

    i = 0;
    while (map_text[++i])
    {
        if (map_text[i] == '\n')
            continue ;
        if (check_border(base, i))
        {
            // printf("%d - %d\n", i, check_border(base, i)); //проверка на бордеры
            if (map_text[i] != '1')
            {
                printf("borders arent correct\n");
                free(map_text);
                exit_game(base);
            }
        }
        else if (!check_symbols(base, map_text, i))
        {
            printf("%c, symbols arent correct\n", map_text[i]); // проверка на символы
            free(map_text);
            exit_game(base);
        }
    }
    if (base->count_p != 1 || base->count_e != 1 || base->count_c < 0)
    {
        printf("P or E or C arent correct\n");
        free(map_text);
        exit_game(base);
    }
}