/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:40:27 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 15:59:10 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	back_step(t_game *game, int kyecode)
{
	if (kyecode == 13)
		back(game);
	else if (kyecode == 1)
		forward(game);
	else if (kyecode == 0)
		right(game);
	else if (kyecode == 2)
		left(game);
	return (1);
}

int	wall_collion(t_game *game, int keycode)
{
	if (game->map[(int)(game->player.y + 0.01)][(int)(game->player.x)] == '1')
		return (back_step(game, keycode));
	if (game->map[(int)(game->player.y - 0.01)][(int)(game->player.x)] == '1')
		return (back_step(game, keycode));
	if (game->map[(int)(game->player.y)][(int)(game->player.x + 0.01)] == '1')
		return (back_step(game, keycode));
	if (game->map[(int)(game->player.y)][(int)(game->player.x - 0.01)] == '1')
		return (back_step(game, keycode));
	return (0);
}
