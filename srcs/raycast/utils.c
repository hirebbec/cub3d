/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:16:42 by hirebbec          #+#    #+#             */
/*   Updated: 2022/07/11 20:11:13 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	pifogor(double x, double y, t_game *game)
{
	if (x > game->map_width - 1)
		x = game->map_width - 1;
	if (y > game->map_height - 1)
		y = game->map_height - 1;
	if (y < 0.0)
		y = 0.0;
	if (x < 0.0)
		x = 0.0;
	return (sqrt(pow(x, 2.0) + pow(y, 2.0)));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_exit(t_game *game)
{
	(void)game;
	exit(0);
}

void	init_angels(t_game *game)
{
	int	i;

	i = 0;
	game->d_anglee = 60.0 / 1920.0;
	while (i < 1920)
	{
		game->rays[i].angle = 30.0 - (double)(game->d_anglee * (double)i);
		game->rays[i].x = game->player.x;
		game->rays[i].y = game->player.y;
		game->rays[i].flag = 0;
		i++;
	}
}

void	floor_ceil(t_game *game, int i, int j)
{
	while (i < 1920)
	{
		while (j < 540)
		{
			my_mlx_pixel_put(&game->data, i, j, game->color.ceil);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 541;
	while (i < 1920)
	{
		while (j < 1080)
		{
			my_mlx_pixel_put(&game->data, i, j, game->color.floor);
			j++;
		}
		j = 541;
		i++;
	}
}
