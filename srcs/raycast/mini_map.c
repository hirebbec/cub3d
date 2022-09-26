/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:08:46 by hirebbec          #+#    #+#             */
/*   Updated: 2022/07/04 20:24:59 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	player_draw(t_game *game)
{
	int	f;
	int	k;

	f = 0;
	k = 0;
	while (k < 2)
	{
		f = 0;
		while (f < 2)
		{
			my_mlx_pixel_put(&game->data, (int)(game->player.x * 10) + 30 + f, \
			(int)(game->player.y * 10) + 30 + k, 0xFF0000);
			f++;
		}
		k++;
	}
}

void	minimap_draw(t_game *game, int i, int j, int k)
{
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			k = 0;
			while (k < 10)
			{
				game->tmp = 0;
				while (game->tmp < 10)
				{
					if (game->map[i][j] == '1')
						my_mlx_pixel_put(&game->data, j * 10 + 30 + game->tmp, \
						i * 10 + 30 + k, 0x000000);
					else
						my_mlx_pixel_put(&game->data, j * 10 + 30 + game->tmp, \
						i * 10 + 30 + k, 0xFFFFFF);
					game->tmp++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

int	gun_act(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == 1)
		game->gun = 1;
	return (1);
}

int	gun_deact(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == 1)
		game->gun = 0;
	game->anim = 0;
	return (1);
}
