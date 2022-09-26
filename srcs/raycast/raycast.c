/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:25:19 by hirebbec          #+#    #+#             */
/*   Updated: 2022/07/11 16:35:45 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	tmp(t_game *game, int i)
{
	if (game->camera.x <= game->player.x && game->camera.y >= game->player.y)
	{
		if (h_c_t(game->rays[i], game, &game->rays[i]) <= h_l_t(game->rays[i], \
		game, &game->rays[i]))
			game->rays[i].len = h_c_t(game->rays[i], game, &game->rays[i]);
		else
			game->rays[i].len = h_l_t(game->rays[i], game, &game->rays[i]);
	}
	else if (game->camera.x >= game->player.x && game->camera.y \
	>= game->player.y)
	{
		if (h_c_h(game->rays[i], game, &game->rays[i]) <= h_l_h(game->rays[i], \
		game, &game->rays[i]))
			game->rays[i].len = h_c_h(game->rays[i], game, &game->rays[i]);
		else
			game->rays[i].len = h_l_h(game->rays[i], game, &game->rays[i]);
	}
}

void	ft_raycast(t_game *game, int i)
{
	while (i < 1920)
	{
		if (game->camera.x <= game->player.x && game->camera.y \
		<= game->player.y)
		{
			if (h_c_s(game->rays[i], game, &game->rays[i]) <= \
			h_l_s(game->rays[i], game, &game->rays[i]))
				game->rays[i].len = h_c_s(game->rays[i], game, &game->rays[i]);
			else
				game->rays[i].len = h_l_s(game->rays[i], game, &game->rays[i]);
		}
		else if (game->camera.x >= game->player.x && game->camera.y \
		<= game->player.y)
		{
			if (h_c_f(game->rays[i], game, &game->rays[i]) <= \
			h_l_f(game->rays[i], game, &game->rays[i]))
				game->rays[i].len = h_c_f(game->rays[i], game, &game->rays[i]);
			else
				game->rays[i].len = h_l_f(game->rays[i], game, &game->rays[i]);
		}
		else
			tmp(game, i);
		i++;
	}
}

int	moves(int kyecode, t_game *game)
{
	if (kyecode == 123)
		left_turn(game);
	else if (kyecode == 124)
		right_turn(game);
	else if (kyecode == 13)
		forward(game);
	else if (kyecode == 1)
		back(game);
	else if (kyecode == 0)
		left(game);
	else if (kyecode == 2)
		right(game);
	else if (kyecode == 53)
		exit(0);
	if (!wall_collion(game, kyecode))
	{
		init_angels(game);
		ft_raycast(game, 0);
	}
	return (0);
}

void	raycast(t_game *game)
{
	game->data.img = mlx_new_image(game->mlx, 1920, 1080);
	game->data.addr = mlx_get_data_addr(game->data.img, \
	&game->data.bits_per_pixel, &game->data.line_length, &game->data.en);
	init_angels(game);
	ft_raycast(game, 0);
	mlx_hook(game->win, 2, 0, moves, game);
	mlx_hook(game->win, 6, 0, mouse_move, game);
	mlx_hook(game->win, 4, 0, gun_act, game);
	mlx_hook(game->win, 5, 0, gun_deact, game);
	mlx_loop_hook(game->mlx, update_screen, game);
	mlx_hook(game->win, 17, 0, ft_exit, game);
	mlx_loop(game->mlx);
}
