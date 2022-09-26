/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:22:28 by naqua             #+#    #+#             */
/*   Updated: 2022/07/12 18:47:18 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pic_reader(char *line, t_game *game);
void	map_reader_fd_error(int fd);

static void	color_exit(void)
{
	ft_putendl_fd("Wrong RGB color, only numbers are allowed", 2);
	exit(1);
}

static void	color_f_init(char *l, t_game *game)
{
	int	i;
	int	flag;
	int	f_flag;

	f_flag = 0;
	flag = 0;
	i = -1;
	while (l[++i + 1])
	{
		if (l[i] == 'F')
			++f_flag;
		else if (l[i] == ',')
			++flag;
		else if (ft_isdigit(l[i]) && flag == 0)
			game->color.f_col_r = game->color.f_col_r * 10 + l[i] - '0';
		else if (ft_isdigit(l[i]) && flag == 1)
			game->color.f_col_g = game->color.f_col_g * 10 + l[i] - '0';
		else if (ft_isdigit(l[i]) && flag == 2)
			game->color.f_col_b = game->color.f_col_b * 10 + l[i] - '0';
		else if ((!ft_isdigit(l[i]) && l[i] != ' ' && l[i] != ',' && \
			l[i] != 'F' && l[i] != '\t') || f_flag > 1)
			color_exit();
	}
}

static void	color_c_init(char *line, t_game *game)
{
	int	i;
	int	flag;
	int	c_flag;

	c_flag = 0;
	flag = 0;
	i = -1;
	while (line[++i + 1])
	{
		if (line[i] == 'C')
			++c_flag;
		else if (line[i] == ',')
			++flag;
		else if (ft_isdigit(line[i]) && flag == 0)
			game->color.c_col_r = game->color.c_col_r * 10 + line[i] - '0';
		else if (ft_isdigit(line[i]) && flag == 1)
			game->color.c_col_g = game->color.c_col_g * 10 + line[i] - '0';
		else if (ft_isdigit(line[i]) && flag == 2)
			game->color.c_col_b = game->color.c_col_b * 10 + line[i] - '0';
		else if ((!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',' \
			&& line[i] != 'C' && line[i] != '\t') || c_flag > 1)
			color_exit();
	}
}

void	color_ceil_floor_init(t_game *game)
{
	game->color.ceil = game->color.c_col_r * 65536 + \
		game->color.c_col_g * 256 + game->color.c_col_b;
	game->color.floor = game->color.f_col_r * 65536 + \
		game->color.f_col_g * 256 + game->color.f_col_b;
}

void	color_reader(char *path, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	map_reader_fd_error(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strnstr(line, "F ", ft_strlen(line)))
		{
			game->color.duplicate_flag_f++;
			color_f_init(line, game);
		}
		if (ft_strnstr(line, "C ", ft_strlen(line)))
		{
			game->color.duplicate_flag_c++;
			color_c_init(line, game);
		}
		pic_reader(line, game);
		free(line);
	}
	close(fd);
}
