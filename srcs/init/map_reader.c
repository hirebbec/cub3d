/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:22:35 by naqua             #+#    #+#             */
/*   Updated: 2022/09/02 14:08:37 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strjoin_free1(char *s1, char *s2);
char	*ft_strjoin_free_all(char *s1, char *s2, int i);

int	map_reader_helper(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (-1);
		i++;
	}
	return (i);
}

static int	str_only_one_spaces(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && \
			line[i] != '0' && line[i] != 'W' && line[i] != '1' && \
			line[i] != ' ' && line[i] != '\n')
			return (-1);
		else
			i++;
	}
	if (map_reader_helper(line) == -1)
		game->map_already_init_flag++;
	else if (map_reader_helper(line) != -1 && game->map_already_init_flag > 0)
	{
		ft_putendl_fd("Map error", 2);
		exit(1);
	}
	return (i);
}

void	map_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map_height = 0;
	game->map_width = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j > game->map_width)
			game->map_width = j;
		i++;
	}
	game->map_height = i;
}

void	map_reader_fd_error(int fd)
{
	if (fd == -1)
	{
		ft_putendl_fd("File open error", 2);
		exit(1);
	}
}

void	map_reader(char *path, t_game *game, int fd, char *map_holder)
{
	char	*line;
	char	*temp;

	fd = open(path, O_RDONLY);
	map_reader_fd_error(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (str_only_one_spaces(line, game) != -1)
		{
			temp = map_holder;
			map_holder = ft_strjoin(temp, line);
			free(temp);
		}
		free(line);
	}
	game->map = ft_split(map_holder, '\n');
	free(map_holder);
	close(fd);
}
