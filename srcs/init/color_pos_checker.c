/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pos_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:31:58 by naqua             #+#    #+#             */
/*   Updated: 2022/07/12 18:15:48 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	map_reader_fd_error(int fd);

static int	f_pos(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'F')
			return (i);
		i++;
	}
	return (-1);
}

static int	c_pos(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			return (i);
		i++;
	}
	return (-1);
}

static int	digit_pos(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return (i);
		i++;
	}
	return (-1);
}

static void	check_pos(int color_pos, int digit_pos)
{
	if (color_pos > digit_pos)
	{
		ft_putendl_fd("Color error", 2);
		exit(1);
	}
}

void	color_f_pos_checker(char *path)
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
			check_pos(f_pos(line), digit_pos(line));
		else if (ft_strnstr(line, "C ", ft_strlen(line)))
			check_pos(c_pos(line), digit_pos(line));
		free(line);
	}
	close(fd);
}
