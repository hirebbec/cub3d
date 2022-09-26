/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:50:03 by hirebbec          #+#    #+#             */
/*   Updated: 2022/07/12 18:19:32 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	pic_name_error(void)
{
	ft_putendl_fd("Image file name error", 2);
	exit(1);
}

void	pic_name_checker(t_game *game)
{
	if (game->pic.ea_path[ft_strlen(game->pic.ea_path) - 1] != 'm' || \
	game->pic.ea_path[ft_strlen(game->pic.ea_path) - 2] != 'p' || \
	game->pic.ea_path[ft_strlen(game->pic.ea_path) - 3] != 'x' || \
	game->pic.ea_path[ft_strlen(game->pic.ea_path) - 4] != '.')
		pic_name_error();
	if (game->pic.we_path[ft_strlen(game->pic.we_path) - 1] != 'm' || \
	game->pic.we_path[ft_strlen(game->pic.we_path) - 2] != 'p' || \
	game->pic.we_path[ft_strlen(game->pic.we_path) - 3] != 'x' || \
	game->pic.we_path[ft_strlen(game->pic.we_path) - 4] != '.')
		pic_name_error();
	if (game->pic.no_path[ft_strlen(game->pic.no_path) - 1] != 'm' || \
	game->pic.no_path[ft_strlen(game->pic.no_path) - 2] != 'p' || \
	game->pic.no_path[ft_strlen(game->pic.no_path) - 3] != 'x' || \
	game->pic.no_path[ft_strlen(game->pic.no_path) - 4] != '.')
		pic_name_error();
	if (game->pic.so_path[ft_strlen(game->pic.so_path) - 1] != 'm' || \
	game->pic.so_path[ft_strlen(game->pic.so_path) - 2] != 'p' || \
	game->pic.so_path[ft_strlen(game->pic.so_path) - 3] != 'x' || \
	game->pic.so_path[ft_strlen(game->pic.so_path) - 4] != '.')
		pic_name_error();
}

void	extra_init(t_game *game)
{
	int	i;

	game->mouse.x = 960;
	game->mouse.y = 540;
	mlx_mouse_move(game->win, 960, 540);
	game->gun_img1 = mlx_xpm_file_to_image(game->mlx, \
	"./pictures/shotgun1.xpm", &i, &i);
	game->gun_img2 = mlx_xpm_file_to_image(game->mlx, \
	"./pictures/shotgun2.xpm", &i, &i);
	game->gun_img3 = mlx_xpm_file_to_image(game->mlx, \
	"./pictures/shotgun3.xpm", &i, &i);
	game->gun_img4 = mlx_xpm_file_to_image(game->mlx, \
	"./pictures/shotgun4.xpm", &i, &i);
	game->gun_img5 = mlx_xpm_file_to_image(game->mlx, \
	"./pictures/shotgun5.xpm", &i, &i);
	game->anim = 1;
	game->gun = 0;
	game->tmp = 0;
}

void	set_imgages(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "cub3d");
	game->pic.no.img = mlx_xpm_file_to_image(game->mlx, game->pic.no_path, \
	&game->pic.no.width, &game->pic.no.height);
	game->pic.no.pix = (int *)mlx_get_data_addr(game->pic.no.img, \
	&game->pic.no.bits_per_pixel, &game->pic.no.line_length, &game->pic.no.en);
	game->pic.so.img = mlx_xpm_file_to_image(game->mlx, game->pic.so_path, \
	&game->pic.so.width, &game->pic.so.height);
	game->pic.so.pix = (int *)mlx_get_data_addr(game->pic.so.img, \
	&game->pic.so.bits_per_pixel, &game->pic.so.line_length, &game->pic.so.en);
	game->pic.ea.img = mlx_xpm_file_to_image(game->mlx, game->pic.ea_path, \
	&game->pic.ea.width, &game->pic.ea.height);
	game->pic.ea.pix = (int *)mlx_get_data_addr(game->pic.ea.img, \
	&game->pic.ea.bits_per_pixel, &game->pic.ea.line_length, &game->pic.ea.en);
	game->pic.we.img = mlx_xpm_file_to_image(game->mlx, game->pic.we_path, \
	&game->pic.we.width, &game->pic.we.height);
	game->pic.we.pix = (int *)mlx_get_data_addr(game->pic.we.img, \
	&game->pic.we.bits_per_pixel, &game->pic.we.line_length, &game->pic.we.en);
	extra_init(game);
}
