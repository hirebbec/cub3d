/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WASD.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:51:39 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 16:16:15 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	right_tmp(t_game *game, double angle)
{
	if (game->camera.x <= game->player.x && game->camera.y \
	>= game->player.y)
	{
		game->camera.x = game->camera.x - fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y - fabs(cos(angle) * 0.1);
		game->player.x = game->player.x - fabs(sin(angle) * 0.1);
		game->player.y = game->player.y - fabs(cos(angle) * 0.1);
	}
	else if (game->camera.x >= game->player.x && game->camera.y \
	>= game->player.y)
	{
		game->camera.x = game->camera.x - fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y + fabs(cos(angle) * 0.1);
		game->player.x = game->player.x - fabs(sin(angle) * 0.1);
		game->player.y = game->player.y + fabs(cos(angle) * 0.1);
	}
}

void	left_tmp(t_game *game, double angle)
{
	if (game->camera.x <= game->player.x && game->camera.y \
	>= game->player.y)
	{
		game->camera.x = game->camera.x + fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y + fabs(cos(angle) * 0.1);
		game->player.x = game->player.x + fabs(sin(angle) * 0.1);
		game->player.y = game->player.y + fabs(cos(angle) * 0.1);
	}
	else if (game->camera.x >= game->player.x && game->camera.y \
	>= game->player.y)
	{
		game->camera.x = game->camera.x + fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y - fabs(cos(angle) * 0.1);
		game->player.x = game->player.x + fabs(sin(angle) * 0.1);
		game->player.y = game->player.y - fabs(cos(angle) * 0.1);
	}
}

void	right(t_game *game)
{
	double	angle;

	angle = atan(fabs(game->camera.y - game->player.y) / \
	fabs(game->camera.x - game->player.x));
	if (game->camera.x <= game->player.x && game->camera.y <= game->player.y)
	{
		game->camera.x = game->camera.x + fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y - fabs(cos(angle) * 0.1);
		game->player.x = game->player.x + fabs(sin(angle) * 0.1);
		game->player.y = game->player.y - fabs(cos(angle) * 0.1);
	}
	else if (game->camera.x >= game->player.x && game->camera.y \
	<= game->player.y)
	{
		game->camera.x = game->camera.x + fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y + fabs(cos(angle) * 0.1);
		game->player.x = game->player.x + fabs(sin(angle) * 0.1);
		game->player.y = game->player.y + fabs(cos(angle) * 0.1);
	}
	else
		right_tmp(game, angle);
}

void	left(t_game *game)
{
	double	angle;

	angle = atan(fabs(game->camera.y - game->player.y) / \
	fabs(game->camera.x - game->player.x));
	if (game->camera.x <= game->player.x && game->camera.y <= game->player.y)
	{
		game->camera.x = game->camera.x - fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y + fabs(cos(angle) * 0.1);
		game->player.x = game->player.x - fabs(sin(angle) * 0.1);
		game->player.y = game->player.y + fabs(cos(angle) * 0.1);
	}
	else if (game->camera.x >= game->player.x && game->camera.y \
	<= game->player.y)
	{
		game->camera.x = game->camera.x - fabs(sin(angle) * 0.1);
		game->camera.y = game->camera.y - fabs(cos(angle) * 0.1);
		game->player.x = game->player.x - fabs(sin(angle) * 0.1);
		game->player.y = game->player.y - fabs(cos(angle) * 0.1);
	}
	else
		left_tmp(game, angle);
}
