/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:21:56 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 16:14:23 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	right_turn(t_game *game)
{
	if (game->camera.x <= game->player.x \
	&& game->camera.y <= game->player.y)
	{
		game->camera.x = game->camera.x + 0.003;
		game->camera.y = game->camera.y - 0.003;
	}
	else if (game->camera.x >= game->player.x \
	&& game->camera.y <= game->player.y)
	{
		game->camera.x = game->camera.x + 0.003;
		game->camera.y = game->camera.y + 0.003;
	}
	else if (game->camera.x <= game->player.x \
	&& game->camera.y >= game->player.y)
	{
		game->camera.x = game->camera.x - 0.003;
		game->camera.y = game->camera.y - 0.003;
	}
	else if (game->camera.x >= game->player.x \
	&& game->camera.y >= game->player.y)
	{
		game->camera.x = game->camera.x - 0.003;
		game->camera.y = game->camera.y + 0.003;
	}
}

void	left_turn(t_game *game)
{
	if (game->camera.x <= game->player.x \
	&& game->camera.y <= game->player.y)
	{
		game->camera.x = game->camera.x - 0.003;
		game->camera.y = game->camera.y + 0.003;
	}
	else if (game->camera.x >= game->player.x \
	&& game->camera.y <= game->player.y)
	{
		game->camera.x = game->camera.x - 0.003;
		game->camera.y = game->camera.y - 0.003;
	}
	else if (game->camera.x <= game->player.x \
	&& game->camera.y >= game->player.y)
	{
		game->camera.x = game->camera.x + 0.003;
		game->camera.y = game->camera.y + 0.003;
	}
	else if (game->camera.x >= game->player.x \
	&& game->camera.y >= game->player.y)
	{
		game->camera.x = game->camera.x + 0.003;
		game->camera.y = game->camera.y - 0.003;
	}
}

void	forward(t_game *game)
{
	double	d_x;
	double	d_y;

	d_x = game->camera.x - game->player.x;
	d_y = game->camera.y - game->player.y;
	game->camera.x = game->camera.x + d_x * 1.5;
	game->camera.y = game->camera.y + d_y * 1.5;
	game->player.x = game->player.x + d_x * 1.5;
	game->player.y = game->player.y + d_y * 1.5;
}

void	back(t_game *game)
{
	double	d_x;
	double	d_y;

	d_x = game->camera.x - game->player.x;
	d_y = game->camera.y - game->player.y;
	game->camera.x = game->camera.x - d_x * 1.5;
	game->camera.y = game->camera.y - d_y * 1.5;
	game->player.x = game->player.x - d_x * 1.5;
	game->player.y = game->player.y - d_y * 1.5;
}
