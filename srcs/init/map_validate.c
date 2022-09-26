/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:22:44 by naqua             #+#    #+#             */
/*   Updated: 2022/07/11 20:44:43 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	symbol_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
			{
				ft_putendl_fd("Map symbol error", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	player_checker(char **map)
{
	int	p;
	int	i;
	int	j;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
	{
		ft_putendl_fd("Player error", 2);
		exit(1);
	}
	return (0);
}

static int	cross_checker(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' '
		|| map[i + 1][j] == ' ')
	{
		ft_putendl_fd("Map validate error", 2);
		exit(1);
	}
	if (!map[i][j - 1] || !map[i][j + 1] || !map[i - 1][j] || !map[i + 1][j])
	{
		ft_putendl_fd("Map validate error", 2);
		exit(1);
	}
	return (0);
}

static int	map_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				cross_checker(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_validate(char **map, t_game *game)
{
	if (game->map_flag > 2)
	{
		ft_putendl_fd("Map error", 2);
		exit(1);
	}
	symbol_checker(map);
	player_checker(map);
	map_checker(map);
}
