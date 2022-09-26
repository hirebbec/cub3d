/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:01:43 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 18:14:07 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	mlx_mouse_hide();
	if (game->mouse.x > x)
	{
		left_turn(game);
		init_angels(game);
		ft_raycast(game, 0);
		game->mouse.x = x;
		return (0);
	}
	else if (game->mouse.x < x)
	{
		right_turn(game);
		init_angels(game);
		ft_raycast(game, 0);
		game->mouse.x = x;
		return (0);
	}
	mlx_mouse_move(game->win, 960, 540);
	game->mouse.x = 960;
	game->mouse.y = 540;
	return (0);
}
