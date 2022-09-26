/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:42:12 by hirebbec          #+#    #+#             */
/*   Updated: 2022/06/29 18:11:50 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw(t_game *game)
{
	minimap_draw(game, 0, 0, 0);
	player_draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
	if (game->gun == 1)
	{
		if (game->anim < 3)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->gun_img1, 640, 720);
		else if (game->anim > 3 && game->anim < 6)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->gun_img2, 640, 720);
		else if (game->anim > 6 && game->anim < 9)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->gun_img3, 640, 720);
		else if (game->anim > 9 && game->anim < 12)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->gun_img4, 640, 720);
		else if (game->anim > 12 && game->anim < 15)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->gun_img5, 640, 720);
		if (game->anim > 15)
			game->anim = 0;
		game->anim++;
	}
}

void	so_no(t_game *game, int i, int j)
{
	int	x;
	int	y;

	if (game->rays[i].flag == NO)
	{
		x = (int)((game->rays[i].x_hit - floor(game->rays[i].x_hit)) * \
		game->pic.no.width);
		y = (int)((double) j / (1662.0 / game->rays[i].len) * \
		game->pic.no.height);
		my_mlx_pixel_put(&game->data, i, 540 - (1662.0 / game->rays[i].len) \
		/ 2 + j, game->pic.no.pix[y * game->pic.no.width + x]);
	}
	else
	{
		x = (int)((game->rays[i].x_hit - floor(game->rays[i].x_hit)) * \
		game->pic.so.width);
		y = (int)((double) j / (1662.0 / game->rays[i].len) * \
		game->pic.so.height);
		my_mlx_pixel_put(&game->data, i, 540 - (1662.0 / game->rays[i].len) \
		/ 2 + j, game->pic.so.pix[y * game->pic.so.width + x]);
	}
}

void	we_ea(t_game *game, int i, int j)
{
	int	x;
	int	y;

	if (game->rays[i].flag == WE)
	{
		x = (int)((game->rays[i].y_hit - floor(game->rays[i].y_hit)) * \
		game->pic.we.width);
		y = (int)((double) j / (1662.0 / game->rays[i].len) * \
		game->pic.we.height);
		my_mlx_pixel_put(&game->data, i, 540 - (1662.0 / game->rays[i].len) \
		/ 2 + j, game->pic.we.pix[y * game->pic.we.width + x]);
	}
	else
	{
		x = (int)((game->rays[i].y_hit - floor(game->rays[i].y_hit)) * \
		game->pic.ea.width);
		y = (int)((double) j / (1662.0 / game->rays[i].len) * \
		game->pic.ea.height);
		my_mlx_pixel_put(&game->data, i, 540 - (1662.0 / game->rays[i].len) \
		/ 2 + j, game->pic.ea.pix[y * game->pic.ea.width + x]);
	}
}

void	put_pixel(t_game *game, int i, int j)
{
	while ((double) j < 1662.0 / game->rays[i].len)
	{
		while (540 - (1662.0 / game->rays[i].len) / 2 + j < 0)
			j++;
		if (540 - (1662.0 / game->rays[i].len) / 2 + j > 1080)
			break ;
		if (game->rays[i].flag == SO || game->rays[i].flag == NO)
			so_no(game, i, j);
		else
			we_ea(game, i, j);
		j++;
	}
}

int	update_screen(t_game *game)
{
	int	i;

	i = 0;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->data.img);
	game->data.img = mlx_new_image(game->mlx, 1920, 1080);
	game->data.addr = mlx_get_data_addr(game->data.img, \
	&game->data.bits_per_pixel, &game->data.line_length, &game->data.en);
	floor_ceil(game, 0, 0);
	while (i < 1920)
	{
		put_pixel(game, i, 0);
		i++;
	}
	draw(game);
	return (0);
}
