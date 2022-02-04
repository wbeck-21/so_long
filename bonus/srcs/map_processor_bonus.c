/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:52:16 by wbeck             #+#    #+#             */
/*   Updated: 2022/02/04 19:12:52 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	read_map_file(t_base *base, int fd, char **map_text, char *buf)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, 1024);
		if (bytes < 0)
		{
			free(*map_text);
			close(fd);
			exit_game(base, ERROR_READ);
		}
		buf[bytes] = '\0';
		temp = ft_strjoin(*map_text, buf);
		free(*map_text);
		*map_text = temp;
		if (!(*map_text))
		{
			close(fd);
			exit_game(base, ERROR_FT_STRJOIN);
		}
	}
	free(buf);
}

void	map_init(t_base *base, char *map_text)
{
	map_width(base, map_text);
	map_height(base, map_text);
	check_valid_map(base, map_text);
	base->map = ft_split(map_text, '\n');
	if (!(base->map))
	{
		free(map_text);
		exit_game(base, ERROR_FT_SPLIT);
	}
}

void	map_processor(t_base *base, char *map_file)
{
	int		fd;
	char	*map_text;
	char	*buf;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0)
		exit_game(0, ERROR_FILE);
	map_text = ft_calloc(1, 1);
	if (!map_text)
	{
		close(fd);
		exit_game(base, ERROR_FT_CALLOC);
	}
	buf = (char *)malloc(sizeof(char) * 1024 + 1);
	if (!buf)
	{
		free(map_text);
		close(fd);
		exit_game(base, ERROR_MALLOC_1);
	}
	read_map_file(base, fd, &map_text, buf);
	close(fd);
	map_init(base, map_text);
	free(map_text);
}
